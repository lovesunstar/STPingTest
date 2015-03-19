//
//  STTextView.h
//  STKit
//
//  Created by SunJiangting on 14-1-7.
//  Copyright (c) 2014年 SunJiangting. All rights reserved.
//

#import <UIKit/UIKit.h>

/// 提供了有placeHolder的文本输入框
@interface STTextView : UITextView

@property(nonatomic, strong) UIColor *placeholderColor;

@property(nonatomic, copy) NSString *placeholder;

@end
