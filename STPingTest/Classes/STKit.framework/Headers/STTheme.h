//
//  STTheme.h
//  STKit
//
//  Created by SunJiangting on 13-12-19.
//  Copyright (c) 2013年 SunJiangting. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface STTheme : NSObject <NSCoding>

/**
 * @abstract 为某个类下的某个key赋值。
 *
 * @param value 该主题的值，一般为 UIFont/UIColor等类型
 */
- (void)setThemeValue:(id)value forKey:(NSString *)key whenContainedIn:(Class)containerClass;
- (id)themeValueForKey:(NSString *)key whenContainedIn:(Class)containerClass;

@end
