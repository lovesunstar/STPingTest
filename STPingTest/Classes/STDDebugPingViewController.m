//
//  STDDebugPingViewController.m
//  STKitDemo
//
//  Created by SunJiangting on 15-3-9.
//  Copyright (c) 2015年 SunJiangting. All rights reserved.
//

#import "STDDebugPingViewController.h"
#import "STDebugFoundation.h"
#import "STDPingServices.h"

@interface STDDebugPingViewController ()

@property(nonatomic, strong) UITextField        *textField;
@property(nonatomic, strong) STDebugTextView    *textView;
@property(nonatomic, strong) STDPingServices    *pingServices;

@end

@implementation STDDebugPingViewController

- (void)dealloc {
    [self.pingServices cancel];
}

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    self.navigationItem.title = @"Ping网络";
    self.navigationItem.rightBarButtonItem = [[UIBarButtonItem alloc] initWithTitle:@"Clear" style:UIBarButtonItemStylePlain target:self action:@selector(_clearDebugViewActionFired:)];
    if ([UIViewController instancesRespondToSelector:@selector(setEdgesForExtendedLayout:)]) {
        self.edgesForExtendedLayout  = UIRectEdgeNone;
    }
    self.view.backgroundColor = [UIColor whiteColor];
    
    self.textField = [[UITextField alloc] initWithFrame:CGRectMake(10, 10, CGRectGetWidth(self.view.frame) - 100, 30)];
    self.textField.borderStyle = UITextBorderStyleRoundedRect;
    self.textField.placeholder = @"请输入IP地址或者域名";
    self.textField.text = @"suenblog.duapp.com";
    [self.view addSubview:self.textField];
    
    UIButton *goButton = [UIButton buttonWithType:UIButtonTypeCustom];
    goButton.frame = CGRectMake(CGRectGetMaxX(self.textField.frame) + 10, 10, 60, 30);
    [goButton setTitle:@"Ping" forState:UIControlStateNormal];
    [goButton setTitleColor:[UIColor blueColor] forState:UIControlStateNormal];
    [goButton addTarget:self action:@selector(_pingActionFired:) forControlEvents:UIControlEventTouchUpInside];
    goButton.tag = 10001;
    [self.view addSubview:goButton];
    
    self.textView = [[STDebugTextView alloc] initWithFrame:CGRectMake(0, CGRectGetMaxY(self.textField.frame) + 10, CGRectGetWidth(self.view.frame), CGRectGetHeight(self.view.frame) - CGRectGetMaxY(self.textField.frame) - 10)];
    self.textView.autoresizingMask = UIViewAutoresizingFlexibleWidth | UIViewAutoresizingFlexibleHeight;
    self.textView.editable = NO;
    [self.view addSubview:self.textView];
}

- (void)_clearDebugViewActionFired:(id)sender {
    self.textView.text = nil;
}

- (void)_pingActionFired:(UIButton *)button {
    //    [SimplePingHelper ping:self.textField.text target:self sel:@selector(_pingCallback:)];
    [self.textField resignFirstResponder];
    if (button.tag == 10001) {
        __weak STDDebugPingViewController *weakSelf = self;
        [button setTitle:@"Stop" forState:UIControlStateNormal];
        button.tag = 10002;
        self.pingServices = [STDPingServices startPingAddress:self.textField.text callbackHandler:^(STDPingItem *pingItem, NSArray *pingItems) {
            if (pingItem.status != STDPingStatusFinished) {
                [weakSelf.textView appendText:pingItem.description];
            } else {
                [weakSelf.textView appendText:[STDPingItem statisticsWithPingItems:pingItems]];
                [button setTitle:@"Ping" forState:UIControlStateNormal];
                button.tag = 10001;
                weakSelf.pingServices = nil;
            }
        }];
    } else {
        [self.pingServices cancel];
    }
    
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
