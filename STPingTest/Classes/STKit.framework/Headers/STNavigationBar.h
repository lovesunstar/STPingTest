//
//  STNavigationBar.h
//  STKit
//
//  Created by SunJiangting on 14-2-18.
//  Copyright (c) 2014年 SunJiangting. All rights reserved.
//

#import <UIKit/UIKit.h>
// UINavigationBar
@interface STNavigationBar : UIView

@property(nonatomic, copy) NSString           *title;
@property(nonatomic, strong) UIView           *leftBarView;
@property(nonatomic, strong) UIView           *titleView;
@property(nonatomic, strong) UIView           *rightBarView;

@property(nonatomic, strong, readonly) UIView *transitionView;
@property(nonatomic, strong) UIImage          *backgroundImage;

@property(nonatomic, strong, readonly) UIView *separatorView;

@property(nonatomic, strong) UIColor          *barTintColor;

@property(nonatomic, copy) NSDictionary       *titleTextAttributes;
@end
