//
//  UIKit+STKit.h
//  STKit
//
//  Created by SunJiangting on 13-10-5.
//  Copyright (c) 2013年 SunJiangting. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <STKit/STDefines.h>
#import "Foundation+STKit.h"

#define STLogPoint(point) STLog(@"Point (%f, %f)", point.x, point.y);
#define STLogSize(size) STLog(@"Size (%f, %f)", size.width, size.height);
#define STLogRect(rect) STLog(@"Rect (%f,%f,%f,%f)", rect.origin.x, rect.origin.y, rect.size.width, rect.size.height);
#define STLogEdgeInsets(insets) STLog(@"EdgeInsets (%f,%f,%f,%f)", insets.top, insets.left, insets.bottom, insets.right);

extern CGFloat STOnePixel();
extern CGFloat STGetScreenWidth();
extern CGFloat STGetScreenHeight();

extern CGFloat STGetSystemVersion();
extern NSString *STGetSystemVersionString();

extern CGPoint STConvertPointBetweenSize(CGPoint point, CGSize fromSize, CGSize toSize);

#pragma mark - UIColor Extension
/// 给UIColor增加rgb的构造方法
@interface UIColor (STExtension)
/// 使用rgbValue构造UIColor [UIColor colorWithRGB:0xCB553B];
+ (UIColor *)colorWithRGB:(NSInteger)rgb;
/// 使用rgbValue构造UIColor [UIColor colorWithRGB:0xCB553B alpha:0.3];
+ (UIColor *)colorWithRGB:(NSInteger)rgb alpha:(CGFloat)alpha;
/// 使用rgb 16进制String构造UIColor [UIColor colorWithHexString:@"0xFFFFFF"];
+ (UIColor *)colorWithHexString:(NSString *)hexString;
+ (UIColor *)colorWithHexString:(NSString *)hexString alpha:(CGFloat)alpha;
@end

#pragma mark - UIView Extension

@interface UIView (STKit)

#pragma mark - UIView Frame Accesser
/**
 * @abstract getter CGRectGetMinY(self.frame) setter frame.origin.y = top;
 */
@property(nonatomic) CGFloat top;
/**
 * @abstract getter CGRectGetMaxY(self.frame) setter frame.origin.y = bottom - height;
 */
@property(nonatomic) CGFloat bottom;
/**
 * @abstract getter CGRectGetMinX(self.frame) setter frame.origin.x = left;
 */
@property(nonatomic) CGFloat left;
/**
 * @abstract getter CGRectGetMaxX(self.frame) setter frame.origin.x = right - width;
 */
@property(nonatomic) CGFloat right;
/**
 * @abstract getter CGRectGetWidth(self.frame) setter frame.size.width = width;
 */
@property(nonatomic) CGFloat width;
/**
 * @abstract getter CGRectGetHeight(self.frame) setter frame.size.height = height;
 */
@property(nonatomic) CGFloat height;
/**
 * @abstract getter frame.origin setter frame.origin = origin;
 */
@property(nonatomic) CGPoint origin;
/**
 * @abstract getter frame.size setter frame.size = size;
 */
@property(nonatomic) CGSize size;
/**
 * @abstract getter self.center.x setter center.x = centerX;
 */
@property(nonatomic) CGFloat centerX;
/**
 * @abstract getter self.center.y setter center.y = centerY;
 */
@property(nonatomic) CGFloat centerY;
/**
 * @abstract getter CGRectGetWidth(frame) / 2
 */
@property(nonatomic, readonly) CGFloat inCenterX;
/**
 * @abstract getter CGRectGetHeight(frame) / 2
 */
@property(nonatomic, readonly) CGFloat inCenterY;
/**
 * @abstract getter (inCenterX, inCenterY)
 */
@property(nonatomic, readonly) CGPoint inCenter;
/**
 * @abstract location in screen
 */
@property(nonatomic, readonly) CGFloat screenX;
/**
 * @abstract location in screen
 */
@property(nonatomic, readonly) CGFloat screenY;
/**
 * @abstract removeAllSubviews
 */
- (void)removeAllSubviews;

/**
 * @abstract view's viewController if the view has one
 */
- (UIViewController *)viewController;

/**
 * @abstract 递归查找view的nextResponder，直到找到类型为class的Responder
 *
 * @param class  nextResponder 的 class
 * @return       第一个满足类型为class的UIResponder
 */
