//
//  STRefreshControl.h
//  STKit
//
//  Created by SunJiangting on 14-9-17.
//  Copyright (c) 2014年 SunJiangting. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <STKit/STControlDefines.h>

/// 刷新控件
@interface STRefreshControl : UIControl

/// 当scrollView.contentOffset 超过这个值时，会触发刷新事件
@property(nonatomic, assign) CGFloat threshold;

/// 是否正在刷新
@property(nonatomic, readonly, getter=isRefreshing) BOOL refreshing;

- (void)beginRefreshing;

- (void)endRefreshing;

/// 下拉刷新组件当前状态
@property(nonatomic, assign, readonly)
    STRefreshControlState refreshControlState;

/// these are callback functions, do not call this method directly, if you want
/// to custom your refreshcontrol, you should override them to fit different
/// state.
- (void)scrollViewDidChangeContentOffset:(CGPoint)contentOffset;
- (void)refreshControlWillChangedToState:(STRefreshControlState)refreshControlState;
- (void)refreshControlDidChangedToState:(STRefreshControlState)refreshControlState;

@property(nonatomic, assign) NSTimeInterval animationDuration;

@end

@interface STDefaultRefreshControl : STRefreshControl
// 内部的控件
@property(nonatomic, weak) UILabel      *refreshTimeLabel;
@property(nonatomic, weak) UILabel      *refreshStatusLabel;
@property(nonatomic, weak) UIImageView  *arrowImageView;

@property(nonatomic, weak) UIActivityIndicatorView *indicatorView;

@property(nonatomic, strong) NSDate *refreshTime;

- (void)setTitle:(NSString *)title forState:(STRefreshControlState)state;
- (NSString *)titleForState:(STRefreshControlState)state;

@end

extern CGSize const STRefreshControlSize;