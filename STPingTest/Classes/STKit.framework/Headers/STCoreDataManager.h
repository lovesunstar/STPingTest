//
//  STCoreDataManager.h
//  STKit
//
//  Created by SunJiangting on 13-10-5.
//  Copyright (c) 2013年 SunJiangting. All rights reserved.
//

#import <STKit/STDefines.h>
#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>

/**
 * @abstract CoreData管理。
 *
 */
@interface STCoreDataManager : NSObject

+ (STCoreDataManager *)defaultDataManager;

@property(nonatomic, readonly, strong) NSString *modelName;
@property(nonatomic, readonly, strong) NSString *dbFilePath;
/// 设置 momd 文件名称。 不需要后缀。会生成一个同名的sqlite文件
- (void)setModelName:(NSString *)modelName;

/// 该Context始终在主线程中。 UIViewController的fetchResultsController
@property(nonatomic, readonly) NSManagedObjectContext *managedObjectContext;
/// 该Context始终在子线程，并且parentContext为楼上的Context。为了提升主线程的绘制效率，建议所有的保存操作都在此Context进行。
@property(nonatomic, readonly) NSManagedObjectContext *backgroundManagedObjectContext;

- (NSManagedObjectContext *)dispatchManagedObjectContext;

/**
 * @abstract 将block中的变换进行save操作
 *
 * @param managedObjectContext 发生改变的managedObject
 */
- (BOOL)saveManagedObjectContext:(NSManagedObjectContext *)managedObjectContext error:(NSError **)error;

// 以下方法分别为在 任意子线程，主线程，特定后台线程执行block
/**
 * @abstract 将一些数据库的CRUD方法放在block中。
 *
 * @param    block 需要执行的代码段
 * @param    waitUntilDone 是否需要等待执行, 如果是NO,则立刻返回，將block添加到queue中等待执行
 */
- (void)performBlock:(void (^)(NSManagedObjectContext *))block waitUntilDone:(BOOL)waitUntilDone;
- (void)performBlockOnMainThread:(void (^)(NSManagedObjectContext *))block waitUntilDone:(BOOL)waitUntilDone;
- (void)performBlockInBackground:(void (^)(NSManagedObjectContext *))block waitUntilDone:(BOOL)waitUntilDone;
@end

@interface NSFetchedResultsController (STCoreDataManager)

- (NSFetchedResultsController *)initWithFetchRequest:(NSFetchRequest *)fetchRequest
                                  sectionNameKeyPath:(NSString *)sectionName
                                           cacheName:(NSString *)cacheName;

@end

@interface NSManagedObjectContext (STCoreDataManager)
- (NSEntityDescription *)descriptionForEntityName:(NSString *)entityName;
- (NSManagedObject *)entityClassFromString:(NSString *)className name:(NSString *)entityName;

@end