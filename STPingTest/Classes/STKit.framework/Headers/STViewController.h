//
//  STViewController.h
//  STKit
//
//  Created by SunJiangting on 13-10-5.
//  Copyright (c) 2013年 SunJiangting. All rights reserved.
//

#import <STKit/STDefines.h>
#import <UIKit/UIKit.h>

@class STSearchDisplayController;
@interface STViewController : UIViewController

@property(nonatomic, weak) UIView *keyboardView;

@property(nonatomic, assign, getter=isInteractivePopGestureEnabled) BOOL interactivePopGestureEnabled;
/// 以下两个方法为了兼容iOS7以下版本,所以申明这些方法
- (void)setEdgesForExtendedLayout:(NSInteger)edgesForExtendedLayout;
- (NSUInteger)edgesForExtendedLayout;

- (void)setExtendedLayoutIncludesOpaqueBars:(BOOL)extendedLayoutIncludesOpaqueBars;
- (BOOL)extendedLayoutIncludesOpaqueBars;

- (void)setAutomaticallyAdjustsScrollViewInsets:(BOOL)automaticallyAdjustsScrollViewInsets;
- (BOOL)automaticallyAdjustsScrollViewInsets;

- (void)backViewControllerAnimated:(BOOL)animated;

- (void)setNavigationBarHidden:(BOOL)hidden animated:(BOOL)animated;
/// animations 隐藏的同时，伴随动画,不应该包含设置navframe的动画
- (void)setNavigationBarHidden:(BOOL)hidden animations:(void (^)(void))animations;

/// default is nil
@property(nonatomic, strong) STSearchDisplayController *customSearchDisplayController;

@property (nonatomic) UIStatusBarStyle  statusBarStyle;

@end

#import <STKit/STNavigationController.h>
#import <STKit/STTabBarController.h>