- (UIResponder *)nextResponderWithClass:(Class) class;

/// 查找firstResponder
- (UIResponder *)findFirstResponder;

/**
 * @abstract view的superview中，是否包含某一类的view
 *
 * @param viewClass  superview 的 class
 * @return           view是否被添加到 类型为viewClass的superview上面
 */
- (BOOL)isDescendantOfClass:(Class)viewClass;

/**
 * @abstract    递归查找view的superview，直到找到类型为viewClass的view
 *
 * @param viewClass  superview 的 class
 * @return           第一个满足类型为viewClass的superview
 */
- (UIView *)superviewWithClass:(Class)viewClass;

/**
 * @abstract 递归遍历该view，找到该view中的所有subview类型为class的view
 *
 * @param viewClass  subview 的 class
 * @return           所有类型为class的subview
 */
- (NSArray *)viewWithClass:(Class) class;

/**
 * @abstract 为该View添加轻拍手势
 *
 * @param target 接受手势通知的对象
 * @param action 回调方法
 */
- (void)addTouchTarget:(id)target action:(SEL)action;
- (void)removeTouchTarget:(id)target action:(SEL)action;

/**
 * Return the x coordinate on the screen, taking into account scroll views.
 */
@property(nonatomic, readonly) CGFloat screenViewX;

/**
 * Return the y coordinate on the screen, taking into account scroll views.
 */
@property(nonatomic, readonly) CGFloat screenViewY;

/**
 * Return the view frame on the screen, taking into account scroll views.
 */
@property(nonatomic, readonly) CGRect screenFrame;

/**
 * Return the width in portrait or the height in landscape.
 */
@property(nonatomic, readonly) CGFloat orientationWidth;

/**
 * Return the height in portrait or the width in landscape.
 */
@property(nonatomic, readonly) CGFloat orientationHeight;
/**
 * Calculates the offset of this view from another view in screen coordinates.
 *
 * otherView should be a parent view of this view.
 */
- (CGPoint)offsetFromView:(UIView *)otherView;

@property(nonatomic) CGPoint    anchorPoint;

@end

/**
 * @abstract hitTestBlock
 *
 * @param 其余参数 参考UIView hitTest:withEvent:
 * @param returnSuper 是否返回Super的值。如果*returnSuper=YES,则代表会返回 super hitTest:withEvent:, 否则则按照block的返回值(即使是nil)
 * 
 * @discussion 切记，千万不要在这个block中调用self hitTest:withPoint,否则则会造成递归调用。这个方法就是hitTest:withEvent的一个代替。
 */
typedef UIView * (^STHitTestViewBlock)(CGPoint point, UIEvent *event, BOOL *returnSuper);
typedef BOOL (^STPointInsideBlock)(CGPoint point, UIEvent *event, BOOL *returnSuper);

@interface UIView (STHitTest)
/// althought this is strong ,but i deal it with copy
@property(nonatomic, strong) STHitTestViewBlock hitTestBlock;
@property(nonatomic, strong) STPointInsideBlock pointInsideBlock;

@end

/// 是否弹起系统Menu菜单（选择/复制/拷贝等等）
@interface UITextField (STMenuController)

/// default YES.
@property(nonatomic, assign, getter=isMenuEnabled) BOOL menuEnabled;

@end

/// 是否弹起系统Menu菜单（选择/复制/拷贝等等）
@interface UITextView (STMenuController)

/// default YES.
@property(nonatomic, assign, getter=isMenuEnabled) BOOL menuEnabled;

@end

/**
 * @abstract 图片类型。
 *
 * @param  STImageDataTypeUnknown 未知类型
 */
typedef enum {
    STImageDataTypeUnknown,
    STImageDataTypePCX,  // 文件头  共1字节  0A
    STImageDataTypeBMP,  // 文件头  共2字节  42 4d
    STImageDataTypeJPEG, // 文件头  共2字节  ff d8 文件尾 ff d9
    STImageDataTypePNG,  // 文件头  共8字节  89 50 4e 47 0d 0a 1a 0a
    STImageDataTypeGIF,  // 文件头  共6字节  47 49 46 38 39/37 61
    STImageDataTypeWebP,  // 文件头  共6字节  47 49 46 38 39/37 61
} STImageDataType;

