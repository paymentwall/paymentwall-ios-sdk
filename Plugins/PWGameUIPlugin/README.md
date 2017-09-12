Paymentwall GameUI plugin
------------------------------
Paymentwall SDK supports external payment system injection (which are in our defined payment system (PS) list). Each time you want to add a new payment system, you have to include it's native SDK into your project along with our plugin framework, our framework will handle creating all the necessary parameters then you can use them to show the native local payment SDK:

1. Add the plugin with Cocoapods with `pod 'PWGameUIPlugin'` or manually dragging the `libPWGameUIPlugin.a` and it's headers file to your project
2. Import the library header into your project in `bridging-headers.h` if you use Swift
3. To use the resource package, add this line while setting up the CoreSDK:
```swift
PWCoreSDK.sharedInstance().setUIPackage(PWGameUIPlugin())
```
