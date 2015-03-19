//
//  STTableView.h
//  STKit
//
//  Created by SunJiangting on 14-5-14.
//  Copyright (c) 2014年 SunJiangting. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface STTableView : UITableView
//// 该TableView是为了兼容iOS6.0以下
- (void)registerClass:(Class)cellClass forCellReuseIdentifier:(NSString *)identifier;
@end
