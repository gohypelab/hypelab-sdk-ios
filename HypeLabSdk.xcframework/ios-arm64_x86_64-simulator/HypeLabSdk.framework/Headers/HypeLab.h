//
//  HypeLab.h
//  HypeLabSdk
//
//  Created by Mark on 4/17/24.
//

#import <Foundation/Foundation.h>
#import <HypeLabSdk/Config.h>

NS_ASSUME_NONNULL_BEGIN

@interface HypeLab : NSObject

+ (void)initialize:(Config *)config;
+ (Config *)getConfig;

@end

NS_ASSUME_NONNULL_END
