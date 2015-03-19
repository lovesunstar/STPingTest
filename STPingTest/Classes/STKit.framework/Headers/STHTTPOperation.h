//
//  STHTTPOperation.h
//  STKit
//
//  Created by SunJiangting on 15-2-4.
//  Copyright (c) 2015年 SunJiangting. All rights reserved.
//

#import "STHTTPRequest.h"
#import "STNetworkConfiguration.h"
#import <CoreGraphics/CoreGraphics.h>

@class STHTTPOperation;

/// 即将开始网络请求，可以配置一些参数（cookies，headerfields等等）
typedef void (^STHTTPWillStartHandler)(STHTTPOperation *operation);


// 请求时时相应，下载资源等
/**
 * @abstract
 *网络请求时，服务器应答的回调，服务器有时候可能不是一次接受到所有数据，所以会分几次接受
 *
 * @param    data 服务端返回的数据
 * @param    completion 完成度，完成的百分比
 */
typedef void (^STHTTPRequestProgressHandler)(STHTTPOperation *operation, CGFloat completionPercent);

/**
 * @abstract 网络请求结束的回调
 *
 * @param response 包含网络返回的数据
 */
typedef void (^STHTTPResponseHandler)(STHTTPOperation *operation, id response);

// 请求时时相应，下载资源等
/**
 * @abstract
 *网络请求时，服务器应答的回调，服务器有时候可能不是一次接受到所有数据，所以会分几次接受
 *
 * @param    data 服务端返回的数据
 * @param    completion 完成度，完成的百分比
 */
typedef void (^STHTTPProgressHandler)(STHTTPOperation *operation, NSData *data, CGFloat completionPercent);

typedef void (^STHTTPFinishedHandler)(STHTTPOperation *operation, NSData *data, NSError *error);


@class STHTTPNetwork;
@interface STHTTPOperation : NSOperation {
 @private
    STHTTPNetwork *_networkDelegate;
}
/// 所有的网络请求都在这个线程发送
+ (NSThread *)standardNetworkThread;

- (instancetype)initWithHTTPRequest:(STHTTPRequest *)request;

@property(atomic, readonly) NSInteger identifier;

@property(nonatomic, strong) STNetworkConfiguration      *configuration;
@property(nonatomic, strong, readonly) STHTTPRequest     *request;
@property(nonatomic, strong, readonly) NSHTTPURLResponse *HTTPResponse;
@property(nonatomic, copy, readonly)   NSData            *responseData;
@property(nonatomic, readonly) NSInteger                  HTTPStatusCode;
@property (nonatomic, getter=isSynchronous) BOOL          synchronous; // Return only a single result, blocking until available (or failure). Defaults to NO

@property(nonatomic, strong) STHTTPWillStartHandler willStartHandler;
/// 请求过程回调
@property(nonatomic, strong) STHTTPRequestProgressHandler  requestProgressHandler;
/// 收到请求应答回调
@property(nonatomic, strong) STHTTPResponseHandler  responseHandler;
/// 当Response比较大时，比如图片，音频，文件等会分批次接受，该回调为每次接收到的%比。参考Content-Length
@property(nonatomic, strong) STHTTPProgressHandler  progressHandler;
/// 请求结束时的回调
@property(nonatomic, strong) STHTTPFinishedHandler  finishedHandler;

@end

@interface STHTTPOperation (STHTTPRequest)

+ (instancetype)operationWithURLString:(NSString *)URLString parameters:(NSDictionary *)parameters;
+ (instancetype)operationWithURLString:(NSString *)URLString HTTPMethod:(NSString *)method parameters:(NSDictionary *)parameters;


/*!
 @method setAllHTTPHeaderFields:
 @abstract Sets the HTTP header fields of the receiver to the given
 dictionary.
 @discussion This method replaces all header fields that may have
 existed before this method call.
 <p>Since HTTP header fields must be string values, each object and
 key in the dictionary passed to this method must answer YES when
 sent an <tt>-isKindOfClass:[NSString class]</tt> message. If either
 the key or value for a key-value pair answers NO when sent this
 message, the key-value pair is skipped.
 @param headerFields a dictionary containing HTTP header fields.
 */
- (void)setAllHTTPHeaderFields:(NSDictionary *)headerFields;

/*!
 @method setValue:forHTTPHeaderField:
 @abstract Sets the value of the given HTTP header field.
 @discussion If a value was previously set for the given header
 field, that value is replaced with the given value. Note that, in
 keeping with the HTTP RFC, HTTP header field names are
 case-insensitive.
 @param value the header field value.
 @param field the header field name (case-insensitive).
 */
- (void)setValue:(NSString *)value forHTTPHeaderField:(NSString *)field;

/*!
 @method addValue:forHTTPHeaderField:
 @abstract Adds an HTTP header field in the current header
 dictionary.
 @discussion This method provides a way to add values to header
 fields incrementally. If a value was previously set for the given
 header field, the given value is appended to the previously-existing
 value. The appropriate field delimiter, a comma in the case of HTTP,
 is added by the implementation, and should not be added to the given
 value by the caller. Note that, in keeping with the HTTP RFC, HTTP
 header field names are case-insensitive.
 @param value the header field value.
 @param field the header field name (case-insensitive).
 */
- (void)addValue:(NSString *)value forHTTPHeaderField:(NSString *)field;

- (void)setParameter:(id <NSCopying>)parameter forField:(NSString *)field;
- (void)addParameter:(id <NSCopying>)parameter forField:(NSString *)field;

- (void)setHTTPConfiguration:(STHTTPConfiguration *)configuration;
- (STHTTPConfiguration *)HTTPConfiguration;

@end

const NSInteger STNetworkErrorCodeUserCancelled;