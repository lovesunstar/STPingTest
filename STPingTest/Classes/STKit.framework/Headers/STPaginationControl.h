//
//  STPaginationControl.h
//  STKit
//
//  Created by SunJiangting on 14-9-17.
//  Copyright (c) 2014年 SunJiangting. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <STKit/STControlDefines.h>

/// 分页空间，列表滑动到最底部时，请求加载下一页。加载更多
@interface STPaginationControl : UIControl
/// 距离底部多少开始触发分页操作
@property(nonatomic, assign) CGFloat threshold;
/// 是否正在加载更多
@property(nonatomic, readonly, getter=isLoading) BOOL loading;

@property(nonatomic, assign) STPaginationControlState paginationState;

- (void)paginationControlDidChangedToState:(STPaginationControlState)controlState;

@end

@interface STDefaultPaginationControl : STPaginationControl

@property(nonatomic, strong) UIButton *reloadButton;
@property(nonatomic, strong) UILabel *titleLabel;
@property(nonatomic, strong) UIActivityIndicatorView *indicatorView;

- (void)setTitle:(NSString *)title forState:(STPaginationControlState)state;
- (NSString *)titleForState:(STPaginationControlState)state;

@end

extern CGSize const STPaginationControlSize;