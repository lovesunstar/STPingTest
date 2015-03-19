//
//  STPayManager.h
//  STKit
//
//  Created by SunJiangting on 14-9-3.
//  Copyright (c) 2014年 SunJiangting. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

typedef NS_ENUM(NSInteger, STPayResult) {
    STPayResultSuccess,
    STPayResultCancelled,
    STPayResultError,
};

typedef NS_OPTIONS(NSUInteger, STPayPlatform){
    STPayPlatformAliPay = 1 << 0, STPayPlatformWXPay = 1 << 1,

    STPayPlatformAll = (STPayPlatformAliPay | STPayPlatformWXPay),
};

@class STPayManager, STPayItem;

typedef void (^STPayHandler)(STPayItem *payItem, STPayResult result, NSError *error);

@interface STPayItem : NSObject

@property(nonatomic, copy) NSString *name;
@property(nonatomic, copy) NSString *title;
@property(nonatomic, assign) NSString *desc;
@property(nonatomic, assign) NSString *detail;

@property(nonatomic, assign) NSInteger count;
/// 精确到分
@property(nonatomic, assign) CGFloat price;
@property(nonatomic, assign) CGFloat amount;

/// 可选参数
@property(nonatomic, assign) STPayPlatform defaultPlatform;
@property(nonatomic, assign) STPayPlatform supportedPlatforms;

- (instancetype)initWithDictionary:(NSDictionary *)dictionary;
@end

/// 有关第三方付款
@interface STPayManager : NSObject

+ (instancetype)sharedPayManager;

- (BOOL)payForItem:(STPayItem *)payItem finishHandler:(STPayHandler)handler;
- (void)cancelPayForItem:(STPayItem *)payItem;

- (BOOL)canOpenURL:(NSURL *)URL;
- (BOOL)openURL:(NSURL *)url sourceApplication:(NSString *)sourceApplication annotation:(id)annotation;

@end
/// 支持的参数 stkit://pay?name=123&title=1234&detail=1234&price=4000&count=1&amount=4000&allowsEditing=1&platforms=3#1
extern BOOL STPayManagerOpenURL(NSURL *URL);
extern BOOL STPayManagerCanOpenURL(NSURL *URL);
