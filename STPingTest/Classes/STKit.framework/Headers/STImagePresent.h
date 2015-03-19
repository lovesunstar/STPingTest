//
//  STImagePresent.h
//  STKit
//
//  Created by SunJiangting on 14-9-21.
//  Copyright (c) 2014年 SunJiangting. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@protocol STImagePresentDelegate;
@interface STImagePresent : NSObject

/**
 * @abstract 展示imageView中的图片，查看大图。查看图片过程中，会使用动画从imageView所在的位置变换到大图界面。
 *
 * @param imageView 需要展示的imageView。
 */
+ (void)presentImageView:(UIImageView *)imageView;

+ (void)presentImageView:(UIImageView *)imageView hdImage:(UIImage *)hdImage;
+ (void)presentImageView:(UIImageView *)imageView hdImageURL:(NSString *)hdImageURL;

- (instancetype)initWithImages:(NSArray *)images;
@property(nonatomic, weak) id<STImagePresentDelegate> delegate;
- (void)presentImageAtIndex:(NSInteger)index animated:(BOOL)animated;
@property(nonatomic, readonly) NSInteger presentedIndex;
- (void)dismissAnimated:(BOOL)animated;
@end

@protocol STImagePresentDelegate <NSObject>
@optional
- (void)imagePresent:(STImagePresent *)imagePresent didPresentImageAtIndex:(NSInteger)index;

- (UIImageView *)imagePresent:(STImagePresent *)imagePresent imageViewForImageAtIndex:(NSInteger)index;

- (void)imagePresent:(STImagePresent *)imagePresent didLongPressImage:(UIImage *)image atIndex:(NSInteger)index;

@end
