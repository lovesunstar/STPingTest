//
//  STLinkLabel.h
//  STKit
//
//  Created by SunJiangting on 13-11-27.
//  Copyright (c) 2013年 SunJiangting. All rights reserved.
//

#import <UIKit/UIKit.h>

#import <STKit/Foundation+STKit.h>

/**
 * @abstract location是否被该Range包含
 */
ST_INLINE BOOL STLocationInRange(NSRange range, NSUInteger location) {
    return (location >= range.location) && (location <= (range.location + range.length));
}
/**
 * @abstract range1 是否包含range2
 */
ST_INLINE BOOL STRangeContainsRange(NSRange range1, NSRange range2) {
    BOOL startContains = (range2.location >= range1.location) && (range2.location <= (range1.location + range1.length));
    BOOL endContains =
        ((range2.location + range2.length) >= range1.location) && ((range2.location + range2.length) <= (range1.location + range1.length));
    return startContains && endContains;
}
/// 自定义Link标签<link value="xxxx" color="0xFFFFFF" highlightedColor="0xFF0000" highlightedBackgroundColor="">display</link>
static u_int64_t STTextCheckingTypeCustomLink = (1ULL << 33);
/**
 * @abstract 点击事件的对象，内包含URL，range。@see STLinkLabel, NSTextCheckingResult
 * 如果是STTextCheckingType， 则从value中去取值
 */
@interface STLinkObject : NSObject
/// 该对象包含的URL，如果没有URL
@property(nonatomic, readonly, strong) NSURL *URL;
@property(nonatomic, readonly, strong) NSString *value;
@property(nonatomic, readonly, assign) NSRange range;

@end

@class STLinkLabel;
/**
 * @abstract 超链接点击时的回调
 * 普通Link http://a.b.c
 * CustomLink <link value="xxxx" color="0xFFFFFF" highlightedColor="0xFF0000" highlightedBackgroundColor="">display</link>
 */
@protocol STLinkLabelDelegate <NSObject>

@optional
/**
 * @abstract 超链接被点击的事件
 *
 * @param    linkLabel 点击事件的label
 * @param    linkObject 点击到的超链接对象
 */
- (void)linkLabel:(STLinkLabel *)linkLabel didSelectLinkObject:(STLinkObject *)linkObject;
@optional
/**
 * @abstract 超链接是否可以被点击
 *
 * @param    linkLabel 点击事件的label
 * @param    linkObject 点击到的超链接对象
 * @return   YES 则会出发linkLabel:didSelectLinkObject: 回调
 *
 */
- (BOOL)linkLabel:(STLinkLabel *)linkLabel shouldSelectLinkObject:(STLinkObject *)linkObject;
@end

/**
 * @abstract 此Label为可以带链接的Label。其中会自动解析文本中包含的链接 @see NSDataDetector, 并为其添加点击事件@see STLinkLabelDelegate。
 * 支持CustomLink，格式为 <link href="someURL" value="xxxx" color="0xFFFFFF" highlightedColor="0xFF0000" highlightedBackgroundColor="">display</link>
 * 若要支持CustomLink，需要设置checkingType|STTextCheckingTypeCustomLink
 * CustomLink 优先于SystemTextCheckingType
 */
@interface STLinkLabel : UIView
/// 是否自动解析超链接
@property(nonatomic, assign) BOOL autoHyperlink;
/// 点击对象的事件委托
@property(nonatomic, weak) id<STLinkLabelDelegate> delegate;
/// 文本内容
@property(nonatomic, copy) NSString *text;
/// 文本字体
@property(nonatomic, strong) UIFont *font;
/// 对其方式 default is NSTextAlignmentLeft
@property(nonatomic, assign) NSTextAlignment textAlignment;
/// 换行模式 default is NSLineBreakByWordWrapping
@property(nonatomic, assign) NSLineBreakMode lineBreakMode;
/// 暂时未用到
@property(nonatomic, assign) NSInteger numberOfLines;
/// 文本颜色
@property(nonatomic, strong) UIColor *textColor;
/// 超链接颜色， 默认blue
@property(nonatomic, strong) UIColor *linkColor;
/// 文本高亮的颜色
@property(nonatomic, strong) UIColor *highlightedTextColor;
/// 超链接高亮的颜色
@property(nonatomic, strong) UIColor *highlightedLinkColor;
/// 超链接高亮时的背景颜色，默认gray
@property(nonatomic, strong) UIColor *linkBackgroundColor;
@property(nonatomic, assign) BOOL     continueTouchEvent;

@property(nonatomic, assign, getter=isHighlighted) BOOL highlighted; // default is  NO

@property(nonatomic, assign) UIBaselineAdjustment baselineAdjustment; // default is UIBaselineAdjustmentAlignBaselines
/// @see STTextCheckingTypeCustomLink
@property(nonatomic, assign) NSTextCheckingTypes textCheckingTypes; // default is NSTextCheckingTypeLink

@property(nonatomic, assign) CGFloat verticalTouchAreaFactor; // default is 1.0

+ (CGSize)sizeWithText:(NSString *)linkText font:(UIFont *)font constrainedToSize:(CGSize)constrainedSize paragraphStyle:(NSParagraphStyle *)paragraphStyle;

+ (CGSize)sizeWithText:(NSString *)linkText textCheckingTypes:(NSTextCheckingTypes)checkingTypes font:(UIFont *)font constrainedToSize:(CGSize)constrainedSize paragraphStyle:(NSParagraphStyle *)paragraphStyle;

@end

@interface NSString (STLinkLabel)

- (CGSize)sizeWithFont:(UIFont *)font constrainedToSize:(CGSize)constrainedSize paragraphStyle:(NSParagraphStyle *)paragraphStyle;

@end