# vim: set ft=ruby

Pod::Spec.new do |spec|
  spec.name         = 'HypeLabSdk'
  spec.version      = '1.0.0'
  spec.summary      = 'HypeLab SDK for iOS'
  spec.description  = 'Integrate HypeLab ads into your iOS app'
  spec.homepage     = 'https://github.com/gohypelab/hypelab-sdk-ios'
  spec.license      = { :type => 'MIT', :file => 'LICENSE' }
  spec.author       = 'HypeLab'
  spec.source       = { :git => 'https://github.com/gohypelab/hypelab-sdk-ios.git', :tag => spec.version.to_s }

  spec.ios.deployment_target  = '15.0'

  spec.vendored_frameworks = 'HypeLabSdk.xcframework'
end
