//
//  STHTTPRequest.h
//  STKit
//
//  Created by SunJiangting on 15-2-4.
//  Copyright (c) 2015年 SunJiangting. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "STHTTPConfiguration.h"

@interface STMultipartItem : NSObject

@property(nonatomic, copy) NSString *name;
/// 如果传送文件
@property(nonatomic, copy) NSString *path;
/// 发送图片或者data
@property(nonatomic, copy) NSData   *data;

@property(nonatomic, copy) NSString *MIMEType;

@end

@interface STHTTPRequest : NSObject

@property(nonatomic, copy)STHTTPConfiguration   *HTTPConfiguration;

- (instancetype)initWithURLString:(NSString *)URLString
                       HTTPMethod:(NSString *)HTTPMethod
                       parameters:(NSDictionary *)parameters;

+ (instancetype)requestWithURLString:(NSString *)URLString
                          HTTPMethod:(NSString *)HTTPMethod
                          parameters:(NSDictionary *)parameters;

@property(nonatomic, copy, readonly) NSURLRequest *URLRequest;

- (void)prepareToRequest;
@end

@interface STHTTPRequest (STHTTPHeader)

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

@end


@interface NSData (STGZip)

- (NSData *)st_compressDataUsingGZip;
+ (NSData *)st_dataWithZipCompressedData:(NSData *)data;

@end

