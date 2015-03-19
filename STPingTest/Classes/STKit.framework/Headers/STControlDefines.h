//
//  STControlDefines.h
//  STKit
//
//  Created by SunJiangting on 14-9-17.
//  Copyright (c) 2014年 SunJiangting. All rights reserved.
//

#ifndef STKit_STControlDefines_h
#define STKit_STControlDefines_h


/**
 * @abstract    刷新控件各个阶段的状态
 * @constant    STRefreshControlStateNormal           默认情况下的状态
 * @constant    STRefreshControlStateReachedThreshold 达到临界条件，即将触发刷新事件
 * @constant    STRefreshControlStateRefreshing       正在刷新
 */
typedef NS_ENUM(NSInteger, STRefreshControlState) {
    STRefreshControlStateNormal,
    STRefreshControlStateReachedThreshold,
    STRefreshControlStateLoading
};


/**
 * @abstract    分页控件的各个状态
 * @constant    STPaginationControlStateNormal     默认情况下的状态
 * @constant    STPaginationControlStateLoading    达到临界条件，即将触发加载下一页事件
 * @constant    STPaginationControlStateFailed     加载失败
 * @constant    STPaginationControlStateReachedEnd 没有加载到更多东西
 */
typedef NS_ENUM(NSInteger, STPaginationControlState) {
    STPaginationControlStateNormal,
    STPaginationControlStateLoading,
    STPaginationControlStateFailed,
    STPaginationControlStateReachedEnd,
};

typedef NS_ENUM (NSInteger, STScrollDirectorState) {
    STScrollDirectorStateRefreshNormal              = 1,
    STScrollDirectorStateRefreshReachedThreshold    = 2,
    STScrollDirectorStateRefreshLoading             = 3,
    
    STScrollDirectorStatePaginationNormal       = 11,
    STScrollDirectorStatePaginationLoading      = 12,
    STScrollDirectorStatePaginationFailed       = 13,
    STScrollDirectorStatePaginationReachedEnd   = 14,
};


#endif
