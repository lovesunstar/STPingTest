//
//  STTabBar.h
//  STKit
//
//  Created by SunJiangting on 14-2-13.
//  Copyright (c) 2014年 SunJiangting. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol STTabBarDelegate;
@class STTabBarItem;
/// UITabBar
@interface STTabBar : UIView

@property(nonatomic, assign) id<STTabBarDelegate> delegate; // weak reference. default is nil
@property(nonatomic, copy) NSArray *items;                  // get/set visible UITabBarItems. default is nil. changes not animated. shown in order
@property(nonatomic, assign) STTabBarItem *selectedItem;    // will show feedback based on mode. default is nil
                                                            /*
                                                             The behavior of tintColor for bars has changed on iOS 7.0. It no longer affects the bar's background
                                                             and behaves as described for the tintColor property added to UIView.
                                                             To tint the bar's background, please use -barTintColor.
                                                             */
@property(nonatomic, retain) UIColor *barTintColor;         // default is nil

/* selectedImageTintColor will be applied to the gradient image used when creating the
 selected image. Default is nil and will result in the system bright blue for selected
 tab item images. If you wish to also customize the unselected image appearance, you must
 use -setFinishedSelectedImage:finishedUnselectedImage: on individual tab bar items.
 */
@property(nonatomic, retain) UIColor *selectedImageTintColor;

/* The background image will be tiled to fit, even if it was not created via the UIImage resizableImage methods.
 */
@property(nonatomic, retain) UIImage *backgroundImage;

@property(nonatomic, getter=isTranslucent) BOOL translucent;

/// default NO, if YES you need to custom add subview
@property(nonatomic, assign) BOOL customizable;

- (void)setBadgeValue:(NSString *)badgeValue forIndex:(NSInteger)index;
- (NSString *)badgeValueForIndex:(NSInteger)index;

@property(nonatomic, strong, readonly) UIView *separatorView;

@end

@protocol STTabBarDelegate <NSObject>
@optional

- (void)tabBar:(STTabBar *)tabBar didSelectItem:(STTabBarItem *)item; // called when a new view is selected by the user (but not programatically)
@end
