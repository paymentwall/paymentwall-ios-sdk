
Pod::Spec.new do |s|
  s.name         = "PWAlipayPlugin"
  s.version      = "1.0.1"
  s.summary      = "PWAlipayPlugin"
  s.description  = "Plugin for Alipay payment option for PWCoreSDK"
  s.homepage     = "http://paymentwall.com"
  s.author       = { "tien.vu" => "kyle.vu@paymentwall.com" }
  s.platform     = :ios
  s.ios.deployment_target = '8.0'

  s.source       = { :git => "https://github.com/paymentwall/ios-sdk-core", :tag => 'PWAlipayPlugin-v'+String(s.version) }
  s.source_files = "PWAlipayPlugin", "PWAlipayPlugin/**/*.{h,m}", "Headers/*.h"
  s.resources    = "PWAlipayPlugin/PWAlipayPlugin.bundle"
  s.vendored_libraries = "PWAlipayPlugin/libPWAlipayPlugin.a"
  s.dependency 'PWCoreSDK'

  s.subspec 'Headers' do |h|
    h.source_files = 'PWAlipayPlugin/Headers/*.{h,m}'
  end

end
