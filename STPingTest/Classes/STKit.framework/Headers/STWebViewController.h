//
//  STWebViewController.h
//  STKit
//
//  Created by SunJiangting on 13-11-21.
//  Copyright (c) 2013年 SunJiangting. All rights reserved.
//

#import <STKit/STDefines.h>
#import <STKit/STViewController.h>

/**
 * @abstract 此ViewController为加载WebView的Controller。一般用于 关于等页面，内提供基本的前进，后退，刷新等网页功能
 */
@interface STWebViewController : STViewController

/// UIWebView。
@property(nonatomic, readonly, strong) UIWebView *webView;
/// 底部导航栏是否hidden，包含网页的前进，后退，刷新等按钮。
@property(nonatomic, assign) BOOL webViewBarHidden;
- (void)setWebViewBarHidden:(BOOL)webViewBarHidden animated:(BOOL)animated;

/// 加载是是否需要菊花
@property(nonatomic, assign) BOOL showIndicatorWhenLoading;

/// designed initializer
- (instancetype)initWithURL:(NSURL *)URL;
- (instancetype)initWithURLString:(NSString *)URLString;

@end


@interface STWebViewController (STLocalFile)

- (instancetype)initWithContentsOfFile:(NSString *)path;

@end