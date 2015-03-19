//
//  STPersistence.h
//  STKit
//
//  Created by SunJiangting on 13-12-8.
//  Copyright (c) 2013年 SunJiangting. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <STKit/Foundation+STKit.h>

typedef enum {
    STPersistenceDirectoryDocument,  // document 目录
    STPersistenceDirectoryLibiary,   // Libiary  目录
    STPersistenceDirectoryCache,     // Cache 目录
    STPersistenceDirectoryTemporary, // 临时目录
} STPersistenceDirectory;

extern NSString *STPersistDocumentDirectory();
extern NSString *STPersistLibiaryDirectory();
extern NSString *STPersistCacheDirectory();
extern NSString *STPersistTemporyDirectory();

@interface STPersistence : NSObject

+ (instancetype)standardPersistence;
+ (void)resetStandardPersistence;

+ (instancetype)persistenceNamed:(NSString *)name;
+ (void)resetPersistenceNamed:(NSString *)name;

- (instancetype)initWithDirectory:(STPersistenceDirectory)directory
                          subpath:(NSString *)subpath;

- (void)setValue:(id)value forKey:(NSString *)key;
- (id)valueForKey:(NSString *)key;

@end

@interface STPersistence (STPersistCreation)

+ (instancetype)documentPersistence;
+ (instancetype)libiaryPersistence;
+ (instancetype)tempoaryPersistence;
+ (instancetype)cachePersistence;

+ (instancetype)documentPersistenceWithSubpath:(NSString *)subpath;
+ (instancetype)libiaryPersistenceWithSubpath:(NSString *)subpath;
+ (instancetype)cachePersistenceWithSubpath:(NSString *)subpath;
+ (instancetype)tempoaryPersistenceWithSubpath:(NSString *)subpath;

@end