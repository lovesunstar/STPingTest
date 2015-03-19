//
//  STAESCryptor.h
//  STKit
//
//  Created by SunJiangting on 14-9-19.
//  Copyright (c) 2014年 SunJiangting. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CommonCrypto/CommonCryptor.h>

typedef NS_OPTIONS(NSInteger, STAESCryptorOptions){
    STAESCryptorOptionsKeySize128   = 1 << 0, // default
    STAESCryptorOptionsKeySize192   = 1 << 1,
    STAESCryptorOptionsKeySize256   = 1 << 2,

    /// 如果需要加密的数据 不是整Key对应的size的整数倍，补全方式
    STAESCryptorOptionsNoPadding    = 1 << 8,
    STAESCryptorOptionsZerosPadding = 1 << 9, // 补0
    STAESCryptorOptionsPKCS5Padding = 1 << 10,
    STAESCryptorOptionsPKCS7Padding = STAESCryptorOptionsPKCS5Padding, // default

    // 加密模式
    STAESCryptorOptionsCBCMode      = 1 << 15, // default
    STAESCryptorOptionsECBMode      = 1 << 16,
};

@interface STAESCryptor : NSObject

/**
 * @abstract
 * @param key 密钥
 * @param options  default STAESCryptorOptionsKeySize128 | STAESCryptorOptionsPKCS7Padding | STAESCryptorOptionsCBCMode
 * @param iv       初始向量，默认为空，ECB模式下，这个参数无用
 */
- (instancetype)initWithKey:(NSString *)key;

- (instancetype)initWithKey:(NSString *)key options:(STAESCryptorOptions)options;

- (instancetype)initWithKey:(NSString *)key options:(STAESCryptorOptions)options iv:(NSString *)iv;

@property(nonatomic, copy, readonly) NSString *key;
/// 初始向量, 默认为空。会根据 加密方式128,192,256 截取keysize。如果不足，则0填充
@property(nonatomic, copy, readonly) NSString *iv;

@property(nonatomic, readonly) STAESCryptorOptions options;

- (NSData *)encryptData:(NSData *)data;
- (NSData *)decryptData:(NSData *)data;

@end

@interface NSData (STAESCryptor)

/// default options  STAESCryptorOptionsPKCS7Padding | STAESCryptorOptionsCBCMode
- (NSData *)AES128EncryptedDataWithKey:(NSString *)key;
- (NSData *)AES192EncryptedDataWithKey:(NSString *)key;
- (NSData *)AES256EncryptedDataWithKey:(NSString *)key;

- (NSData *)decryptAES128DataWithKey:(NSString *)key;
- (NSData *)decryptAES192DataWithKey:(NSString *)key;
- (NSData *)decryptAES256DataWithKey:(NSString *)key;

- (NSData *)AESEncryptedDataWithKey:(NSString *)key options:(STAESCryptorOptions)options;
- (NSData *)decryptAESWithKey:(NSString *)key options:(STAESCryptorOptions)options;

@end
