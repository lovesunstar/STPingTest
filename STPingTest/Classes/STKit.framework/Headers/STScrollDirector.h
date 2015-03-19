//
//  STScrollDirector.h
//  STKit
//
//  Created by SunJiangting on 14-5-10.
//  Copyright (c) 2014年 SunJiangting. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <STKit/STRefreshControl.h>
#import <STKit/STPaginationControl.h>

@interface STAccessoryView : UIView

@property(nonatomic, strong) UIImageView *imageView;

@property(nonatomic, strong) UILabel *textLabel;

@property(nonatomic, strong) UIButton *reloadButton;

@end

extern CGSize const STAccessoryViewMinimumSize;

/// 可以为scrollView添加下拉刷新和分页加载更多。
@interface STScrollDirector : NSObject
/// 主要提供set方法。。
@property(nonatomic, weak) UIScrollView *scrollView;

@property(nonatomic, strong) STRefreshControl *refreshControl;
@property(nonatomic, strong) STPaginationControl *paginationControl;

/// @see STRefreshControlState @see STPaginationControlState
- (void)setTitle:(NSString *)title forState:(STScrollDirectorState)state;
- (NSString *)titleForState:(NSInteger)state;

@end
