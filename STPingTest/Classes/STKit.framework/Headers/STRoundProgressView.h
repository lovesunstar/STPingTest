//
//  STRoundProgressView.h
//  STKit
//
//  Created by SunJiangting on 13-11-26.
//  Copyright (c) 2013年 SunJiangting. All rights reserved.
//

#import <STKit/STDefines.h>
#import <UIKit/UIKit.h>

/**
 * @abstract 环形的进度完成率，默认风格为iOS7 应用下载的风格.
 */
@interface STRoundProgressView : UIControl
/// 完成度
@property(nonatomic, assign) CGFloat completion;
- (void)setCompletion:(CGFloat)completion animated:(BOOL)animated;

@property(nonatomic, strong) UIColor *progressTintColor;

@end
