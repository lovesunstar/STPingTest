//
//  STRateControl.h
//  STKit
//
//  Created by SunJiangting on 14-9-18.
//  Copyright (c) 2014年 SunJiangting. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <STKit/STControlDefines.h>

/// 几颗星 打分组件
@interface STRateControl : UIControl
//- (instancetype) initWithStaredImage:(UIImage *) staredImage unstaredImage:(UIImage *) unstaredImage;
/// 填充满的星星
@property(nonatomic, strong) UIImage    *staredImage;
/// 未填充满的星星
@property(nonatomic, strong) UIImage    *unstaredImage;
/// 每个星星之间的间隔
@property(nonatomic, assign) CGFloat     verticalMargin;
/// 最多的value, 默认 5
@property(nonatomic, assign) CGFloat     maximumValue;
/// 当前value
@property(nonatomic, assign) CGFloat     value;
@end
