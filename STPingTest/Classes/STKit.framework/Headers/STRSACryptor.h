//
//  STRSACryptor.h
//  STKit
//
//  Created by SunJiangting on 14-9-19.
//  Copyright (c) 2014年 SunJiangting. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <Security/Security.h>

/**
 * @abstract 根据格式，从Data中读取公钥/私钥
 *
 * @param data      密钥的data
 * @param base64String 密钥经过base64编码之后的数据
 * @return 密钥(autorelease)
 */
extern SecKeyRef STSecPublicKeyFromDERData(NSData *data);
extern SecKeyRef STSecPublicKeyFromDERBase64String(NSString *base64String);

extern SecKeyRef STSecPublicKeyFromPEMData(NSData *data);
extern SecKeyRef STSecPublicKeyFromPEMBase64String(NSString *base64String);

extern SecKeyRef STSecPrivateKeyFromPEMData(NSData *data);
extern SecKeyRef STSecPrivateKeyFromPEMBase64String(NSString *base64String);

/// 目前只支持有密码的P12文件读取，如果没有密码的，iOS库本身不支持
extern SecKeyRef STSecPrivateKeyFromP12Data(NSData *data, NSString *password);

/// 比较两个key是否相同
extern BOOL STSecKeyEqualToSecKey(SecKeyRef key1, SecKeyRef key2);

@interface STRSACryptor : NSObject

- (instancetype)initWithPublicSecKey:(SecKeyRef)publicSecKey privateSecKey:(SecKeyRef)privateSecKey;

@property(nonatomic, readonly) NSInteger padding;

/**
 * @abstract 使用私钥对data进行签名
 *
 * @param   data 需要签名的数据
 * @return  返回签名后的数据
 */
- (NSData *)signData:(NSData *)data;

/**
 * @abstract 使用公钥验证签名是否有效
 *
 * @param   signature  使用私钥签名之后的数据
 * @param   signedData 原始 未被签名的数据
 * @return  是否验证通过
 */
- (BOOL)verifySignature:(NSData *)signature signedData:(NSData *)signedData;

/// 使用公钥加密/私钥解密 data : 需要加/解密的数据
- (NSData *)encryptData:(NSData *)data;
- (NSData *)decryptData:(NSData *)data;

@end
extern NSString *const STSecAttrApplicationTag;
