//
//  STApplicationContext.h
//  STKit
//
//  Created by SunJiangting on 14-8-14.
//  Copyright (c) 2014年 SunJiangting. All rights reserved.
//

#import <UIKit/UIKit.h>

/**
 * @abstract 提供App运行时的一些状态
 *
 */
@interface STApplicationContext : NSObject

+ (STApplicationContext *)sharedContext;

@property(nonatomic, assign, readonly) NSString *name;
@property(nonatomic, assign, readonly) NSString *bundleIdentifier;
@property(nonatomic, assign, readonly) NSString *bundleVersion;

/// 目前存在的所有UIAlertView
@property(nonatomic, copy, readonly) NSArray *availableAlertViews;

/// 界面主window，默认去从appdelegate中读取，如果没有读取到则返回占屏幕面积最大的window
@property(nonatomic, assign, readonly) UIWindow *mainWindow;

/// 目前显示的最顶端的ViewController
@property(nonatomic, assign, readonly) UIViewController *topmostViewController;

- (BOOL)openURL:(NSURL *)URL;
- (BOOL)canOpenURL:(NSURL *)URL;

/// when openURL, the context will enumerate all URLs to find the appropriate class.
- (BOOL)registerClass:(Class)class forURLString:(NSString *)URLString;

@end
