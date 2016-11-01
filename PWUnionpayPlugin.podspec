
Pod::Spec.new do |s|
  s.name         = "PWUnionpayPlugin"
  s.version      = "1.0.3"
  s.summary      = "PWUnionpayPlugin"
  s.description  = "Plugin for Unionpay payment option for PWCoreSDK"
  s.homepage     = "http://paymentwall.com"
  s.author       = { "tien.vu" => "kyle.vu@paymentwall.com" }
  s.platform     = :ios
  s.ios.deployment_target = '8.0'
  s.license      = { :type => 'Apache 2.0', :file => 'LICENSE' }

  s.source       = { :git => "https://github.com/paymentwall/ios-sdk-core.git", :tag => 'PWUnionpayPlugin-v'+String(s.version) }
  s.source_files = "PWUnionpayPlugin", "PWUnionpayPlugin/**/*.{h,m}", "PWUnionpayPlugin/Headers/*.h"
  s.resources    = "PWUnionpayPlugin/PWUnionpayPlugin.bundle"
  s.vendored_libraries = "PWUnionpayPlugin/libPWUnionpayPlugin.a"
  s.dependency 'PWCoreSDK'

end
