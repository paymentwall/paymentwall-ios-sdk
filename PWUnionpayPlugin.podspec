
Pod::Spec.new do |s|
  s.name         = "PWUnionpayPlugin"
  s.version      = "1.0.0"
  s.summary      = "PWUnionpayPlugin"
  s.description  = "Plugin for Unionpay payment option for PWCoreSDK"
  s.homepage     = "http://paymentwall.com"
  s.author       = { "tien.vu" => "kyle.vu@paymentwall.com" }
  s.platform     = :ios
  s.ios.deployment_target = '8.0'

  s.source       = { :git => "https://github.com/paymentwall/ios-sdk-core", :tag => 'PWUnionpayPlugin-v'+String(s.version) }
  s.source_files = "PWUnionpayPlugin", "PWUnionpayPlugin/**/*.{h,m}", "Headers/*.h"
  s.resources    = "PWUnionpayPlugin/PWUnionpayPlugin.bundle"
  s.vendored_libraries = "PWUnionpayPlugin/libPWUnionpayPlugin.a"
  s.dependency 'PWCoreSDK'

end
