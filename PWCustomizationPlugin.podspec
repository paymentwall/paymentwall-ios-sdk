
Pod::Spec.new do |s|
  s.name         = "PWCustomizationPlugin"
  s.version      = "1.0.0"
  s.summary      = "PWCustomizationPlugin"
  s.description  = "Plugin for customize PWCoreSDK's flat UI"
  s.homepage     = "http://paymentwall.com"
  s.author       = { "tien.vu" => "kyle.vu@paymentwall.com" }
  s.platform     = :ios
  s.ios.deployment_target = '8.0'
  s.license      = { :type => 'Apache 2.0', :file => 'LICENSE' }

  s.source       = { :git => "https://github.com/paymentwall/paymentwall-ios-sdk-master.git", :tag => 'PWCustomizationPlugin-v'+String(s.version) }
  s.source_files = "Plugins/PWCustomizationPlugin", "Plugins/PWCustomizationPlugin/**/*.{h,m}"
  
  s.vendored_libraries = "Plugins/PWCustomizationPlugin/libPWCustomizationPlugin.a"

  s.dependency 'PWCoreSDK', '~> 1.2.0'
end