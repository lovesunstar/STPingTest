//
//  STImageCollectionView.h
//  STKit
//
//  Created by SunJiangting on 14-8-25.
//  Copyright (c) 2014年 SunJiangting. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <STKit/STObject.h>

@protocol STImageCollectionViewDelegate;
@class STImageScrollView;
@interface STImageCollectionView : UIView

- (instancetype)initWithFrame:(CGRect)frame images:(NSArray *)images;

@property(nonatomic, copy) NSArray *images;
- (void)setImages:(NSArray *)images animated:(BOOL)animated;

@property(nonatomic, assign) NSUInteger currentImageIndex; // default is 0. value pinned to 0..images.count-1
@property(nonatomic, weak) id<STImageCollectionViewDelegate> delegate;
@property(nonatomic, assign) CGFloat horizontalSpacing;
@property(nonatomic, strong, readonly) UICollectionView *collectionView;

@property(nonatomic, strong, readonly) STImageScrollView *imageScrollView;
@end

@protocol STImageCollectionViewDelegate <NSObject>
@optional
- (void)imageCollectionView:(STImageCollectionView *)collectionView didDisplayImageAtIndex:(NSInteger)index;
- (void)imageCollectionView:(STImageCollectionView *)collectionView didTapImageAtIndex:(NSInteger)index;

- (void)imageCollectionView:(STImageCollectionView *)collectionView didLongPressImage:(UIImage *)image atIndex:(NSInteger)index;
@end

@interface STImageItem : STObject

@property(nonatomic, strong) UIImage *thumb;
@property(nonatomic, copy) NSString *thumbURLString;

@property(nonatomic, strong) UIImage *image;
@property(nonatomic, copy) NSString *imageURLString;

@end