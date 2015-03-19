//
//  STSearchBar.h
//  STKit
//
//  Created by SunJiangting on 14-9-4.
//  Copyright (c) 2014年 SunJiangting. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface STSearchEditView : UIView

@property(nonatomic, strong) UIButton *deleteButton;
@property(nonatomic, strong) UITextField *editTextField;
@property(nonatomic, strong) UIImageView *backgroundImageView;

- (void)reloadInputState;

@end

@protocol STSearchBarDelegate;
@interface STSearchBar : UIView
/// UISearchBar
@property(nonatomic, readonly, strong) UIImageView *backgroundImageView;
@property(nonatomic, readonly, strong) STSearchEditView *searchEditView;

@property(nonatomic, copy) NSString *text; // current/starting search text

@property(nonatomic, readonly, strong) UIButton *cancelView;
/// default is nil.
@property(nonatomic, readonly, strong) UIButton *leftButton;
@property(nonatomic, readonly, strong) UIButton *rightButton;

- (void)setEditing:(BOOL)editing animated:(BOOL)animated completion:(void (^)(BOOL))completion;

@property(nonatomic, weak) id<STSearchBarDelegate> delegate;

@end

@protocol STSearchBarDelegate <NSObject>
/// UISearchBar
@optional

- (BOOL)searchBarShouldBeginEditing:(STSearchBar *)searchBar; // return NO to not become first responder
- (void)searchBarTextDidBeginEditing:(STSearchBar *)searchBar; // called when text starts editing
- (BOOL)searchBarShouldEndEditing:(STSearchBar *)searchBar; // return NO to not resign first responder
- (void)searchBarTextDidEndEditing:(STSearchBar *)searchBar; // called when text ends editing
- (void)searchBar:(STSearchBar *)searchBar textDidChange:(NSString *)searchText; // called when text changes (including clear)
- (BOOL)searchBar:(STSearchBar *)searchBar shouldChangeTextInRange:(NSRange)range replacementText:(NSString *)text; // called before text changes

- (void)searchBarSearchButtonClicked:(STSearchBar *)searchBar; // called when keyboard search button pressed
- (void)searchBarBookmarkButtonClicked:(STSearchBar *)searchBar; // called when bookmark button pressed
- (void)searchBarCancelButtonClicked:(STSearchBar *)searchBar; // called when cancel button pressed
- (void)searchBarResultsListButtonClicked:(STSearchBar *)searchBar; // called when search results button pressed

- (void)searchBar:(STSearchBar *)searchBar selectedScopeButtonIndexDidChange:(NSInteger)selectedScope;
@end

extern CGFloat const STSearchViewDefaultHeight;