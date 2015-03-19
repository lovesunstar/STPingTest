//
//  STReachability.h
//  STKit
//
//  Created by SunJiangting on 13-12-7.
//  Copyright (c) 2013年 SunJiangting. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <SystemConfiguration/SCNetworkReachability.h>

typedef enum {
    STNetworkStatusReachNone, // 网络不通
    STNetworkStatusReachWIFI, // WIFI
    STNetworkStatusReachWWAN, // GPRS,E等
} STNetworkStatus;

/**
 * @abstract 此类可以获取网络的一些状况
 */
@interface STReachability : NSObject

/// 是否能够ping通host
+ (instancetype)reachabilityWithHost:(NSString *)host;

/// designed initializer
- (instancetype)initWithHost:(NSString *)host;

- (STNetworkStatus)reachabilityStatus;
- (SCNetworkReachabilityFlags)reachabilityFlags;

@end

@interface STReachability (STNotification)

/**
 * @abstract 开启/关闭网络状态改变的通知 @see
 *STReachabilityDidChangedNotification
 *
 * @discussion 该通知肯定在主线程发送。
 */
- (BOOL)startNotification;
- (void)stopNotification;

@end

@interface STReachability (STAccessor)

- (BOOL)reachable;
- (BOOL)reachWWAN;
- (BOOL)reachWIFI;

@end
extern NSString *const STReachabilityDidChangedNotification;