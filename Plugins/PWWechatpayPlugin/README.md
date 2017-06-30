Paymentwall Wechatpay plugin
------------------------------
Paymentwall SDK supports external payment system injection (which are in our defined payment system (PS) list). Each time you want to add a new payment system, you have to include it's native SDK into your project along with our plugin framework, our framework will handle creating all the necessary parameters then you can use them to show the native local payment SDK:

1. Add the plugin with Cocoapods with `pod 'PWWechatpayPlugin'` or manually dragging the `libPWWechatpayPlugin.a` and it's headers file to your project
2. Import the library header into your project in `bridging-headers.h` if you use Swift
3. Setup the plugin, each plugin have different requirements so please check their header files and local payment option docs on their websites for more information:
```swift
let wechatpay = PWWechatpayPlugin()

//Required
wechatpay.appId = "external"
wechatpay.appScheme = "YOUR APP SCHEME"

//Optional
wechatpay.pwProjectKey = "YOUR PROJECT KEY"
wechatpay.pwSecretKey = "YOUR SECRET KEY"
```
4. If secret key is not set in both PWCoreSDK and this plugin, you have to generate and provide `signString` for the Plugin:
```swift
//Get string to sign - call this after set all required values in step 3. and set PaymentObject in PWCoreSDK
let strToSign = wechatpay.getStringToSign()

//Append your secret key to the end and calculate, then set to `signString`, have to do it again with new PaymentObject
wechatpay.signString = calculateSign(with: strToSign)
```
5. Add to CoreSDK:
```swift
PWCoreSDK.sharedInstance().addCustomPaymentOptions([wechatpay])
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
Make sure `YOUR APP SCHEME` is Wechatpay App id on your ps settings.
