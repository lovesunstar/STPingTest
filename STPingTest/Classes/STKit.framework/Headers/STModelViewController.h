//
//  STModelViewController.h
//  STKit
//
//  Created by SunJiangting on 13-12-17.
//  Copyright (c) 2013年 SunJiangting. All rights reserved.
//

#import <STKit/STViewController.h>
#import <STKit/STModel.h>

@interface STModelViewController : STViewController <STModelDelegate>
/// 返回Model的类名
+ (Class)modelClass;
@property(nonatomic, strong) STModel *model;

@end
