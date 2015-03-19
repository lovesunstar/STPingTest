//
//  STIndicatorView.h
//  STKit
//
//  Created by SunJiangting on 14-7-3.
//  Copyright (c) 2014年 SunJiangting. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <STKit/UIKit+STKit.h>

typedef enum STIndicatorType { STIndicatorTypeCustom, STIndicatorTypeWaiting, STIndicatorTypeText } STIndicatorType;

@class STIndicatorView;
@protocol STIndicatorViewDelegate <NSObject>
@optional
/**
 * @abstract 指示器被完全隐藏之后的回调, 一般会在hide之后动画结束了调用。参考minDisplayDuration
 *
 * @param    indicatorView 隐藏的指示器
 */
- (void)indicatorViewDidHidden:(STIndicatorView *)indicatorView;
@end

/**
 * @abstract 指示器。
 */
@interface STIndicatorView : UIView

/**
 * @abstract 显示指示器，指示器会被添加到view上,如果view = nil， 则添加到 keywindow上。
 *
 * @param    view 指示器需要显示的superview
 * @param    animated 是否需要动画
 */
+ (instancetype)showInView:(UIView *)view animated:(BOOL)animated;

/**
 * @abstract 关闭view上的所有指示器
 *
 * @param    view  需要关闭指示器的view
 * @param    animated 关闭的时候是否需要动画
 */
+ (BOOL)hideInView:(UIView *)view animated:(BOOL)animated;

/**
 * @abstract 该view上的指示器， 如果该view上没有指示器，则返回nil
 *
 * @param    view 有指示器的view。
 */
+ (instancetype)indicatorInView:(UIView *)view;
+ (NSArray *)allIndicatorInView:(UIView *)view;

/**
 * @abstract default initializer
 *
 * @param    view 该indicatorView会被添加到view上，如果view=nil，则为keywindow
 */
- (instancetype)initWithView:(UIView *)view;
/**
 * @abstract 显示/隐藏指示器。
 *
 * @param    animated 是否需要动画
 */
- (void)showAnimated:(BOOL)animated;
- (void)hideAnimated:(BOOL)animated;
/// 延时隐藏指示器
- (void)hideAnimated:(BOOL)animated afterDelay:(NSTimeInterval)delay;
- (void)hideAnimated:(BOOL)animated afterDelay:(NSTimeInterval)delay completion:(void (^)(void))completion;

@property(nonatomic, assign) STBlurEffectStyle blurEffectStyle;
/// 指示器弧度，默认 10
@property(nonatomic, assign) CGFloat cornerRadius;
/// 指示器间距，default 0 0
@property(nonatomic, assign) CGPoint contentOffset;
/// default 20
@property(nonatomic, assign) UIEdgeInsets contentInsets;
/// 指示器最小为多大，默认 0 0
@property(nonatomic, assign) CGSize minimumSize;
/// 您可以添加默认的customView. 当mode为STIndicatorTypeCustom时
@property(nonatomic, strong) UIView *customView;
@property(nonatomic, assign) id<STIndicatorViewDelegate> delegate;

@property(nonatomic, assign) STIndicatorType indicatorType;

@property(nonatomic, readonly, strong) UILabel *textLabel;
@property(nonatomic, readonly, strong) UILabel *detailLabel;
/// 是否强制为正方形。 默认NO
@property(nonatomic, assign, getter=isForceSquare) BOOL forceSquare;
/// 当指示器不显示的时候是否将指示器移除
@property(nonatomic, assign) BOOL removeWhenStopped;
@end
