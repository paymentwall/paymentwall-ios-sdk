INTRODUCTION
------------
Do you want to accept payments from mobile users in different countries, different payment system by writing just few of code lines?
Paymentwall SDK is a global mobile payment gateway that accepts payments from more than 200 countries with 100+ alternative payment options. We now provide SDK for iOS which will become a native part of your application, it eliminates the necessity to open a web browser for payments. Less steps, faster process, there’s no doubt your conversion rate will get boost! All you have to do is to import the library into your project and config it to start accepting in-app payment. It is quick and easy! We'll guide you through the process here.

HOW DOES IT WORK?
-----------------
1. Add the framework to your project.
With different areas, we provide corresponding external payment system framework files. You can add as many as you want. You can also enable/disable default payment options too. You can add any payment option as they want by importing the payment system framework and framework plugin provided by Paymentwall to your project
2. User requests a purchase inside your application.
3. Paymentwall SDK initializes payment screen with 3 core payment options (Brick, MINT, Mobiamo) and the other is “Local Payments” option.
4. User initiates payment in-app
With Brick, Mint, Mobiamo the payment process will totally be native.
With local payments, local payment screen will be shown with payment methods corresponding to user’s current location. Here users can then select a payment option they prefer.

REQUIREMENTS
------------
XCode 8.0+, iOS 8.0+

CREDENTIALS
-----------
SDK integration requires a project key. Obtain these Paymentwall API credentials in the application settings of your Merchant Account at [Paymentwall.com](http://paymentwall.com/)

Core SDK integration
------------------------------
- [Paymentwall iOS Core SDK integration instruction](https://github.com/paymentwall/paymentwall-ios-sdk/tree/master/Core%20SDK)

Available native payment option plugins
------------------------------
- [Alipay](https://github.com/paymentwall/paymentwall-ios-sdk/tree/master/Plugins/PWAlipayPlugin)
- [Wechatpay](https://github.com/paymentwall/paymentwall-ios-sdk/tree/master/Plugins/PWWechatpayPlugin)
- [MyCard](https://github.com/paymentwall/paymentwall-ios-sdk/tree/master/Plugins/PWMycardPlugin)

Available extra plugins
------------------------------
- [Card scanner](https://github.com/paymentwall/paymentwall-ios-sdk/tree/master/Plugins/PWCardScannerPlugin)
- [GameUI](https://github.com/paymentwall/paymentwall-ios-sdk/tree/master/Plugins/PWGameUIPlugin)
- [UI Customization](https://github.com/paymentwall/paymentwall-ios-sdk/tree/master/Plugins/PWCustomizationPlugin) (Deprecated)
