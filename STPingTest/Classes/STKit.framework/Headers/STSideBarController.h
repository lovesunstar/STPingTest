//
//  STSideBarController.h
//  STKit
//
//  Created by SunJiangting on 13-11-19.
//  Copyright (c) 2013年 SunJiangting. All rights reserved.
//

#import <STKit/STDefines.h>
#import <UIKit/UIKit.h>

#import "STViewController.h"

//// 侧滑生效的范围
/**
 * @abstract 侧滑导航在哪些区域通过左滑手势可以打开
 *
 * @attention 默认从最左端可以产生侧滑效果。
 */
typedef enum {
    STSideInteractiveAreaNone          = 0,// 无任何侧滑效果
    STSideInteractiveAreaNavigationBar = 1 << 0,// 导航条可以通过手势侧滑
    STSideInteractiveAreaContentView   = 1 << 1,// 中间区域可以通过手势侧滑
    STSideInteractiveAreaAll           = (STSideInteractiveAreaNavigationBar | STSideInteractiveAreaContentView)
} STSideInteractiveArea;

@interface STSideBarController : STViewController {
}

- (instancetype)initWithRootViewController:(UIViewController *)rootViewController;

/// sideBar 的最大宽度
@property (nonatomic) CGFloat maxSideWidth;
@property (nonatomic, copy)   NSArray *viewControllers;
- (void)setViewControllers:(NSArray *)sideViewControllers animated:(BOOL)animated;

/// 当前选中的ViewController
@property(nonatomic, readonly, weak) UIViewController *selectedViewController;
@property(nonatomic) NSUInteger       selectedIndex;
/// sidebar 是否在可见区域,当侧边栏出现时sideAppeared = YES
@property(nonatomic) BOOL sideAppeared;
/// 滑动手势
@property(nonatomic, strong, readonly) UIPanGestureRecognizer *panGestureRecognizer;

/**
 * @abstract 打开/关闭侧边栏,重复打开,则无效.
 *
 * @param    animated 是否需要动画
 */
- (void)revealSideViewControllerAnimated:(BOOL)animated;
- (void)concealSideViewControllerAnimated:(BOOL)animated;

@end

@interface UIViewController (SideBarController)

@property(nonatomic, readonly, assign) STSideBarController *sideBarController;
@property(nonatomic, assign) NSInteger sideInteractionArea;

//@property (nonatomic, assign) CGFloat   interactiveSideEdgeOffset;

- (UINavigationBar *)topNavigationBar;

@end
