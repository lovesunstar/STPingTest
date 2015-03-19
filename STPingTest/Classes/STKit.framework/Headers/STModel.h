//
//  STModel.h
//  STKit
//
//  Created by SunJiangting on 13-12-17.
//  Copyright (c) 2013年 SunJiangting. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "STHTTPOperation.h"

/**
 * 数据加载的来源，包括从本地Cache加载，下拉刷新，分页获取更多等
 */
typedef enum STModelDataSourceType {
    STModelDataSourceTypeCache,
    STModelDataSourceTypeRemote,
    STModelDataSourceTypePagination,
} STModelDataSourceType;

@class STModel;
@protocol STModelDelegate <NSObject>

- (void)modelWillStartLoadData:(STModel *)model;
- (void)modelDidFinishLoadData:(STModel *)model;
/// 当加载失败是，error不为nil。
- (void)modelDidFailedLoadData:(STModel *)model;
/// 如果正在加载更多，但是又触发了下拉刷新，则取消加载更多
- (void)modelDidCancelLoadData:(STModel *)model;
@optional
- (void)model:(STModel *)model didInsertItemAtIndexPaths:(NSArray *)indexPaths;
// if indexPaths == nil, preferred to reloadData
- (void)model:(STModel *)model didReloadItemAtIndexPaths:(NSArray *)indexPaths;

@end

@interface STModel : NSObject
/// 如果有更多，则展示 加载更多，否则，则为空
- (BOOL)hasNextPage;
@property(nonatomic, weak) id<STModelDelegate> delegate;
@property(nonatomic, assign) STModelDataSourceType sourceType;

@property(nonatomic, strong) NSError *error;
/// 注意。 当pagination的时候去操作下拉刷新，会取消当前的pagination操作。每一次加载更多，需要生成一个新的Operation
@property(nonatomic, weak) STHTTPOperation *paginationOperation;

/// 每次加载完毕后，会调用此方法，判断是否需要显示空数据
- (NSInteger)numberOfDataItems;
- (id)objectAtIndexPath:(NSIndexPath *)indexPath;
/// 从Cache加载
- (void)loadDataFromCache;

- (void)loadDataFromRemote;
- (void)loadDataFromPagination;

- (void)saveDataToCache;
/// 清除缓存
- (void)invalidateData;

/// when subclass finish network , must call these method
- (void)requestDidFinishWithObject:(id)object;
- (void)requestDidCancelWithObject:(id)object;
- (void)requestDidFailedWithObject:(id)object error:(NSError *)error;

@end
