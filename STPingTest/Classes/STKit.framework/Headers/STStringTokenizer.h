//
//  STStringTokenizer.h
//  STKit
//
//  Created by SunJiangting on 14-5-12.
//  Copyright (c) 2014年 SunJiangting. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

/// <mark type=text name="name:systemFont" size="size:16" color="color:black" style="bold/itaic/plain:plain" underline="single:none"
/// strikethrough="single/thick:none">Text</mark>
/// :后面的为 default value.
/// to be continue
/// <mark type=image width=123 height=123 placeholder=123.png>123.png</mark>
@interface STStringTokenizer : NSObject

+ (NSAttributedString *)attributedStringWithMarkedString:(NSString *)markedText;
/// 分词
+ (NSDictionary *)dictionaryWithMarkedString:(NSString *)markedString;

@end

@interface UILabel (STStringTokenizer)

- (void)setMarkedText:(NSString *)markedText;

@end