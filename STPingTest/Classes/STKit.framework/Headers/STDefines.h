//
//  STDefines.h
//  STKit
//
//  Created by SunJiangting on 13-11-27.
//  Copyright (c) 2013年 SunJiangting. All rights reserved.
//

#ifndef STKit_STDefines_h
#define STKit_STDefines_h

#if !defined(ST_INLINE)
#if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L
#define ST_INLINE static inline
#elif defined(__cplusplus)
#define ST_INLINE static inline
#elif defined(__GNUC__)
#define ST_INLINE static __inline__
#else
#define ST_INLINE static
#endif
#endif

#if !defined(ST_EXTERN)
#define ST_EXTERN extern
#endif

#endif

#import <CoreGraphics/CoreGraphics.h>
#import <Foundation/Foundation.h>

#ifndef DEBUG
#ifdef STLog
#undef STLog(format, ...)
#define STLog(format, ...)
#else
#define STLog(format, ...)
#endif
#else
#ifndef STLog
#define STLog(format, ...) NSLog((@"%s [Line %d] " format), __PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__);
#endif
#endif

/// 定义一种结构体，用来表示区间。表示一个 从 几到几 的概念
typedef struct _STRange {
    NSInteger start;
    NSInteger end;
} STRange;

ST_INLINE CGFloat STDistanceBetweenPoints(CGPoint point1, CGPoint point2) {
    CGFloat distance2 = ABS((point1.x - point2.x) * (point1.x - point2.x) + (point1.y - point2.y) * (point1.y - point2.y));
    return sqrtf(distance2);
}

/**
 * @brief 创建结构体 STRange，结构体中保存start，end
 * @param start 范围开始
 * @param end   范围结束
 * @return 返回 该范围
 * @note eg. SRangeMake(0,5) 则返回 0~5
 */
ST_INLINE STRange STRangeMake(NSInteger start, NSInteger end) {
    STRange range;
    range.start = start;
    range.end = end;
    return range;
}

/**
 * @brief 该int 数 是否在 STRange区间内
 * @param r 整形区间
 * @param i 要比较的数
 * @return i在区间 r内，返回YES；否则，返回NO
 */
ST_INLINE BOOL InRange(STRange r, NSInteger i) { return (r.start <= i) && (r.end >= i); }
/**
 * @brief 该点是否在某一rect区间内
 * @param p 点
 * @param r 矩形
 */
ST_INLINE BOOL CGPointInRect(CGPoint p, CGRect r) {
    return p.x > r.origin.x && p.x < (r.origin.x + r.size.width) && p.y > r.origin.y && p.y < (r.origin.y + r.size.height);
}