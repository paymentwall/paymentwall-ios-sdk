Pod::Spec.new do |s|
  s.name         = "PWGameUIPlugin"
  s.version      = "3.0.0"
  s.summary      = "PWGameUIPlugin"
  s.description  = "Resource for CoreSDK's game UI"
  s.homepage     = "http://paymentwall.com"
  s.author       = { "tien.vu" => "kyle.vu@paymentwall.com" }
  s.platform     = :ios
  s.ios.deployment_target = '8.0'
  s.license      = { :type => 'Apache 2.0', :file => 'LICENSE' }
  s.requires_arc = true

  s.source       = { :git => "https://github.com/paymentwall/paymentwall-ios-sdk-master.git", :tag => 'v'+String(s.version) }
  s.source_files = "Plugins/PWGameUIPlugin", "Plugins/PWGameUIPlugin/**/*.{h,m}"
  
  s.vendored_libraries = "Plugins/PWGameUIPlugin/libPWGameUIPlugin.a"
  s.resources    = "Plugins/PWGameUIPlugin/PWGameUIPluginResource.bundle"

  s.dependency 'PWCoreSDK', '>= 3.0.0'
end