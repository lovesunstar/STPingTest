//
//  STImagePickerController.h
//  STKit
//
//  Created by SunJiangting on 14-1-3.
//  Copyright (c) 2014年 SunJiangting. All rights reserved.
//

#import <STKit/STKit.h>
#import <UIKit/UIKit.h>

@class STImagePickerController;
@protocol STImagePickerControllerDelegate <NSObject>

// The picker does not dismiss itself; the client dismisses it in these callbacks.
// The delegate will receive one or the other, but not both, depending whether the user
// confirms or cancels.
- (void)imagePickerController:(STImagePickerController *)picker didFinishPickingImageWithInfo:(NSDictionary *)info;
- (void)imagePickerControllerDidCancel:(STImagePickerController *)picker;

@end

@interface STImagePickerController : STNavigationController {
    //    UIImagePickerController
}

@property(nonatomic, assign) BOOL allowsMultipleSelection;
@property(nonatomic, assign) NSInteger maximumNumberOfSelection; // default 20

@property(nonatomic, weak) id<STNavigationControllerDelegate, STImagePickerControllerDelegate> delegate;

@end

extern NSString *const STImagePickerControllerOriginalImagePath; // a path of image in temp
extern NSString *const STImagePickerControllerThumbImage;
extern NSString *const STImagePickerControllerOriginalImageAssetPath;

extern UIImage *STExactImageWithPath();
