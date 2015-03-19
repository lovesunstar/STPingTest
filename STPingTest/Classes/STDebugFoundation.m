//
//  STDebugFoundation.m
//  STKitDemo
//
//  Created by SunJiangting on 15-3-9.
//  Copyright (c) 2015年 SunJiangting. All rights reserved.
//

#import "STDebugFoundation.h"

@implementation STDebugTextView

- (instancetype)initWithFrame:(CGRect)frame {
    self = [super initWithFrame:frame];
    if (self) {
        self.backgroundColor = [UIColor blackColor];
        self.textColor = [UIColor greenColor];
        if ([self respondsToSelector:@selector(layoutManager)]) {
            self.layoutManager.allowsNonContiguousLayout = NO;
        }
        self.font = [UIFont systemFontOfSize:14];
        self.editable = NO;
    }
    return self;
}

- (void)appendText:(NSString *)text {
    if (text.length == 0) {
        return;
    }
    if (self.text.length == 0) {
        self.text = text;
    } else {
        self.text = [NSString stringWithFormat:@"%@\n%@" , self.text, text];
        [self scrollToBottomAnimated:YES];
    }
}

- (void)scrollToBottomAnimated:(BOOL)animated {
    [self scrollRangeToVisible:NSMakeRange(self.text.length, 0)];
}

- (BOOL)canPerformAction:(SEL)action withSender:(id)sender {
    NSString *selectorName = NSStringFromSelector(action);
    return [selectorName hasPrefix:@"copy"] || [selectorName hasPrefix:@"select"];
}

@end
