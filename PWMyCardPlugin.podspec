
Pod::Spec.new do |s|
  s.name         = "PWMyCardPlugin"
  s.version      = "3.0.0"
  s.summary      = "PWMyCardPlugin"
  s.description  = "Plugin for MyCard payment option for PWCoreSDK"
  s.homepage     = "http://paymentwall.com"
  s.author       = { "tien.vu" => "kyle.vu@paymentwall.com" }
  s.platform     = :ios
  s.ios.deployment_target = '8.0'
  s.license      = { :type => 'Apache 2.0', :file => 'LICENSE' }
  s.requires_arc = true

  s.source       = { :git => "https://github.com/paymentwall/paymentwall-ios-sdk-master.git", :tag => 'v'+String(s.version) }

  s.source_files = "Plugins/PWMyCardPlugin", "Plugins/PWMyCardPlugin/Headers/*.{h,m}"
  s.resources    = "Plugins/PWMyCardPlugin/PWMyCardPluginResource.bundle"

  s.vendored_libraries = "Plugins/PWMyCardPlugin/libPWMyCardPlugin.a"

  s.libraries = 'PWCoreSDK'

  s.dependency 'PWCoreSDK', '>= 3.0.0'

end
