//
//  STHTTPConfiguration.h
//  STKit
//
//  Created by SunJiangting on 15-2-6.
//  Copyright (c) 2015年 SunJiangting. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <STKit/STRSACryptor.h>

/// 如果有file，会强制使用mutilpart/form-data
/// 否则服务端不能接收数据,一般没有特殊需求就不要乱搞
typedef NS_ENUM(NSInteger, STHTTPRequestFormEnctype) {
    STHTTPRequestFormEnctypeURLEncoded,    /// Default
    STHTTPRequestFormEnctypeMultipartData, /// 如果有文件/图片,会使用此格式
    STHTTPRequestFormEnctypeTextPlain,     /// 慎用。如果你不知道什么意思,你就不要用这个,一般服务器都不支持。
};


/// default text/json
typedef NS_ENUM(NSInteger, STHTTPResponseDataType) {
    STHTTPResponseDataTypeTextHTML = 0, // 返回类型位HTML text/html
    STHTTPResponseDataTypeTextJSON = 1, // 返回类型位JSON text/json
    STHTTPResponseDataTypeTextXML  = 2  // 返回类型位XML  text/xml
};

typedef NS_OPTIONS(NSInteger, STXMLParseOptions){
    STXMLParseOptionsProcessNamespaces = 1 << 0,
    STXMLParseOptionsReportNamespacePrefixes = 1 << 1,
    STXMLParseOptionsResolveExternalEntities = 1 << 2,
};

typedef NS_ENUM(NSInteger, STCompressionOptions) {
    STCompressionOptionsNone             = 1 << 0,     // 不接受任何压缩
    STCompressionOptionsRequestAllowed   = 1 << 1,     // 请求时压缩request-body
    STCompressionOptionsResponseAccepted = 1 << 2      // 允许服务器传输压缩的数据
};


@interface STHTTPConfiguration : NSObject <NSCopying>

+ (instancetype)defaultConfiguration;

/// Expiration -1 means follow the protocol
@property(nonatomic, getter=supportCachePolicy) BOOL supportCachePolicy;

@property(nonatomic) NSURLRequestCachePolicy cachePolicy;

@property(nonatomic, copy)NSString    *HTTPMethod;

@property(nonatomic) STCompressionOptions   compressionOptions;
@property(nonatomic) NSStringEncoding dataEncoding;
// 是否自动解码
@property(nonatomic) BOOL             decodeResponseData;
// default text/json
@property(nonatomic) STHTTPResponseDataType dataType;
/// used when dataType is text/json
@property(nonatomic) NSJSONReadingOptions JSONReadingOptions;
/// used when dataType is text/xml
@property(nonatomic) STXMLParseOptions XMLParseOptions;
/// 元素内容的key.默认content
@property(nonatomic, copy) NSString *XMLElementContextKey;

/// 超时时间 default 60s
@property(nonatomic) NSTimeInterval timeoutInterval;
@property(nonatomic) STHTTPRequestFormEnctype enctype;

@end
