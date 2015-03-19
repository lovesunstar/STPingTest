//
//  STImage.h
//  STKit
//
//  Created by SunJiangting on 14-11-8.
//  Copyright (c) 2014年 SunJiangting. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface STImage : UIImage

@property (nonatomic, assign, readonly, getter=isGIFImage) BOOL  GIFImage;
@property (nonatomic, assign, readonly) NSInteger numberOfImages;

- (UIImage *) imageAtIndex:(NSInteger)index duration:(NSTimeInterval *)duration;

@end