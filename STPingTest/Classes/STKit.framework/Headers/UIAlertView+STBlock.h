//
//  UIAlertView+STBlock.h
//  STKit
//
//  Created by SunJiangting on 14-10-31.
//  Copyright (c) 2014年 SunJiangting. All rights reserved.
//

#import <UIKit/UIKit.h>


typedef void (^STAlertViewDismissBlock)(UIAlertView *alertView, NSUInteger dismissIndex);

@interface UIAlertView (STBlock)

- (void)showWithDismissBlock:(STAlertViewDismissBlock)block;

@end
