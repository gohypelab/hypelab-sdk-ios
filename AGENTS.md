# Repository Guidelines

## Project Structure

- This repository distributes the closed-source `HypeLabSdk` iOS binary as an `HypeLabSdk.xcframework`.
- `Package.swift` exposes the SDK through Swift Package Manager as a binary target backed by `HypeLabSdk.xcframework.zip`.
- `HypeLabSdk.podspec` exposes the same SDK through CocoaPods using the unzipped `HypeLabSdk.xcframework`.
- `README.md` documents installation and basic Swift/Objective-C usage.

## Editing Guidance

- Treat files under `HypeLabSdk.xcframework/` and `HypeLabSdk.xcframework.zip` as release artifacts. Do not modify them unless the task is explicitly about updating the shipped binary.
- Keep SPM and CocoaPods metadata aligned when changing versioning, deployment target, product name, or framework paths.
- Preserve the current minimum iOS target unless the task explicitly changes support policy.
- README examples should stay valid for both Swift and Objective-C consumers when API-facing behavior changes.

## Validation

- For manifest changes, run `swift package describe` from the repository root when available.
- For podspec changes, run `pod spec lint HypeLabSdk.podspec --allow-warnings` when CocoaPods is available and network access is permitted.
- For binary framework updates, verify both device and simulator slices are present in `HypeLabSdk.xcframework/Info.plist`, then regenerate or replace `HypeLabSdk.xcframework.zip` consistently with the framework contents.

## Local Tooling

- Prefer `rg`/`rg --files` for repository searches.
- RTK is available for token-saving command summaries. Use raw commands when exact output matters; use `rtk <cmd>` when large output would benefit from summarization.
