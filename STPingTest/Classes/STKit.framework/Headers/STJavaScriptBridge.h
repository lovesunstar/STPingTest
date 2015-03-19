//
//  STJavaScriptBridge.h
//  STKit
//
//  Created by SunJiangting on 14-10-16.
//  Copyright (c) 2014年 SunJiangting. All rights reserved.
//

#import <UIKit/UIKit.h>

@class STJavaScriptBridgeItem;

typedef void (^STBridgeCompletionHandler)(NSDictionary *dictionary);
typedef void (^STBridgeHandler)(STJavaScriptBridgeItem *item, STBridgeCompletionHandler completionHandler);

@interface STJavaScriptBridgeItem : NSObject

@property (nonatomic, copy) NSString     *eventID;
@property (nonatomic, copy) NSString     *callbackID;
@property (nonatomic, copy) NSString     *method;
@property (nonatomic, copy) NSDictionary *parameters;

@end

@interface STJavaScriptBridge : NSObject

@property(nonatomic, weak, readonly) UIWebView *webview;

@property(nonatomic, copy) NSString *scheme;
@property(nonatomic, copy) NSString *host;

- (void)registerBridgeHandler:(STBridgeHandler)bridgeHandler forJSMethod:(NSString *)JSMethod;

@end

@interface UIWebView (STJavaScriptBridge)

@property(nonatomic, strong, readonly) STJavaScriptBridge *JSBridge;

@property(nonatomic, assign) BOOL allowsJavaScriptBridge;

@end
