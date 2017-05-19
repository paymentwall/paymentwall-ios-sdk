
Pod::Spec.new do |s|
  s.name         = "PWCardScannerPlugin"
  s.version      = "1.0.1"
  s.summary      = "PWCardScannerPlugin"
  s.description  = "Plugin for Alipay payment option for PWCoreSDK"
  s.homepage     = "http://paymentwall.com"
  s.author       = { "tien.vu" => "kyle.vu@paymentwall.com" }
  s.platform     = :ios
  s.ios.deployment_target = '8.0'
  s.license      = { :type => 'Apache 2.0', :file => 'LICENSE' }

  s.source       = { :git => "https://github.com/paymentwall/paymentwall-ios-sdk-master.git", :tag => 'PWCardScannerPlugin-v'+String(s.version) }
  s.source_files = "Plugins/PWCardScannerPlugin", "Plugins/PWCardScannerPlugin/**/*.{h,m}"
  
  s.vendored_libraries = "Plugins/PWCardScannerPlugin/libPWCardScannerPlugin.a"

  s.dependency 'PWCoreSDK'
  s.dependency 'CardIO'

  s.libraries = 'PWCoreSDK', 'CardIO', 'opencv_core', 'opencv_imgproc'
end