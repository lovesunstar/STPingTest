//
//  UIImageView+STImageLoader.h
//  STKit
//
//  Created by SunJiangting on 13-11-26.
//  Copyright (c) 2013年 SunJiangting. All rights reserved.
//

#import <STKit/STDefines.h>
#import <UIKit/UIKit.h>

#import "STImageLoader.h"

typedef enum STImageState {
    STImageStateInitialized,
    STImageStateDownloading,
    STImageStateDownloadFinished,
    STImageStateDownloadFailed,
} STImageState;
/// 图片加载
@interface UIImageView (STImageLoader)

@property(nonatomic, readonly, getter=isFinished) BOOL finished;

@property(nonatomic, strong) UIImage *placeholderImage;

@property(nonatomic, assign, readonly) STImageState state;

- (void)setImageWithURLString:(NSString *)URLString;

- (void)setImageWithURLString:(NSString *)URLString finishedHandler:(STImageLoaderHandler)finishedHandler;

- (void)setImageWithURLString:(NSString *)URLString
              progressHandler:(STImageProgressHandler)progressHandler
              finishedHandler:(STImageLoaderHandler)finishedHandler;

- (void)cancelLoadImageWithURLString:(NSString *)URLString;

@end
