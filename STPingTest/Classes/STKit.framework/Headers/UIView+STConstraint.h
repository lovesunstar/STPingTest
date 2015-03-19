//
//  UIView+STConstraint.h
//  STKit
//
//  Created by SunJiangting on 15-1-21.
//  Copyright (c) 2015年 SunJiangting. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIView (STConstraint)

- (NSArray *)constraintsWithFirstItem:(UIView *)firstItem;
- (NSArray *)constraintsWithFirstItem:(UIView *)firstItem
                       firstAttribute:(NSLayoutAttribute)attribute;

@end
