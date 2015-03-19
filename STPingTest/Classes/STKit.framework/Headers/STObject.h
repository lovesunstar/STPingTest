//
//  STObject.h
//  STKit
//
//  Created by SunJiangting on 14-8-30.
//  Copyright (c) 2014年 SunJiangting. All rights reserved.
//

#import <Foundation/Foundation.h>

#ifdef ST_IMPLEMENTION_FILE
#define ST_EXTERN
#else
#define ST_EXTERN extern
#endif

/**
 * @abstract 根据所传入的className和dictionary，构建一个Object
 *
 * @param  objectClass  需要创建对象的ClassName。
 * @param  dictionary   需要构建的一系列参数 @see relationship
 *
 * @discussion 传入的不一定必须是STObject， 理论上任何类型都可以，但是必须有relationship方法的实现, relationship
 *不必列出所有的属性-key映射，只需要列出 属性和key不同的地方即可，如果全部相同，返回nil就可以,
 *也无需调用父类的relationship，key相同的relationship会覆盖父类的relationship。
 */
ST_EXTERN id STObjectCreate(Class objectClass, NSDictionary *dictionary);

/**
 * @abstract 将当前的对象属性映射到dictionary中。
 */
ST_EXTERN NSDictionary *STObjectToDictionary(NSObject *object);

/**
 * @abstract 为某个对象进行重新赋值
 *
 * @discussion 传入的不一定必须是STObject， 理论上任何类型都可以, 将会把所有dictionary中未包含的值都置为空，剩下的都是用dictionary中的值
 */
ST_EXTERN void STObjectResetValue(NSObject *object, NSDictionary *dictionary);

/**
 * @abstract 更新Object中的某些字段的值
 *
 * @discussion 注意，更新只是字典中包含的，就会取重新赋值，其余的不会改变. @see STObjectResetValue
 */
ST_EXTERN void STObjectUpdateValue(NSObject *object, NSDictionary *dictionary);

/// Copy Object
ST_EXTERN id STObjectCreateCopy(NSObject *object);

/// 得到这个类下的所有属性关系映射
ST_EXTERN NSDictionary *STClassGetPropertyRelationship(Class class);

/*

 @interface STTestObject : STObject

 @property (nonatomic, copy) NSString * name;

 @property (nonatomic, strong) STTestObject * friendObject;

 @property (nonatomic, copy)   NSArray * otherObjects;

 @property (nonatomic, copy)   NSArray * descriptions;

 @end

 @implementation STTestObject

 + (Class) otherObjectsClass {
    return [STTestObject class];
 }

 + (Class) descriptionsClass {
    return [NSString class];
 }

 @end

 // use dictionary
 @{@"name":@"name", @"friendObject":@{@"name":@"xxx", ...}, @"otherObjects":@[@{@"name":@"name", ...}, @"descriptions":@[@"description1",
 @"description2", ...]]}


 */
/**
 * @abstract 根据Dictionary自动对象映射。
 * 目前可以根据dictionary为对应的变量赋值，集合类的仅支持NSArray/NSSet 以及NSMutable__##__， 不支持的部分，将保留原数据。
 *
 * @discussion 注意，如果对象中包含数组，比如<br/>
 *    <br /> \@property(nonatomic, copy) NSArray * friends;  // class STFriend;
 *  则需要实现名称为propertyNameClass的类方法，用于将property数组解析成对应的对象数组 如果未实现类方法，则array会保持原始dictionary中的数据
 */
@interface STObject : NSObject

+ (instancetype)objectWithDictionary:(NSDictionary *)dictionary;

- (instancetype)initWithDictinoary:(NSDictionary *)dictionary;

/**
 * @abstract 根据dict更新Object中对应的属性
 *
 * @param dictionary 需要更新的字段值，需要与relationship对应。
 */
- (void)updateValueWithDictionary:(NSDictionary *)dictionary;

/**
 * @abstract 重置Object变量值，如果字段没有传值，则初始化为原始值，比如 0 nil 等
 *
 * @param dictionary 字段对应的值，需要与relationship对应。
 */
- (void)resetValueWithDictionary:(NSDictionary *)dictionary;

- (NSDictionary *)toDictionary;

/**
 * @abstract relationship 为 property --->  dictionary key的对应。
 *
 * @discussion 默认会有 propertyName ---> key的对应。
 *             每个子类只需要写出与dictionary key不一样的那一部分而已，不需要super。
 *             假设 ClassA 中 有 property a, dictionary中key也是a，则不需要重写此方法
 *             ClassB继承ClassA， ClassB中新增了变量b， 对应的是c，则需要重写此方法 relationship {return @{@"b":@"c"}}, 只返回不一样的对应即可
 *
 * @attention  dictionary的key为property, value 为dict's key
 */
+ (NSDictionary *)relationship;

@end
