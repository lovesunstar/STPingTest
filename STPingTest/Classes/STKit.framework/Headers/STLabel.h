//
//  STLabel.h
//  STKit
//
//  Created by SunJiangting on 13-10-26.
//  Copyright (c) 2013年 SunJiangting. All rights reserved.
//

#import <STKit/STDefines.h>
#import <UIKit/UIKit.h>

typedef enum {
    STVerticalAlignmentTop,  // default
    STVerticalAlignmentMiddle,
    STVerticalAlignmentBottom,
} STVerticalAlignment;

/**
 * @abstract 为Label添加垂直对齐方式和内容间距
 */
@interface STLabel : UILabel
/// 垂直方向上的对其方式
@property(nonatomic, assign) STVerticalAlignment verticalAlignment;
/// 内容间距
@property(nonatomic, assign) UIEdgeInsets contentInsets;
@end