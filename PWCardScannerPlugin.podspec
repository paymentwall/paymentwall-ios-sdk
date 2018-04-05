
Pod::Spec.new do |s|
  s.name         = "PWCardScannerPlugin"
  s.version      = "3.0.0"
  s.summary      = "PWCardScannerPlugin"
  s.description  = "Plugin to support credit card scanner for PWCoreSDK"
  s.homepage     = "http://paymentwall.com"
  s.author       = { "tien.vu" => "kyle.vu@paymentwall.com" }
  s.platform     = :ios
  s.ios.deployment_target = '8.0'
  s.license      = { :type => 'Apache 2.0', :file => 'LICENSE' }
  s.requires_arc = true

  s.source       = { :git => "https://github.com/paymentwall/paymentwall-ios-sdk-master.git", :tag => 'v'+String(s.version) }
  s.source_files = "Plugins/PWCardScannerPlugin", "Plugins/PWCardScannerPlugin/**/*.{h,m}"
  
  s.vendored_libraries = "Plugins/PWCardScannerPlugin/libPWCardScannerPlugin.a"

  s.dependency 'PWCoreSDK', '>= 3.0.0'
  s.dependency 'CardIO'

  s.libraries = 'PWCoreSDK', 'CardIO', 'opencv_core', 'opencv_imgproc'
end