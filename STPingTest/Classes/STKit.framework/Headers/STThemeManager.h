//
//  STThemeManager.h
//  STKit
//
//  Created by SunJiangting on 13-12-19.
//  Copyright (c) 2013年 SunJiangting. All rights reserved.
//

#import <Foundation/Foundation.h>

@class STTheme;
@interface STThemeManager : NSObject

+ (instancetype)sharedThemeManager;

+ (STTheme *)currentTheme;
@end
