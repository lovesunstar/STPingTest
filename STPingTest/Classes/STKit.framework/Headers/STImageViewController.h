//
//  STImageViewController.h
//  STKit
//
//  Created by SunJiangting on 13-12-25.
//  Copyright (c) 2013年 SunJiangting. All rights reserved.
//

#import <STKit/STKit.h>

@class STImageViewController;
@protocol STImageViewControllerDelegate <NSObject>

@optional
- (void)imageViewController:(STImageViewController *)imageViewController didScrollToImageAtIndex:(NSInteger)imageIndex;
@end

@interface STImageViewController : STViewController

@property(nonatomic, weak) id<STImageViewControllerDelegate> delegate;

@property(nonatomic, assign) NSInteger selectedIndex;
/// 所有Image 数组
@property(nonatomic, copy) NSArray *imageDataSource;

@property(nonatomic, copy) NSString *navigationTitle;
/// 长按 是否存储到相册
@property(nonatomic, assign) BOOL saveImageToAlbumWhenLongPressed;

@end
// PS. 以下key为imageDataSource Key
/// 预览图片缩略图
extern NSString *const STImagePreviewThumbImageKey;
/// 预览图片缩略图 URL
extern NSString *const STImagePreviewThumbImageURLKey;
/// 预览图片大图
extern NSString *const STImagePreviewOriginalImageURLKey;