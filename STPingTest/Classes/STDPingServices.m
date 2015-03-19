//
//  STDPingServices.m
//  STKitDemo
//
//  Created by SunJiangting on 15-3-9.
//  Copyright (c) 2015年 SunJiangting. All rights reserved.
//

#import "STDPingServices.h"

@implementation STDPingItem

- (NSString *)description {
    if (self.status == STDPingStatusDidStart) {
        return [NSString stringWithFormat:@"PING %@ (%@): %ld data bytes",self.originalAddress, self.IPAddress, (long)self.dateBytesLength];
    }
    if (self.status == STDPingStatusDidTimeout) {
        return [NSString stringWithFormat:@"Request timeout for icmp_seq %ld", (long)self.ICMPSequence];
    }
    if (self.status == STDPingStatusDidReceivePacket) {
        return [NSString stringWithFormat:@"%ld bytes from %@: icmp_seq=%ld ttl=%ld time=%.3f ms", (long)self.dateBytesLength, self.IPAddress, (long)self.ICMPSequence, (long)self.timeToLive, self.timeMilliseconds];
    }
    return super.description;
}

+ (NSString *)statisticsWithPingItems:(NSArray *)pingItems {
    //    --- baidu.com ping statistics ---
    //    5 packets transmitted, 5 packets received, 0.0% packet loss
    //    round-trip min/avg/max/stddev = 4.445/9.496/12.210/2.832 ms
    NSString *address = [pingItems.firstObject originalAddress];
    NSMutableString *description = [NSMutableString stringWithCapacity:50];
    [description appendFormat:@"--- %@ ping statistics ---\n", address];
    __block NSInteger receivedCount = 0;
    [pingItems enumerateObjectsUsingBlock:^(STDPingItem *obj, NSUInteger idx, BOOL *stop) {
        if (obj.status == STDPingStatusDidReceivePacket) {
            receivedCount ++;
        }
    }];
    NSInteger allCount = pingItems.count;
    CGFloat lossPercent = (CGFloat)(allCount - receivedCount) / MAX(1.0, allCount) * 100;
    [description appendFormat:@"%ld packets transmitted, %ld packet received, %.1f%% packet loss\n", (long)allCount, (long)receivedCount, lossPercent];
    return [description stringByReplacingOccurrencesOfString:@".0%" withString:@"%"];
}
@end

@interface STDPingServices () <SimplePingDelegate> {
    BOOL _hasStarted;
    BOOL _isTimeout;
    NSInteger   _repingTimes;
    NSInteger   _icmpSequence;
    NSMutableArray *_pingItems;
}

@property(nonatomic, copy)   NSString   *address;
@property(nonatomic, strong) SimplePing *simplePing;

@property(nonatomic, strong)void(^callbackHandler)(STDPingItem *item, NSArray *pingItems);

@end

@implementation STDPingServices

+ (STDPingServices *)startPingAddress:(NSString *)address
                      callbackHandler:(void(^)(STDPingItem *item, NSArray *pingItems))handler {
    STDPingServices *services = [[STDPingServices alloc] initWithAddress:address];
    services.callbackHandler = handler;
    [services startPing];
    return services;
}

- (instancetype)initWithAddress:(NSString *)address {
    self = [super init];
    if (self) {
        self.timeoutMilliseconds = 500;
        self.address = address;
        self.simplePing = [SimplePing simplePingWithHostName:address];
        self.simplePing.delegate = self;
        self.maximumPingTimes = 100;
        _icmpSequence = 1;
        _pingItems = [NSMutableArray arrayWithCapacity:10];
    }
    return self;
}

- (void)startPing {
    _icmpSequence = 1;
    _repingTimes = 0;
    _hasStarted = NO;
    [_pingItems removeAllObjects];
    [self.simplePing start];
}

- (void)reping {
    [self.simplePing stop];
    [self.simplePing start];
}

- (void)_timeoutActionFired {
    STDPingItem *pingItem = [[STDPingItem alloc] init];
    pingItem.ICMPSequence = _icmpSequence;
    pingItem.originalAddress = self.address;
    pingItem.status = STDPingStatusDidTimeout;
    [self _handlePingItem:pingItem];
}

