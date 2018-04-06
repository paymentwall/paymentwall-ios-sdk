Paymentwall Wechatpay plugin
------------------------------
Paymentwall SDK supports external payment system injection (which are in our defined payment system (PS) list). Each time you want to add a new payment system, you have to include it's native SDK into your project along with our plugin framework, our framework will handle creating all the necessary parameters then you can use them to show the native local payment SDK:

1. Add the plugin with Cocoapods with `pod 'PWWechatpayPlugin'` or manually dragging the `libPWWechatpayPlugin.a` and it's headers file to your project
2. Import the library header into your project in `bridging-headers.h` if you use Swift
3. Setup the plugin, each plugin have different requirements so please check their header files and local payment option docs on their websites for more information:
```swift
let wechatpay = PWOptionWechatpay()

//Optional
wechatpay.overrideProjectKey = "YOUR PROJECT KEY"
wechatpay.overrideSecretKey = "YOUR SECRET KEY"
wechatpay.overrideSignVersion = .SHA256
```
4. If secret key is not set in both PWCoreSDK and this plugin, you will have to handle the `.signatureRequiring` in your `PWCoreSDKDelegate` callback
5. Add to CoreSDK:
```swift
options.append(wechatpay)
PWCoreSDK.sharedInstance().showPaymentVC(withParentVC: self, paymentObject: payment, paymentOption: options, delegate: self)
```
6. App scheme is required in `info.plist`:
```xml
<key>CFBundleURLTypes</key>
<array>
    <dict>
    <key>CFBundleTypeRole</key>
    <string>Editor</string>
    <key>CFBundleURLName</key>
    <string></string>
    <key>CFBundleURLSchemes</key>
        <array>
            <string>YOUR APP SCHEME</string>
        </array>
    </dict>
</array>
```
7. Linking to Wechatpay app is required in `info.plist` in iOS 9.0 and above:
```xml
<key>LSApplicationQueriesSchemes</key>
<array>
    <string>weixin</string>
</array>
```

## Important
Make sure `YOUR APP SCHEME` is Wechatpay App id on your ps settings, not the app scheme you use to call your app.
