//
//  Config.h
//  HypeLabSdk
//
//  Created by Mark on 4/19/24.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface Config : NSObject

@property NSString *environment;
@property NSString *propertySlug;
@property int __flags;

- (instancetype)initWithEnvironment:(NSString *)environment
                       propertySlug:(NSString *)propertySlug;

@end

NS_ASSUME_NONNULL_END