- (void)_handlePingItem:(STDPingItem *)pingItem {
    if (pingItem.status == STDPingStatusDidReceivePacket || pingItem.status == STDPingStatusDidTimeout) {
        [_pingItems addObject:pingItem];
    }
    if (_repingTimes < self.maximumPingTimes - 1) {
        if (self.callbackHandler) {
            self.callbackHandler(pingItem, [_pingItems copy]);
        }
        _repingTimes ++;
        _icmpSequence ++;
        NSTimer *timer = [NSTimer timerWithTimeInterval:1.0 target:self selector:@selector(reping) userInfo:nil repeats:NO];
        [[NSRunLoop currentRunLoop] addTimer:timer forMode:NSRunLoopCommonModes];
    } else {
        if (self.callbackHandler) {
            self.callbackHandler(pingItem, [_pingItems copy]);
        }
        [self cancel];
    }
}

- (void)cancel {
    [self.simplePing stop];
    STDPingItem *pingItem = [[STDPingItem alloc] init];
    pingItem.status = STDPingStatusFinished;
    if (self.callbackHandler) {
        self.callbackHandler(pingItem, [_pingItems copy]);
    }
    [[self class] cancelPreviousPerformRequestsWithTarget:self selector:@selector(_timeoutActionFired) object:nil];
}

- (void)simplePing:(SimplePing *)pinger didStartWithAddress:(NSData *)address {
    [pinger sendPingWithData:nil];
    [self performSelector:@selector(_timeoutActionFired) withObject:nil afterDelay:self.timeoutMilliseconds / 1000.0];
}
// If this is called, the SimplePing object has failed.  By the time this callback is
// called, the object has stopped (that is, you don't need to call -stop yourself).

// IMPORTANT: On the send side the packet does not include an IP header.
// On the receive side, it does.  In that case, use +[SimplePing icmpInPacket:]
// to find the ICMP header within the packet.

- (void)simplePing:(SimplePing *)pinger didSendPacket:(NSData *)packet ICMPHeader:(ICMPHeader *)_ICMPHeader {
    
    STDPingItem *pingItem = [[STDPingItem alloc] init];
    pingItem.IPAddress = pinger.IPAddress;
    pingItem.originalAddress = self.address;
    pingItem.dateBytesLength = packet.length - sizeof(ICMPHeader);
    pingItem.status = STDPingStatusDidStart;
    if (self.callbackHandler && !_hasStarted) {
        self.callbackHandler(pingItem, nil);
        _hasStarted = YES;
    }
}

// Called whenever the SimplePing object tries and fails to send a ping packet.
- (void)simplePing:(SimplePing *)pinger didReceivePingResponsePacket:(NSData *)packet timeElasped:(NSTimeInterval)timeElasped {
    [[self class] cancelPreviousPerformRequestsWithTarget:self selector:@selector(_timeoutActionFired) object:nil];
    const struct IPHeader * ipPtr = NULL;
    size_t                  ipHeaderLength = 0;
    if (packet.length >= (sizeof(IPHeader) + sizeof(ICMPHeader))) {
        ipPtr = (const IPHeader *) [packet bytes];
        ipHeaderLength = (ipPtr->versionAndHeaderLength & 0x0F) * sizeof(uint32_t);
    }
    NSInteger timeToLive = 0, dataBytesSize = 0;
    if (ipPtr != NULL) {
        dataBytesSize = packet.length - ipHeaderLength;
        timeToLive = ipPtr->timeToLive;
    }
    STDPingItem *pingItem = [[STDPingItem alloc] init];
    pingItem.IPAddress = pinger.IPAddress;
    pingItem.dateBytesLength = dataBytesSize;
    pingItem.timeToLive = timeToLive;
    pingItem.timeMilliseconds = timeElasped * 1000;
    pingItem.ICMPSequence = _icmpSequence;
    pingItem.originalAddress = self.address;
    pingItem.status = STDPingStatusDidReceivePacket;
    [self _handlePingItem:pingItem];
}
@end
