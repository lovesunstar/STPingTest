//
//  STButton.h
//  STKit
//
//  Created by SunJiangting on 14-3-25.
//  Copyright (c) 2014年 SunJiangting. All rights reserved.
//

#import <UIKit/UIKit.h>

/// 1、提供选中和高亮背景色
/// 2、此Button上的所有Subview。当Button处于highlighted状态，subview同样处于highlighted状态
/// 3、此按钮为了避免系统按钮上的image和title无法设置frame问题，申明了ButtonImageView和buttonTitleLabel。
@interface STButton : UIButton

@property(nonatomic, assign) BOOL usingSystemLayout;

@property(nonatomic, strong) UIColor *highlightedBackgroundColor;
@property(nonatomic, strong) UIColor *selectedBackgroundColor;

@end

@interface STButton (STKit)

@property(nonatomic, assign) NSString *normalTitle;
@property(nonatomic, assign) NSString *highlightedTItle;

@end
