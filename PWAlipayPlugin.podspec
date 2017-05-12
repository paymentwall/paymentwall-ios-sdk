
Pod::Spec.new do |s|
  s.name         = "PWAlipayPlugin"
  s.version      = “1.0.4”
  s.summary      = "PWAlipayPlugin"
  s.description  = "Plugin for Alipay payment option for PWCoreSDK"
  s.homepage     = "http://paymentwall.com"
  s.author       = { "tien.vu" => "kyle.vu@paymentwall.com" }
  s.platform     = :ios
  s.ios.deployment_target = '8.0'
  s.license      = { :type => 'Apache 2.0', :file => 'LICENSE' }

  s.source       = { :git => "https://github.com/paymentwall/ios-sdk-core.git", :tag => 'PWAlipayPlugin-v'+String(s.version) }
  s.source_files = “Plugins/PWAlipayPlugin", "Plugins/PWAlipayPlugin/**/*.{h,m}"
  s.resources    = "Plugins/PWAlipayPlugin/PWAlipayPlugin.bundle"
  s.vendored_libraries = "Plugins/PWAlipayPlugin/libPWAlipayPlugin.a"
  s.dependency 'PWCoreSDK'

end
