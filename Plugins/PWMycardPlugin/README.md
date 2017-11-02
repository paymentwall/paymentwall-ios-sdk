Paymentwall Mycard plugin
------------------------------
Paymentwall SDK supports external payment system injection (which are in our defined payment system (PS) list). Each time you want to add a new payment system, you have to include it's native SDK into your project along with our plugin framework, our framework will handle creating all the necessary parameters then you can use them to show the native local payment SDK:

1. Add the plugin with Cocoapods with `pod 'PWMyCardPlugin'` or manually dragging the `libPWMycardPlugin.a` and it's headers file to your project
2. Import the library header into your project in `bridging-headers.h` if you use Swift
3. Setup the plugin, each plugin have different requirements so please check their header files and local payment option docs on their websites for more information:
```swift
let mycard = PWMyCardPlugin()

//Optional
mycard.pwProjectKey = "YOUR PROJECT KEY"
mycard.pwSecretKey = "YOUR SECRET KEY"
```
4. If secret key is not set in both PWCoreSDK and this plugin, you have to generate and provide `signString` for the Plugin:
```swift
//Get string to sign - call this after set all required values in step 3. and set PaymentObject in PWCoreSDK
let strToSign = mycard.getStringToSign()

//Append your secret key to the end and calculate, then set to `signString`, have to do it again with new PaymentObject
mycard.signString = calculateSign(with: strToSign)
```
5. Add to CoreSDK:
```swift
PWCoreSDK.sharedInstance().addCustomPaymentOptions([mycard])
```
6. This plugin required signing again after user enter MyCard information, this step will be required if you did step 4., the string to sign will be return to you by the delegate with responseCode `MERCHANT_PROCESSING`:
```swift
    switch response.responseCode {
        case .MERCHANT_PROCESSING:
            if response.paymentType == .OTHERS {
                if let othersDict = response.others {
                    if let mycardStringToSign = othersDict["MyCard"] {
                        let signString = sha256(text: "\(mycardStringToSign)d283a4f7768976b2f1511e56ee3e1700")!
                        //If success
                        NotificationCenter.default.post(name: Notification.Name(MYCARD_SIGNATURE_GENERATED), object: nil, userInfo: ["signString": signString])
                        //If failed
                        //NotificationCenter.default.post(name: Notification.Name(MYCARD_SIGNATURE_GENERATED), object: nil, userInfo: ["error": "some error"])
                    }
                }
            }
        }
```
>Note: `key` will be the display name of the payment option, `val` will be the string to sign, after sign it with your app or server, post the notification named `MYCARD_SIGNATURE_GENERATED` with the signed string in Dictionary with key = "signString", or error message in Dictionary with key = "error"
