//
//  STTabBarItem.h
//  STKit
//
//  Created by SunJiangting on 14-2-13.
//  Copyright (c) 2014年 SunJiangting. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <STKit/STDefines.h>
#import <STKit/UIKit+STKit.h>

@interface STTabBarItem : NSObject

@property(nonatomic, copy) NSString *title;
@property(nonatomic, strong) UIImage *image;
@property(nonatomic, strong) UIImage *selectedImage;

@property(nonatomic, copy) NSString *badgeValue;

@property(nonatomic, assign) CGRect imageFrame;
@property(nonatomic, assign) CGRect titleFrame;

//- (CGRect) imageRectForBounds:(CGRect) bounds;
//- (CGRect) titleRectForBounds:(CGRect) bounds;

@property(nonatomic, weak) UIView *itemView;
/// UITabBarItem
- (instancetype)initWithTitle:(NSString *)title image:(UIImage *)image selectedImage:(UIImage *)selectedImage;

@end
