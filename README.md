# HypeLab SDK for iOS

HypeLab SDK for iOS lets app developers display HypeLab ads in iPhone and iPad apps. The SDK is distributed as a binary `XCFramework` and can be installed with Swift Package Manager or CocoaPods.

[![iOS](https://img.shields.io/badge/iOS-15.0%2B-0A84FF)](#requirements)
[![Swift Package Manager](https://img.shields.io/badge/SPM-supported-F05138)](#swift-package-manager)
[![CocoaPods](https://img.shields.io/badge/CocoaPods-supported-EE3322)](#cocoapods)
[![License](https://img.shields.io/badge/license-MIT-111111)](LICENSE)

## Overview

HypeLab provides an embeddable iOS ad SDK for apps that want to monetize with HypeLab demand. This repository is the public distribution point for the SDK binary and developer integration documentation.

The current SDK includes:

- Rewarded ad loading and presentation
- Swift and Objective-C integration support
- Device and simulator framework slices
- Swift Package Manager and CocoaPods distribution

## SKAdNetwork Participation

HypeLab is preparing to register as an Apple SKAdNetwork ad network participant. Apple requires ad networks to register before using SKAdNetwork attribution APIs, receive an ad network identifier, provide a public key, and configure an install-validation postback endpoint.

Once Apple issues HypeLab's ad network identifier, app developers who display HypeLab ads will add that lowercase identifier to their app's `Info.plist` under `SKAdNetworkItems`.

```xml
<key>SKAdNetworkItems</key>
<array>
  <dict>
    <key>SKAdNetworkIdentifier</key>
    <string>YOUR_HYPELAB_SKADNETWORK_ID.skadnetwork</string>
  </dict>
</array>
```

Do not ship the placeholder above. Replace it with the official HypeLab SKAdNetwork ID after registration is complete.

Developer responsibilities for SKAdNetwork-enabled integrations:

- Include HypeLab's issued SKAdNetwork identifier in the source app's `Info.plist`
- Use the current HypeLab SDK release from this repository
- Keep the identifier lowercase so iOS recognizes it

HypeLab ad network responsibilities:

- Maintain the Apple-issued ad network identifier
- Sign eligible ads with the registered private key
- Receive and validate SKAdNetwork install-validation postbacks
- Publish integration guidance for app developers

## Requirements

- iOS 15.0 or later
- Xcode 14 or later
- Swift Package Manager or CocoaPods

## Installation

### Swift Package Manager

In Xcode:

1. Open your app project.
2. Select **File > Add Package Dependencies**.
3. Enter this repository URL:

```text
https://github.com/gohypelab/hypelab-sdk-ios
```

4. Add the `HypeLabSdk` package to your app target.

### CocoaPods

Add `HypeLabSdk` to your `Podfile`:

```ruby
pod 'HypeLabSdk', '~> 1.0'
```

Then install the pod:

```sh
pod install
```

Open the generated `.xcworkspace` before building your app.

## Configure the SDK

Initialize HypeLab once during app startup before creating or showing ads.

### Swift

```swift
import HypeLabSdk

let config = Config(
  environment: "production",
  propertySlug: "your-property-slug"
)

HypeLab.initialize(config)
```

### Objective-C

```objc
#import <HypeLabSdk/Config.h>
#import <HypeLabSdk/HypeLab.h>

Config *config = [[Config alloc] initWithEnvironment:@"production"
                                        propertySlug:@"your-property-slug"];

[HypeLab initialize:config];
```

## Rewarded Ads

Create a rewarded placement with the placement slug provided by HypeLab, attach callbacks, then call `show()` when the ad is ready.

### Swift

```swift
import HypeLabSdk

let rewarded = Rewarded(placementSlug: "your-placement-slug")

rewarded.onReady = {
  print("Rewarded ad is ready")
}

rewarded.onReward = {
  print("Reward the user")
}

rewarded.onError = {
  print("Rewarded ad failed to load")
}

rewarded.onVideoStart = {
  print("Rewarded video started")
}

rewarded.onVideoComplete = {
  print("Rewarded video completed")
}

rewarded.onVideoError = {
  print("Rewarded video playback error")
}

rewarded.onImpression = {
  print("Rewarded impression recorded")
}

rewarded.onClick = {
  print("Rewarded ad clicked")
}
```

Show the ad:

```swift
rewarded.show()
```

### Objective-C

```objc
#import <HypeLabSdk/Rewarded.h>

Rewarded *rewarded = [[Rewarded alloc] initWithPlacementSlug:@"your-placement-slug"];

rewarded.onReady = ^{
  NSLog(@"Rewarded ad is ready");
};

rewarded.onReward = ^{
  NSLog(@"Reward the user");
};

rewarded.onError = ^{
  NSLog(@"Rewarded ad failed to load");
};

rewarded.onVideoStart = ^{
  NSLog(@"Rewarded video started");
};

rewarded.onVideoComplete = ^{
  NSLog(@"Rewarded video completed");
};

rewarded.onVideoError = ^{
  NSLog(@"Rewarded video playback error");
};

rewarded.onImpression = ^{
  NSLog(@"Rewarded impression recorded");
};

rewarded.onClick = ^{
  NSLog(@"Rewarded ad clicked");
};
```

Show the ad:

```objc
[rewarded show];
```

## Binary Distribution

This repository includes:

- `HypeLabSdk.xcframework` for CocoaPods consumers
- `HypeLabSdk.xcframework.zip` for Swift Package Manager consumers
- Public Objective-C headers for Swift and Objective-C interoperability

The framework contains both device and simulator builds:

- `ios-arm64`
- `ios-arm64_x86_64-simulator`

## Support

Open an issue in this repository for SDK packaging or integration problems. For HypeLab account setup, property slugs, placement slugs, or SKAdNetwork registration details, contact your HypeLab representative.

## License

This SDK distribution is available under the [MIT License](LICENSE).
