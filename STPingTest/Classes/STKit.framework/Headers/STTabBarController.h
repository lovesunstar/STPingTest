//
//  STTabBarController.h
//  STKit
//
//  Created by SunJiangting on 14-2-13.
//  Copyright (c) 2014年 SunJiangting. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <STKit/STViewController.h>

@protocol STTabBarControllerDelegate;
@class STTabBar, STTabBarItem;

@interface STTabBarController : STViewController

@property(nonatomic, readonly, strong) UIView *transitionView;
@property(nonatomic) BOOL animatedWhenTransition;

@property(nonatomic, copy) NSArray *viewControllers;
// If the number of view controllers is greater than the number displayable by a tab bar, a "More" navigation controller will automatically be shown.
// The "More" navigation controller will not be returned by -viewControllers, but it may be returned by -selectedViewController.
- (void)setViewControllers:(NSArray *)viewControllers animated:(BOOL)animated;

@property(nonatomic, weak) UIViewController *selectedViewController;
@property(nonatomic) NSUInteger selectedIndex;

@property(nonatomic, readonly) STTabBar *
    tabBar; // Provided for -[UIActionSheet showFromTabBar:]. Attempting to modify the contents of the tab bar directly will throw an exception.

@property(nonatomic, weak) id<STTabBarControllerDelegate> delegate;

/// default 49
@property(nonatomic, assign) CGFloat tabBarHeight;
@property(nonatomic, assign) CGFloat actualTabBarHeight;

- (void)setBadgeValue:(NSString *)badgeValue forIndex:(NSInteger)index;
- (NSString *)badgeValueForIndex:(NSInteger)index;

//- (void)setTabBarHidden:(BOOL)hidden animated:(BOOL)animated;

@end

@interface UIViewController (STTabBarControllerItem)

@property(nonatomic, strong)
    STTabBarItem *customTabBarItem; // Automatically created lazily with the view controller's title if it's not set explicitly.

@property(nonatomic, readonly, strong)
    STTabBarController *customTabBarController; // If the view controller has a tab bar controller as its ancestor, return it. Returns nil otherwise.

@end

@protocol STTabBarControllerDelegate <NSObject>
@optional
- (BOOL)tabBarController:(STTabBarController *)tabBarController shouldSelectViewController:(UIViewController *)viewController;

- (void)tabBarController:(STTabBarController *)tabBarController didSelectViewController:(UIViewController *)viewController;

@end
/// Default 49
extern const CGFloat STCustomTabBarHeight;