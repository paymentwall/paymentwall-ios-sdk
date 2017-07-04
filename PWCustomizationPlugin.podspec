
Pod::Spec.new do |s|
  s.name         = "PWCustomizationPlugin"
  s.version      = "2.0.0"
  s.summary      = "PWCustomizationPlugin"
  s.description  = "Plugin to customize PWCoreSDK's flat UI"
  s.homepage     = "http://paymentwall.com"
  s.author       = { "tien.vu" => "kyle.vu@paymentwall.com" }
  s.platform     = :ios
  s.ios.deployment_target = '8.0'
  s.license      = { :type => 'Apache 2.0', :file => 'LICENSE' }
  s.requires_arc = true

  s.source       = { :git => "https://github.com/paymentwall/paymentwall-ios-sdk-master.git", :tag => 'v'+String(s.version) }
  s.source_files = "Plugins/PWCustomizationPlugin", "Plugins/PWCustomizationPlugin/**/*.{h,m}"
  
  s.vendored_libraries = "Plugins/PWCustomizationPlugin/libPWCustomizationPlugin.a"

  s.dependency 'PWCoreSDK', '~> 2.0.0'
end