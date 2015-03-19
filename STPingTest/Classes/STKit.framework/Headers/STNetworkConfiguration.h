//
//  STNetworkConfiguration.h
//  STKit
//
//  Created by SunJiangting on 14-10-18.
//  Copyright (c) 2014年 SunJiangting. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <STKit/STRSACryptor.h>
#import "STHTTPConfiguration.h"

/// 以下内容仅有一项就可以了
@interface STCertificateItem : NSObject
/// cer 文件的路径 [NSData dataWithContentsOfFile:filePath]
@property(nonatomic, copy) NSString *filePath;
/// cer 文件base64编码之后的字符串
@property(nonatomic, copy) NSString *base64String;
/// cer 文件内容 data
@property(nonatomic, copy) NSData *data;

///
+ (instancetype)certificateItemWithFilePath:(NSString *)filePath;
+ (instancetype)certificateItemWithBase64String:(NSString *)base64String;
+ (instancetype)certificateItemWithData:(NSData *)data;

@end

typedef NS_ENUM(NSInteger, STSSLPinningMode) {
    STSSLPinningModeNone        = 1 << 0,
    STSSLPinningModePublicKey   = 1 << 1,   // 只验证public是否正确
    STSSLPinningModeCertificate = 1 << 2  // 验证Public是否正确，以及证书是否有效
};


@interface STNetworkConfiguration : NSObject <NSCopying>

+ (instancetype)sharedConfiguration;
/// 是否允许未经过验证的证书，默认允许。如果允许，则忽略SSLPinningMode。default yes
@property BOOL allowsAnyHTTPSCertificate;
/// 如果SSLMode 为publicKey，则需要指定publicKey或者指定certificates，实现会从certificates中读取到publickey，然后赋值给publicKey
@property STSSLPinningMode SSLPinningMode;
/// 如果你没有设置publicKeys，必要的时候(PinningMode==STSSLPinningModePublicKey)会从certificate中读取publicKey
@property(nonatomic, copy) NSArray *publicKeys;
/// 证书 目前只支持 cer格式。具体查看 @see STCertificateItem
@property(nonatomic, copy) NSArray /*<STCertificateItem>*/ *certificates;

@property(nonatomic, strong) NSURLCredential *HTTPBasicCredential;
@property(nonatomic, strong) NSURLCredential *clientCertificateCredential;

@property NSInteger  cacheDiskCapacity;

@property(nonatomic, strong) STHTTPConfiguration    *HTTPConfiguration;

@end
