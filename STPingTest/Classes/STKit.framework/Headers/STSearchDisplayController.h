//
//  STSearchDisplayController.h
//  STKit
//
//  Created by SunJiangting on 14-9-4.
//  Copyright (c) 2014年 SunJiangting. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "STSearchBar.h"

@protocol STSearchDisplayDelegate;
@interface STSearchDisplayController : NSObject

/// UISearchDisplayController
- (instancetype)initWithSearchBar:(STSearchBar *)searchView
               contentsController:(UIViewController *)viewController;

@property(nonatomic, weak) id<STSearchDisplayDelegate> delegate;

@property(nonatomic, getter=isActive) BOOL active; // configure the view controller for searching. default is NO.
                 // animated is NO
- (void)setActive:(BOOL)visible animated:(BOOL)animated; // animate the view controller for searching

@property(nonatomic, readonly, weak) STSearchBar        *searchBar;
@property(nonatomic, readonly, weak) UIViewController   *searchContentsController; // the view we are searching (often a UITableViewController)
@property(nonatomic, readonly) UITableView *searchResultsTableView; // will return non-nil. create if requested
@property(nonatomic, weak) id<UITableViewDataSource> searchResultsDataSource; // default is nil. delegate can provide
@property(nonatomic, weak) id<UITableViewDelegate>   searchResultsDelegate; // default is nil. delegate can provide
@property(nonatomic, copy) NSString *searchResultsTitle; // default is nil. If nil, the controller uses the default title string

@end

@protocol STSearchDisplayDelegate <NSObject>

@optional

// when we start/end showing the search UI
- (void)searchDisplayControllerWillBeginSearch:(STSearchDisplayController *)controller;
- (void)searchDisplayControllerDidBeginSearch:(STSearchDisplayController *)controller;
- (void)searchDisplayControllerWillEndSearch:(STSearchDisplayController *)controller;
- (void)searchDisplayControllerDidEndSearch:(STSearchDisplayController *)controller;

// called when table is shown/hidden
- (void)searchDisplayController:(STSearchDisplayController *)controller willShowSearchResultsTableView:(UITableView *)tableView;
- (void)searchDisplayController:(STSearchDisplayController *)controller didShowSearchResultsTableView:(UITableView *)tableView;
- (void)searchDisplayController:(STSearchDisplayController *)controller willHideSearchResultsTableView:(UITableView *)tableView;
- (void)searchDisplayController:(STSearchDisplayController *)controller didHideSearchResultsTableView:(UITableView *)tableView;

// return YES to reload table. called when search string/option changes.
// convenience methods on top UISearchBar delegate methods
- (BOOL)searchDisplayController:(STSearchDisplayController *)controller shouldReloadTableForSearchString:(NSString *)searchString;
- (BOOL)searchDisplayController:(STSearchDisplayController *)controller shouldReloadTableForSearchScope:(NSInteger)searchOption;

@end