/**
 * @abstract 根据Data内容，解析文件头。
 */
@interface NSData (STImage)
/// 根据data前8字节解析图片类型。@see STImageDataType
- (STImageDataType)imageType;

@end

/**
 * @abstract 根据Data内容，解析图片。
 */
@interface UIImage (STImage)
/// 判断图片类型，支持GIF解析
+ (UIImage *)imageWithSTData:(NSData *)data;

@end

/// imageNamed:.png/@2x.png/-568h@2x.png.
/// gif image must has suffix .gif, named:xxx.gif or xxx@2x.gif
@interface UIImage (STImageNamed)

@end

/**
 * @abstract!
 *
 * STBlurEffectStyleLight       比较淡色的毛玻璃效果，系统原生的NavigationBar毛玻璃效果
 * STBlurEffectStyleExtraLight  系统从最底部往上滑动的设置毛玻璃效果
 * STBlurEffectStyleDark        通知中心的毛玻璃效果
 */
typedef enum STBlurEffectStyle {
    STBlurEffectStyleNone,
    STBlurEffectStyleExtraLight,
    STBlurEffectStyleLight,
    STBlurEffectStyleDark
} STBlurEffectStyle;

/// 给图片添加毛玻璃效果
@interface UIImage (STBlurImage)

- (UIImage *)blurImageWithStyle:(STBlurEffectStyle)style;

- (UIImage *)blurImageWithTintColor:(UIColor *)tintColor;

- (UIImage *)blurImageWithRadius:(CGFloat)blurRadius tintColor:(UIColor *)tintColor saturationDeltaFactor:(CGFloat)saturationDeltaFactor;

- (UIImage *)blurImageWithRadius:(CGFloat)blurRadius
                       tintColor:(UIColor *)tintColor
           saturationDeltaFactor:(CGFloat)saturationDeltaFactor
                       maskImage:(UIImage *)maskImage;
@end

/// UIView 截图
@interface UIView (STSnapshot)
/// 截图后的image
- (UIImage *)snapshotImage;
/// 截取View中的某一小块
- (UIImage *)snapshotImageInRect:(CGRect)rect;
/// 把 UIView的transform也放进截图中
- (UIImage *)transformedSnapshotImage;

@end

@interface UIView (STBlur)

- (UIImage *)blurImage;

- (UIView *)statusBarWindow;

@end

typedef void (^STInvokeHandler)(void);

@interface UICollectionView (STReloadData)
@property(nonatomic, strong) STInvokeHandler willReloadData;
@property(nonatomic, strong) STInvokeHandler didReloadData;

@end


@interface UITableView (STReloadData)
@property(nonatomic, strong) STInvokeHandler willReloadData;
@property(nonatomic, strong) STInvokeHandler didReloadData;

@end

@interface UIActionSheet (STKit)

- (instancetype)initWithTitle:(NSString *)title
                     delegate:(id<UIActionSheetDelegate>)delegate
            cancelButtonTitle:(NSString *)cancelButtonTitle
       destructiveButtonTitle:(NSString *)destructiveButtonTitle
        otherButtonTitleArray:(NSArray *)otherButtonTitleArray;

@end

@interface UIImage (STSubimage)
+ (UIImage *)imageWithColor:(UIColor *)color;
+ (UIImage *)imageWithColor:(UIColor *)color size:(CGSize)size;
/// 某个rect下的子图像
- (UIImage *)subimageInRect:(CGRect)rect;

- (UIImage *)imageWithTransform:(CGAffineTransform)transform;

- (UIImage *)imageConstrainedToSize:(CGSize)size contentMode:(UIViewContentMode)contentMode;

@end

typedef enum STBarButtonCustomItem {
    STBarButtonCustomItemBack,
    STBarButtonCustomItemDismiss,
    STBarButtonCustomItemMore,
} STBarButtonCustomItem;
@interface UIBarButtonItem (STKit)

+ (instancetype)backBarButtonItemWithTarget:(id)target action:(SEL)action;
- (instancetype)initWithBarButtonCustomItem:(STBarButtonCustomItem)customItem target:(id)target action:(SEL)action;

- (instancetype)initWithTitle:(NSString *)title target:(id)target action:(SEL)action;
@end
