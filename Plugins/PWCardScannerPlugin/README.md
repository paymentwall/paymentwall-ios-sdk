Paymentwall Card Scanner plugin
------------------------------
Card Scanner Plugin is an optional plugin to add the feature that use camera to scan the credit card, powered by [Card.IO](https://www.card.io/).

1. Add the plugin with Cocoapods with `pod 'PWCardScannerPlugin'` or manually dragging the `libPWCardScannerPlugin.a` and it's headers file to your project
2. If you use manually install, you must also include CardIO static libs and it's headers in the app
3. Import the library header into your project or via `bridging-headers.h` if you use Swift
4. Add it within brick payment method creation:
```swift
PWCoreSDK.sharedInstance().addBrickPayment(withPublicKey: nil, useNativeFinishDialog: true, cardScannerPlugin: PWCardScannerPlugin.sharedInstance())
```
