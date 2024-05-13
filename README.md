# HypeLab SDK for iOS

Integrate HypeLab ads in your iOS app.

## Getting Started

### Install HypeLab SDK

#### CocoaPods

Add the `HypeLabSdk` dependency to your `Podfile`

```ruby
pod 'HypeLabSdk', '~> 1.0'
```

Then install the pod

```sh
pod install
```

#### Swift Package Manager

Find the package using the git url: `https://github.com/gohypelab/hypelab-sdk-ios`

### Configure HypeLab SDK

Swift:

```swift
import HypeLabSdk.HypeLab
import HypeLabSdk.Config

// ...

let config = Config(environment: "environment", propertySlug: "propertySlug")
HypeLab.initialize(config)
```

Objective-C:

```objc
#import <HypeLabSdk/HypeLab.h>
#import <HypeLabSdk/Config.h>

// ...

Config *config = [[Config alloc] initWithEnvironment:@"environment" propertySlug:@"propertySlug"];
[HypeLab initialize:config];
```

### Create a Rewarded ad

Swift:

```swift
import HypeLabSdk.Rewarded

// ...

let rewarded = Rewarded(placementSlug: "placementSlug");
rewarded.onReady = { print("Rewarded onReady") }
rewarded.onError = { print("Rewarded onError") }
rewarded.onVideoStart = { print("Rewarded onVideoStart") }
rewarded.onVideoComplete = { print("Rewarded onVideoComplete") }
rewarded.onVideoError = { print("Rewarded onVideoError") }
rewarded.onImpression = { print("Rewarded onImpression") }
rewarded.onClick = { print("Rewarded onClick") }
```

Objective-C:

```objc
#import <HypeLabSdk/Rewarded.h>

// ...

Rewarded *rewarded = [[Rewarded alloc] initWithPlacementSlug:@"placementSlug"];
rewarded.onReady = ^{ NSLog(@"Rewarded onReady"); };
rewarded.onError = ^{ NSLog(@"Rewarded onError"); };
rewarded.onVideoStart = ^{ NSLog(@"Rewarded onVideoStart"); };
rewarded.onVideoComplete = ^{ NSLog(@"Rewarded onVideoComplete"); };
rewarded.onVideoError = ^{ NSLog(@"Rewarded onVideoError"); };
rewarded.onImpression = ^{ NSLog(@"Rewarded onImpression"); };
rewarded.onClick = ^{ NSLog(@"Rewarded onClick"); };
```

### Show a Rewarded ad

Swift:

```swift
rewarded.show()
```

Objective-C:

```objc
[rewarded show];
```
