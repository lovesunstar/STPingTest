//
//  SWaveAnalysis.h
//  SMood
//
//  Created by SunJiangting on 13-3-21.
//  Copyright (c) 2013年 sun. All rights reserved.
//

#import "fft.h"

#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
#define FFT_RESULT_SIZE (1 << (FFT_BUFFER_SIZE_LOG - 1))
#define FFT_AUDIO_BUFFER_SIZE (1 << (FFT_BUFFER_SIZE_LOG + 1))

// 目前采样点为512
typedef struct STAnalysisBuffer {
    SInt8 channels;                    // 分析为单声道还是多声道
    SInt16 result[2][FFT_RESULT_SIZE]; // 分析后的数据,如果是单声道，则只分析result[0][*]
} STAnalysisBuffer;

typedef STAnalysisBuffer *STAnalysisBufferRef;

/**
 * @brief 该类主要是对音频数据进行采样分析，主要用到快速傅立叶变换(fft),根据变换之后的值即可对数据进行分量，得到各个频段下的能量
 */
@interface STWaveAnalysis : NSObject

/// 所有的高度是根据 constraintsHeight 相对计算得来的，默认为100
@property(nonatomic, assign) CGFloat constraintsHeight;

// 默认单声道
- (STAnalysisBufferRef)analysisWithData:(NSData *)data;

/**
 * @brief 对data中的数据进行傅立叶变换,采样点为512
 *
 * @param  data 需要分析的原始音频数据
 * @param  channels 音频为单声道还是双声道
 *
 * @return 返回分析后的结果，分析后的结果为二维数组，如果单声道音频,则只有result[0][i] 有值
 * @note   所传入的data必须为原始音频数据，如果传入其它音频数据，则不能保证分析的数据是准确的。必须保证data中有512 个short
 */
- (STAnalysisBufferRef)analysisWithData:(NSData *)data channels:(NSInteger)channels;

@end

// 获取绘制柱状图所需要的数据
@interface STWaveAnalysis (SWaveBar)
// 默认单声道，分量频率为默认值
- (NSArray *)heightForBarWithData:(NSData *)data;
// 默认分量频率
- (NSArray *)heightForBarWithData:(NSData *)data channels:(NSInteger)channels;

/**
 * @brief 该方法主要是针对条形图和分量频率对各个频率的能量进行求值
 *
 * @param  data 原始音频数据
 * @param  channels 声道个数
 * @param  frequency 分量频率
 * @return 返回各个分量下的能量值，比如 20k 下的power为40
 * @note   data必须为原始数据，否则不保证分析结果的准确性。必须保证data的长度包含512个short
 */
- (NSArray *)heightForBarWithData:(NSData *)data channels:(NSInteger)channels constraintsFrequency:(NSArray *)frequency;

@end

@interface STWaveAnalysis (SLemuria)

- (NSArray *)heightWithData:(NSData *)data channels:(NSInteger)channels constraintsFrequency:(NSArray *)frequency;

@end
