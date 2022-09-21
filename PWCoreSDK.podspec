
Pod::Spec.new do |s|
  s.name         = "PWCoreSDK"
  s.version      = "3.1.2"
  s.summary      = "PWCoreSDK"
  s.description  = "Unified SDK for all paymentwall products on iOS"
  s.homepage     = "http://paymentwall.com"
  s.author       = { "tien.vu" => "kyle.vu@paymentwall.com" }
  s.platform     = :ios
  s.ios.deployment_target = '8.0'
  s.license      = { :type => 'Apache 2.0', :file => 'LICENSE' }
  s.requires_arc = true

  s.source       = { :git => "https://github.com/paymentwall/paymentwall-ios-sdk-master.git", :tag => "v"+String(s.version) }
  
  s.public_header_files = "Core SDK/**/PWCoreSDK.h"
  s.source_files = "Core SDK/**/PWCoreSDK.h"
  s.resources    = "Core SDK/*.bundle", "Core SDK/PWCoreSDKResource.bundle"
  s.vendored_libraries = "Core SDK/libPWCoreSDK.a"

  s.subspec 'CoreSDK' do |sp|
    sp.source_files = "Core SDK/**/*.{h,m}"
  end

  s.pod_target_xcconfig = {
    "OTHER_LDFLAGS" => "-lObjC"
  }
end
