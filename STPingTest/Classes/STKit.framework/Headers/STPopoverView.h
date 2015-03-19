//
//  STPopoverView.h
//  STKit
//
//  Created by SunJiangting on 14-5-23.
//  Copyright (c) 2014年 SunJiangting. All rights reserved.
//

#import <UIKit/UIKit.h>

/// attention: 这个方向是表示朝向，比如Up就表示从下网上弹出。
typedef enum STPopoverViewDirection {

    STPopoverViewDirectionUp,
    STPopoverViewDirectionDown,

    STPopoverViewDirectionLeft,
    STPopoverViewDirectionRight,

} STPopoverViewDirection;

@protocol STPopoverViewDelegate;
@interface STPopoverView : UIView

/// all subview must be add to the contentView
@property(nonatomic, strong, readonly) UIView *contentView;
/// the contentoffset from it's parentView . see showInview can get the parentview
@property(nonatomic, assign) CGPoint contentOffset;
/// now visible
@property(nonatomic, assign, readonly) BOOL visible;
/// this direction is the direction how it's popfrom
@property(nonatomic, assign) STPopoverViewDirection direction;

- (void)showInView:(UIView *)view animated:(BOOL)animated;

/* Called to dismiss the popover programmatically. The delegate methods for "should" and "did" dismiss are not called when the popover is dismissed in
 * this way.
 */
- (void)dismissAnimated:(BOOL)animated;
/// background mask, default black alpha 0.5. the alpha will change when animated
@property(nonatomic, strong, readonly) UIView *backgroundView;

@property(nonatomic, weak) id<STPopoverViewDelegate> delegate;

@end

@protocol STPopoverViewDelegate <NSObject>
@optional
- (BOOL)popoverViewShouldDismiss:(STPopoverView *)popoverView;
- (void)popoverViewDidDismiss:(STPopoverView *)popoverView;

@end