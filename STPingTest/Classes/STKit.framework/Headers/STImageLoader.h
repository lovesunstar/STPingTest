//
//  STImageLoader.h
//  STKit
//
//  Created by SunJiangting on 13-10-29.
//  Copyright (c) 2013年 SunJiangting. All rights reserved.
//

#import <STKit/STDefines.h>
#import <STKit/Foundation+STKit.h>
#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

/**
 * @abstract 图片文件下载完成回调
 *
 * @param    image 下载完成之后的image
 * @param    error 文件下载失败的错误
 */
typedef void (^STImageLoaderHandler)(UIImage *image, NSString *URLString, BOOL usingCache, NSError *error);

/**
 * @abstract 图片下载完成度回调
 *
 * @param    completion 完成百分比
 */
typedef void (^STImageProgressHandler)(CGFloat completion);
/**
 * @abstract 图片下载顺序
 *
 * STImageDownloadOrderForward 遵循FIFO，先请求，优先下载
 * STImageDownloadOrderBackward 遵循LIFO, 后请求，先下载
 */
typedef NS_ENUM(NSInteger, STImageDownloadOrder) {
    STImageDownloadOrderForward,
    STImageDownloadOrderBackward,
};
/**
 * @abstract 图片下载器, 可以负责图片下载,下载进度回调等.
 *
 */
@interface STImageLoader : NSObject
/// 默认的图片下载器
+ (instancetype)imageLoader;
/// 图片下载queue
@property(nonatomic, strong, readonly) NSOperationQueue *downloadQueue;
/// 图片下载顺序
@property(nonatomic, assign) STImageDownloadOrder downloadOrder;

/**
 * @abstract 根据URLString 去下载图片,并且根据回调通知给调用方
 *
 * @param   URLString 图片的URL地址
 * @param   progressHandler 图片下载过程中,下载进度的回调.@see STImageProgressHandler
 * @param   finishedHandler 图片下载完成的回调,会返回图片/错误 @see STImageLoaderHandler
 */
/// 以下两个方法为去服务端下载图片。
- (NSInteger)loadImageWithURLString:(NSString *)URLString finishedHandler:(STImageLoaderHandler)finishedHandler;

- (NSInteger)loadImageWithURLString:(NSString *)URLString
               progressHandler:(STImageProgressHandler)progressHandler
               finishedHandler:(STImageLoaderHandler)finishedHandler;

- (void)cancelLoadImageWithURLString:(NSString *)URLString;

- (void)cancelLoadImageWithIdentifier:(NSInteger)identifier;
@end