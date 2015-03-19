//
//  STLocationManager.h
//  STKit
//
//  Created by SunJiangting on 14-5-13.
//  Copyright (c) 2014年 SunJiangting. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

typedef void (^STLocationHandler)(CLLocation *location, NSError *error);

typedef void (^STGeoReverseHandler)(CLPlacemark *placemark, NSError *error);

@interface STLocationManager : NSObject

+ (instancetype)sharedManager;

- (void)requestWhenInUseAuthorization;
- (void)requestAlwaysAuthorization;

- (void)obtainLocationWithHandler:(STLocationHandler)handler;

- (void)obtainLocationWithGeoHandler:(STGeoReverseHandler)geoReverseHandler;
/// first step. obtain location then reverse geocode
- (void)obtainLocationWithHandler:(STLocationHandler)handler reverseGeocodeHandler:(STGeoReverseHandler)geoReverseHandler;

- (void)reverseLocation:(CLLocation *)location reverseHandler:(STGeoReverseHandler)geoReverseHandler;

/// default nil, if has been located once, it will be the lastest location
@property(atomic, strong) CLLocation *location;
@property(atomic, strong) CLPlacemark *placemark;
@property(nonatomic, strong) NSError *error;

@end

extern NSString *const STLocationDidObtainNotification;
extern NSString *const STLocationDidReverseNotification;