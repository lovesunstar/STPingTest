//
//  STImageScrollView.h
//  STKit
//
//  Created by SunJiangting on 13-12-25.
//  Copyright (c) 2013年 SunJiangting. All rights reserved.
//

#import <UIKit/UIKit.h>

@class STImageScrollView, STRoundProgressView;
@protocol STImageScrollViewDelegate <NSObject>

@optional
- (void)imageScrollViewDidTapped:(STImageScrollView *)imageScrollView;
@optional
- (void)imageScrollViewDidLongPressed:(STImageScrollView *)imageScrollView;

@end

@class STImageView;
@interface STImageScrollView : UIScrollView

@property(nonatomic, readonly, strong) UIImageView *imageView;
@property(nonatomic, assign) BOOL autoFitImageView;
@property(nonatomic, weak) id<STImageScrollViewDelegate> interactionDelegate;
@property(nonatomic, strong, readonly) STRoundProgressView *roundProgressView;

- (void)zoomToFit;
- (void)zoomToFitImage:(UIImage *)image;

- (void)setImage:(UIImage *)image animated:(BOOL)animated;
- (void)setImageURL:(NSString *)imageURL animated:(BOOL)animated;
@end
