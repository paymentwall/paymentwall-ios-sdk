Paymentwall Mycard plugin
------------------------------
Paymentwall SDK supports external payment system injection (which are in our defined payment system (PS) list). Each time you want to add a new payment system, you have to include it's native SDK into your project along with our plugin framework, our framework will handle creating all the necessary parameters then you can use them to show the native local payment SDK:

1. Add the plugin with Cocoapods with `pod 'PWMyCardPlugin'` or manually dragging the `libPWMycardPlugin.a` and it's headers file to your project
2. Import the library header into your project in `bridging-headers.h` if you use Swift
3. Setup the plugin, each plugin have different requirements so please check their header files and local payment option docs on their websites for more information:
```swift
let mycard = PWOptionMyCard()

//Optional
mycard.overrideProjectKey = "YOUR PROJECT KEY"
mycard.overrideSecretKey = "YOUR SECRET KEY"
mycard.overrideSignVersion = .SHA256
```
4. If secret key is not set in both PWCoreSDK and this plugin, you will have to handle the `.signatureRequiring` in your `PWCoreSDKDelegate` callback
5. Add to CoreSDK:
```swift
options.append(mycard)
PWCoreSDK.sharedInstance().showPaymentVC(withParentVC: self, paymentObject: payment, paymentOption: options, delegate: self)
```
