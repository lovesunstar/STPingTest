//
//  STCollectionViewFlowLayout.h
//  STKit
//
//  Created by SunJiangting on 14-5-8.
//  Copyright (c) 2014年 SunJiangting. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol STCollectionViewFlowLayoutDelegate;
/**
 * @abstract 支持每行的高度不一致
 */
// UICollectionViewFlowLayout
@interface STCollectionViewFlowLayout : UICollectionViewLayout

@property(nonatomic, assign) NSUInteger numberOfColumns;

/// 行、列边距
@property(nonatomic) CGFloat minimumLineSpacing;
@property(nonatomic) CGFloat minimumInteritemSpacing;
@property(nonatomic) CGSize itemSize;
@property(nonatomic) UIEdgeInsets sectionInset;

/**
 *  @brief The calculated width of an item in the specified section.
 *  @discussion
 *    The width of an item is calculated based on number of columns, the collection view width, and the horizontal insets for that section.
 */
- (CGFloat)itemWidthInSectionAtIndex:(NSInteger)section;

@end

@protocol STCollectionViewFlowLayoutDelegate <UICollectionViewDelegateFlowLayout>

@end

@interface UICollectionView (STHeaderFooterView)

@property(nonatomic, strong) UIView *collectionHeaderView;
@property(nonatomic, strong) UIView *collectionFooterView;

@end