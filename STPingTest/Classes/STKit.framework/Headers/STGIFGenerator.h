//
//  STGIFGenerator.h
//  STKit
//
//  Created by SunJiangting on 14-11-8.
//  Copyright (c) 2014年 SunJiangting. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <ImageIO/ImageIO.h>

typedef NS_ENUM(NSInteger, STGIFPropertyColorModel) {
    STGIFPropertyColorModelRGB,
    STGIFPropertyColorModelGray,
    STGIFPropertyColorModelCMYK,
    STGIFPropertyColorModelLab
};

@interface STGIFProperty : NSObject
+ (STGIFProperty *)defaultGIFProperty;
/// default YES
@property (nonatomic, getter=hasGlobalColorMap) BOOL hasGlobalColorMap;
/// default STGIFPropertyColorModelRGB
@property (nonatomic) STGIFPropertyColorModel    colorModel;
/// default 8
@property (nonatomic) CGFloat   depth;
/// default 0
@property (nonatomic) NSInteger loopCount;

@end

@interface STGIFGenerator : NSObject

- (instancetype)initWithProperty:(STGIFProperty *)property;

@property (nonatomic, assign) CGSize    preferredImageSize;

- (void)appendImage:(UIImage *)image duration:(NSTimeInterval)duration;

- (void)startGeneratorWithPath:(NSString *)path completionHandler:(void(^)(NSString *))completionHandler;
- (void)cancel;

@end
