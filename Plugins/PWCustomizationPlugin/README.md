Paymentwall Customization plugin
------------------------------
Customization Plugin is an optional plugin to add the feature that enable customization UI for the flat UI.

1. Add the plugin with Cocoapods with `pod 'PWCustomizationPlugin'` or manually dragging the `libPWCardScannerPlugin.a` and it's headers file to your project
2. Import the library header into your project or via `bridging-headers.h` if you use Swift
3. Add it while setting up CoreSDK:
```swift
let custom = PWCustomizationPlugin()
//Set properties for the plugin
PWCoreSDK.sharedInstance().setUseCustomization(custom)
```

Usage
------------------------------
- UIBarStyle barStyle: Change the status bar style

- NSDictionary* infoCardTextAttribute: You can set custom font and color of infoCard text with this property eg. item name and item value
- UIColor* infoCardBackgroundColor: Background color for the infoCard, default is 0xFFFFFF
- UIImage* infoCardImage: Replace the infoCard background with your own image, default is nil
- UIViewContentMode infoCardImageMode: Image content mode for infoCard background, default is UIViewContentModeScaleAspectFill

- UIColor* headerBackgroundColor: Change the header color, default is 0xFBBD30
- UIImage* headerBackgroundImage: Add image to the header view, default is nil
- UIViewContentMode headerBackgroundImageMode: Image content mode for header background, default is UIViewContentModeScaleAspectFill

- UIColor* optionTextColor: Set color for the text in option method background, does not affect cell, default is 0x000000
- UIColor* optionBackgroundColor: Background color for the whole view
- UIImage* optionBackgroundImage: Set image as background for the whole view, you can set alpha = 0 color for `headerBackgroundColor` to show whole image, default is nil
- UIViewContentMode optionBackgroundImageMode: Image content mode for view background image, default is UIViewContentModeScaleAspectFill

- UIButton* buttonConfig: Set custom UI property for this property to change some button to your liking, eg. backgroundColor, tintColor, titleColor, image
