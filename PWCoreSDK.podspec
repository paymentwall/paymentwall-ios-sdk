
Pod::Spec.new do |s|
  s.name         = "PWCoreSDK"
  s.version      = "1.0.3"
  s.summary      = "PWCoreSDK"
  s.description  = "Unified SDK for all paymentwall products on iOS"
  s.homepage     = "http://paymentwall.com"
  s.author       = { "tien.vu" => "kyle.vu@paymentwall.com" }
  s.platform     = :ios
  s.ios.deployment_target = '8.0'
  s.license      = { :type => 'Apache 2.0', :file => 'LICENSE' }

  s.source       = { :git => "https://github.com/paymentwall/ios-sdk-core.git", :tag => 'PWCoreSDK-v'+String(s.version) }
  s.source_files = "PWCoreSDK", "PWCoreSDK/**/*.{h,m}", "Headers/*.h"
  s.resources    = "PWCoreSDK/PWCoreSDK.bundle"
  s.vendored_libraries = "PWCoreSDK/libPWCoreSDK.a"

end
