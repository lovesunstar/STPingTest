//
//  STNotificationWindow.h
//  STKit
//
//  Created by SunJiangting on 13-11-28.
//  Copyright (c) 2013年 SunJiangting. All rights reserved.
//

#import <STKit/STDefines.h>
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@protocol STNotificationWindowDelegate <NSObject>

- (void)allNoticationViewDismissed;

@end

typedef void (^Completion)(BOOL completion);

@class STNotificationWindow, STImageView, STLabel;
;
@interface STNotificationView : UIView

@property(nonatomic, readonly, strong) STImageView *imageView;
@property(nonatomic, readonly, strong) STLabel *textLabel;
@property(nonatomic, readonly, strong) STLabel *detailLabel;

- (instancetype)initWithFrame:(CGRect)frame; /// do not use this initializer

@end

@interface STNotificationWindow : UIWindow

@property(nonatomic, weak) id<STNotificationWindowDelegate> notificationWindowDelegate;
/// max message the window can show.
@property(nonatomic, assign) NSInteger maximumNumberOfWindows;
@property(nonatomic, assign) NSTimeInterval displayDuration;

- (void)pushNotificationView:(STNotificationView *)notificationView animated:(BOOL)animated;
- (void)popNotificationViewAnimated:(BOOL)animated;

@end

@interface STNotificationCenter : NSObject

@end

@interface STNotificationWindow (STNotificationView)
+ (STNotificationView *)notificationViewWithInfo:(NSDictionary *)notificationInfo;
@end

extern NSString *const STNotificationViewImageNameKey;
extern NSString *const STNotificationViewTitleTextKey;
extern NSString *const STNotificationViewDetailTextKey;
