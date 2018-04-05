
Pod::Spec.new do |s|
  s.name         = "PWAlipayPlugin"
  s.version      = "3.0.0"
  s.summary      = "PWAlipayPlugin"
  s.description  = "Plugin for Alipay payment option for PWCoreSDK"
  s.homepage     = "http://paymentwall.com"
  s.author       = { "tien.vu" => "kyle.vu@paymentwall.com" }
  s.platform     = :ios
  s.ios.deployment_target = '8.0'
  s.license      = { :type => 'Apache 2.0', :file => 'LICENSE' }
  s.requires_arc = true

  s.source       = { :git => "https://github.com/paymentwall/paymentwall-ios-sdk-master.git", :tag => 'v'+String(s.version) }
  s.source_files = "Plugins/PWAlipayPlugin", "Plugins/PWAlipayPlugin/Headers/*.{h,m}"
  s.resources    = "Plugins/PWAlipayPlugin/PWAlipayPluginResource.bundle"

  s.vendored_libraries = "Plugins/PWAlipayPlugin/libPWAlipayPlugin.a"

  s.libraries = 'PWCoreSDK'
  s.frameworks = 'AlipaySDK'

  s.dependency 'PWCoreSDK', '>= 3.0.0'

  s.subspec 'Alipay' do |sp|
    sp.vendored_frameworks = "Plugins/PWAlipayPlugin/AlipaySDK.framework"
    sp.libraries = 'z', 'c++'
    sp.resources = "Plugins/PWAlipayPlugin/AlipaySDK.bundle"
    sp.frameworks = 'UIKit', 'CFNetwork', 'CoreGraphics', 'SystemConfiguration', 'Foundation', 'CoreMotion', 'CFNetwork', 'QuartzCore', 'CoreText', 'CoreTelephony'
  end

end
