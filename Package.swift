// swift-tools-version:5.7

import PackageDescription

let package = Package(
  name: "HypeLabSdk",
  platforms: [.iOS(.v15)],
  products: [
    .library(name: "HypeLabSdk", targets: ["HypeLabSdk"])
  ],
  targets: [
    .binaryTarget(
      name: "HypeLabSdk",
      path: "HypeLabSdk.xcframework.zip")
  ]
)
