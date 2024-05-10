//
//  Rewarded.h
//  HypeLabSdk
//
//  Created by Mark on 4/17/24.
//

#import <Foundation/Foundation.h>
#import <WebKit/WebKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface Rewarded
    : NSObject <WKUIDelegate, WKNavigationDelegate, WKScriptMessageHandler> {
  NSString *placementSlug;
  WKWebView *webView;
}
@property void (^onReady)(void);
@property void (^onError)(void);
@property void (^onReward)(void);
@property void (^onVideoStart)(void);
@property void (^onVideoComplete)(void);
@property void (^onVideoError)(void);
@property void (^onImpression)(void);
@property void (^onClick)(void);

- (instancetype)initWithPlacementSlug:(NSString *)placementSlug;
- (void)show;
@end

NS_ASSUME_NONNULL_END
