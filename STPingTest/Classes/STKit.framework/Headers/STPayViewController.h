//
//  STPayViewController.h
//  STKit
//
//  Created by SunJiangting on 14-9-3.
//  Copyright (c) 2014年 SunJiangting. All rights reserved.
//

#import <STKit/STKit.h>
#import "STPayManager.h"

@interface STPayViewController : STViewController

- (instancetype)initWithPayItem:(STPayItem *)payItem handler:(STPayHandler)payHandler;

@property(nonatomic, readonly) STPayPlatform payPlatforms;

@end
