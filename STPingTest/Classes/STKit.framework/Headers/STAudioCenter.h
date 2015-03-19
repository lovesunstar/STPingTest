//
//  STAudioCenter.h
//  STKit
//
//  Created by SunJiangting on 13-10-5.
//  Copyright (c) 2013年 SunJiangting. All rights reserved.
//

#import <STKit/STDefines.h>
#import <Foundation/Foundation.h>
#import <AudioToolbox/AudioToolbox.h>
#import <STKit/STAudioRecorder.h>

@interface STAudioCenter : NSObject

+ (instancetype)sharedAudioCenter;

+ (void)setAudioSessionEnabled:(BOOL)audioSessionEnabled wantRecording:(BOOL)wantRecording;
/// 播放震动
- (void)playVibrations;

@end

@interface STAudioCenter (STAudioRecorder)

@property(nonatomic, readonly, strong) STAudioRecorder *audioRecorder;

- (void)startRecordWithPath:(NSString *)path handler:(STAudioRecordHandler)audioHandler;
- (void)startRecordWithPath:(NSString *)path handler:(STAudioRecordHandler)audioHandler dataHandler:(STAudioDataHandler)dataHandler;
- (void)finishRecord;
@end

extern NSString *const STAudioSessionOutputVolumeDidChangeNotification;

extern NSString *const STAudioSessionOutputVolumeNewValueKey;
extern NSString *const STAudioSessionOutputVolumeOldValueKey;