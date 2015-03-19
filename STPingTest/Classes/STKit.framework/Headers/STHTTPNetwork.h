//
//  STHTTPNetwork.h
//  STKit
//
//  Created by SunJiangting on 13-11-25.
//  Copyright (c) 2013年 SunJiangting. All rights reserved.
//

#import <STKit/Foundation+STKit.h>
#import <Foundation/Foundation.h>
#import "STNetworkConfiguration.h"

typedef NS_ENUM(NSInteger, STHTTPNetworkErrorCode) {
    STHTTPNetworkErrorCodeUserCancelled     = 1,
    STHTTPNetworkErrorCodeCantLoadCache     = 10,
    /// 301跳转，永久重定向
    STHTTPNetworkErrorCodeMovedTemporarily  = 301,
    /// 302跳转，服务器redirect
    STHTTPNetworkErrorCodeMovedPermanently  = 302,
    STHTTPNetworkErrorCodeServerForbidden   = 403,
    STHTTPNetworkErrorCodePageNotFound      = 404,
    STHTTPNetworkErrorCodeMethodNotAllowed  = 405,
    STHTTPNetworkErrorCodeNotAcceptable     = 406,
    //    服务器遇到了一个未曾预料的状况，导致了它无法完成对请求的处理。一般来说，这个问题都会在服务器端的源代码出现错误时出现
    STHTTPNetworkErrorCodeInternetServerError = 500,
    STHTTPNetworkErrorCodeNotImplemented      = 501,
    STHTTPNetworkErrorCodeBadGateway          = 502,
    STHTTPNetworkErrorCodeServiceUnavailable  = 503,
    STHTTPNetworkErrorCodeGatewayTimeout      = 504,
    STHTTPNetworkErrorCodeHTTPVersionNotSupported = 505,
};

@class STHTTPOperation;
typedef void (^STHTTPNetworkHandler)(STHTTPOperation *operation, id response, NSError *error);
typedef void (^STHTTPSynchronousNetworkHandler)(NSURLResponse *response, id data, NSError *error);

/// HTTP类型的网络请求
@interface STHTTPNetwork : NSObject

+ (instancetype)defaultHTTPNetwork;
+ (NSURLCache *)defaultHTTPCache;

- (instancetype)initWithConfiguration:(STNetworkConfiguration *)configuration;
/// default mainQueue
@property(nonatomic, strong) dispatch_queue_t   callbackQueue;
@property(nonatomic, assign) NSInteger          maxConcurrentRequestCount;


- (void)sendHTTPOperation:(STHTTPOperation *)operation;

- (void)cancelHTTPOperation:(STHTTPOperation *)operation;

@end

@interface STHTTPNetwork (STHTTPConvenience)

- (void)sendHTTPOperation:(STHTTPOperation *)operation
        completionHandler:(STHTTPNetworkHandler)completionHandler;

- (STHTTPOperation *)sendRequestWithURLString:(NSString *)URLString
                                   parameters:(NSDictionary *)parameters
                            completionHandler:(STHTTPNetworkHandler)completionHandler;

@end


extern NSString *const STHTTPNetworkErrorDomain;
extern NSString *const STHTTPNetworkErrorDescriptionUserInfoKey;
