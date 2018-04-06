
Pod::Spec.new do |s|
  s.name         = "PWWechatpayPlugin"
  s.version      = "3.0.0"
  s.summary      = "PWWechatpayPlugin"
  s.description  = "Plugin for Wechatpay payment option for PWCoreSDK"
  s.homepage     = "http://paymentwall.com"
  s.author       = { "tien.vu" => "kyle.vu@paymentwall.com" }
  s.platform     = :ios
  s.ios.deployment_target = '8.0'
  s.license      = { :type => 'Apache 2.0', :file => 'LICENSE' }
  s.requires_arc = true

  s.source       = { :git => "https://github.com/paymentwall/paymentwall-ios-sdk-master.git", :tag => 'v'+String(s.version) }

  s.source_files = "Plugins/PWWechatpayPlugin", "Plugins/PWWechatpayPlugin/Headers/*.{h,m}"
  s.resources    = "Plugins/PWWechatpayPlugin/PWWechatpayPluginResource.bundle"

  s.vendored_libraries = "Plugins/PWWechatpayPlugin/libPWWechatpayPlugin.a"

  s.libraries = 'PWCoreSDK' , 'WeChatSDK'

  s.dependency 'PWCoreSDK', '>= 3.0.0'

  s.subspec 'Wechatpay' do |sp|
    sp.source_files = "Plugins/PWWechatpayPlugin/Wechatpay/*.{h,m}"
    sp.vendored_libraries = "Plugins/PWWechatpayPlugin/Wechatpay/libWeChatSDK.a"
    sp.libraries = 'z', 'c++', 'sqlite3.0'
    sp.frameworks = 'UIKit', 'SystemConfiguration', 'Foundation', 'CoreTelephony', 'Security', 'CFNetwork'
  end

end
