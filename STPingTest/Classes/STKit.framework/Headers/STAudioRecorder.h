//
//  STAudioRecorder.h
//  STKit
//
//  Created by SunJiangting on 13-10-5.
//  Copyright (c) 2013年 SunJiangting. All rights reserved.
//

#import <STKit/STDefines.h>
#import <Foundation/Foundation.h>
#import <AudioToolbox/AudioToolbox.h>

/// 录音状态
typedef enum STAudioRecorderState : NSInteger {
                                        STAudioRecorderBegan,      // 开始录音
                                        STAudioRecorderProgressed, // 正在录音
                                        STAudioRecorderEnded,
                                        STAudioRecorderCancelled, // 理论上该方法不会被调用。
                                        STAudioRecorderFailed,    // 录音失败,文件错误等等
                                    } STAudioRecorderState;

/**
 * @abstract 录音回调
 *
 * @param state     录音状态
 * @param userInfo  录音中的一些数据，一般是NSDictionary。可以通过文件中定义的Key去获取一些值
 * @param error     录音失败，失败原因。
 */
typedef void (^STAudioRecordHandler)(STAudioRecorderState state, id userInfo, NSError *error);

/**
 * @abstract 录音数据回调
 *
 * @param buffer    音频数据
 * @param error     录音失败，失败原因。
 */
typedef void (^STAudioDataHandler)(AudioQueueBufferRef buffer, NSError *error);

@interface STAudioRecorder : NSObject

/// 是否在recordoing状态
@property(nonatomic, readonly) BOOL recording;
/// 音频储存路径
@property(nonatomic, readonly) NSString *path;
/// 音频采样率 default 44100，一旦开始录音，则不能改变sampleRate值，需要预先设置好sampleRate，然后开始录音
@property(nonatomic, assign) NSUInteger sampleRate;

/**
 * @abstract 开始录音
 *
 * @param    path           音频文件将要保存的路径
 * @param    audioHandler   用于录音状态时界面的相应。该回调不会返回音频数据，每次需要绘制的时候则会回调，默认1s调用60次。
 *
 * @discussion  录音时，界面如果需要响应，比如 显示音波效果等，就需要从audioHandler回调中取得值
 */
// 以下两个方法均为录音方法。 如果需要得到原始音频数据，则需要使用第二个方法。
- (void)startRecordWithPath:(NSString *)path handler:(STAudioRecordHandler)audioHandler;
// 该方法的两个回调没有先后顺序，没有必然联系。如果录音状态正常，则audioHandler会随着绘制周期而回调。dataHandler则为AudioQueue有数据了才会回调。
- (void)startRecordWithPath:(NSString *)path handler:(STAudioRecordHandler)audioHandler dataHandler:(STAudioDataHandler)dataHandler;

- (void)pause;
// 停止录音
- (void)stop;

@end

extern NSString *const STAudioRecorderKeyDuration;
extern NSString *const STAudioRecorderKeyPeakPower;
extern NSString *const STAudioRecorderKeyAveragePower;
extern NSString *const STAudioRecorderKeyErrorDomain;
extern NSString *const STAudioRecorderKeyErrorData;