//
//  STTableViewController.h
//  STKit
//
//  Created by SunJiangting on 14-5-14.
//  Copyright (c) 2014年 SunJiangting. All rights reserved.
//

#import <STKit/STKit.h>
#import <STKit/STScrollDirector.h>
#import <STKit/STModelViewController.h>

@interface STTableViewController : STModelViewController <UITableViewDataSource, UITableViewDelegate>

@property(nonatomic, strong, readonly) UITableView *tableView;
/// addtarget to receive refresh callback
@property(nonatomic, weak, readonly) STRefreshControl *refreshControl;
@property(nonatomic, weak, readonly) STPaginationControl *paginationControl;
/// designed initializer
- (instancetype)initWithStyle:(UITableViewStyle)style;
//// 触发刷新方法
- (void)refreshData;
- (void)refreshDataUsingRefreshControl;

//// 当数据加载完成之后，会调用此方法，子类徐重写，刷新列表等
- (void)reloadData;

/// 当出现异常失败时，是否列表可以滚动
@property(nonatomic, assign) BOOL scrollableWhenExcepted;

@property(nonatomic, strong) STAccessoryView *dataZeroView;
@property(nonatomic, strong) STAccessoryView *dataExceptionView;
//// 指示器
@property(nonatomic, strong) STIndicatorView *indicatorView;

/// default return YES
- (BOOL)shouldDisplayDataZeroView:(UIView *)zeroView;
- (BOOL)shouldDisplayDataExceptionView:(UIView *)exceptionView error:(NSError *)error;

- (void)displayDataZeroView:(UIView *)zeroView;
- (void)displayDataExceptionView:(UIView *)exceptionView error:(NSError *)error;

@end
