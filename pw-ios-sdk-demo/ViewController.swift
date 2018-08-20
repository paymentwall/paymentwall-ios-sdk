//
//  ViewController.swift
//  pw-ios-sdk-demo
//
//  Created by Tien Nhat Vu on 5/19/17.
//  Copyright © 2017 Paymentwall. All rights reserved.
//

import UIKit

class ViewController: UIViewController {

    @IBOutlet weak var resultLabel: UILabel!
    
    var brick: PWOptionBrick!
    var mint: PWOptionMint!
    var mobiamo: PWOptionMobiamo!
    var widget: PWOptionWidget!
    var alipay: PWOptionAlipay!
    var mycard: PWOptionMyCard!
    var wechatpay: PWOptionWechatpay!
    var options: [Any]!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view, typically from a nib.
        setupPaymentwall()
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    
    @IBAction func startPaymentsBtnTouch(_ sender: Any) {
        let paymentObject = setupPaymentObject()
        PWCoreSDK.sharedInstance().showPaymentVC(withParentVC: self, paymentObject: paymentObject, paymentOption: options, delegate: self)
    }
    
    ///Setup payment object
    func setupPaymentObject() -> PWPaymentObject {
        let payment = PWPaymentObject(name: "test",
                                      price: NSDecimalNumber(string: "0.99"),
                                      itemID: "testid",
                                      userID: "testuid",
                                      currency: "USD",
                                      image: #imageLiteral(resourceName: "item1"))
        return payment
    }
    
    ///Setup CoreSDK UI
    func setupUI() {
        let custom = PWCustomization()
        custom.headerBackgroundColor = UIColor.clear
        custom.barStyle = UIBarStyle.blackOpaque
        custom.commonBackgroundImage = #imageLiteral(resourceName: "optionBackground")
        custom.commonTextColor = UIColor.white
        custom.cellTextColor = UIColor.purple
        custom.cellBackgroundColor = UIColor.white
        
        let customButton = UIButton()
        customButton.tintColor = UIColor.purple
        customButton.backgroundColor = .purple
        custom.commonButtonConfig = customButton
//        PWCoreSDK.sharedInstance().setCustomizationForDefaultUI(custom)
//        PWCoreSDK.sharedInstance().setUIPackage(PWGameUIPlugin())
    }
    
    ///Setup CoreSDK payment systems
    func setupPaymentwall() {
        self.setupUI()
        
        PWCoreSDK.sharedInstance().setGlobalProjectKey("YOUR_PUBLIC_KEY")
        PWCoreSDK.sharedInstance().setGlobalSecretKey("YOUR_SECRET_KEY")
        
        brick = PWOptionBrick()
        brick.setCardScannerPlugin(PWCardScannerPlugin())
        
        mint = PWOptionMint()
        
        mobiamo = PWOptionMobiamo()
        mobiamo.useNoPrice = true
        
        let widgetFlex = PWWidgetDigitalGoodsFlexible()
        widgetFlex.widget = "m2_1"
        widgetFlex.ag_type = "fixed"
        widget = PWOptionWidget(type: PWWidgetType.digitalGoodsFlexible, extraParams: widgetFlex)
        
        mycard = PWOptionMyCard()
        
        wechatpay = PWOptionWechatpay()
        
        alipay = PWOptionAlipay()
        alipay.appId = "external" //International
        alipay.appScheme = "pwsdkdemo"
        //international alipay
        alipay.itbPay = "30m"
        alipay.forexBiz = "FP"
        alipay.appenv = "system=ios^version=\(UIDevice.current.systemVersion)"
        
        options = [brick, mint, mobiamo, widget, alipay, mycard, wechatpay]
    }
}

extension ViewController: PWCoreSDKDelegate {
    func paymentResponse(_ response: PWCoreSDKResponse) {
        
        var message = response.message ?? ""
        
        switch response.responseCode {
        case .successful:
            let alert = UIAlertView(title: "Congrats", message: "Payment successful", delegate: nil, cancelButtonTitle: "OK")
            alert.show()
            message = "Success"
        case .failed:
            break
        case .cancel:
            message = "Cancelled"
            break
        case .signatureRequiring:
            switch response.signatureAlgorithm {
            case .MD5:
                PWCoreSDK.sharedInstance().continuePayment(withSign: md5("\(response.stringToSign!)YOUR_SECRET_KEY"))
            case .SHA256:
                PWCoreSDK.sharedInstance().continuePayment(withSign: sha256("\(response.stringToSign!)YOUR_SECRET_KEY"))
            }
        case .merchantProcessing:
            /**
             
             Process the one-time token in your backend asynchronously
             After finish:
             - Success without asking to store card:
                brick.handleBackendChargeResult(true, chargeObject: nil, secureURL: nil, errorMessage: nil)
             - Success with asking to store card:
                brick.handleBackendChargeResult(true, chargeObject: chargedObjectDict, secureURL: nil, errorMessage: nil)
             - Error:
                brick.handleBackendChargeResult(false, chargeObject: nil, secureURL: nil, errorMessage: "some error")
             - 3D secure:
                brick.handleBackendChargeResult(false, chargeObject: nil, secureURL: url, errorMessage: nil)
             
             >After 3D secure, Paymentwall backend will report the 3DS result to your server, now you can make the charge again and print the result on the webView, the webView will catch the result JSON and close the webView:
                - {"success":1} will mark the result as success without asking to store user card.
                - Charge object JSON will mark the result as success and ask to store user card.
                - {"error": "error_message"} will mark the result as failed with the error message
             
             */
            if response.paymentType == PWPaymentTypeBrick {
                brick.handleBackendChargeResult(true, chargeObject: nil, secureURL: nil, errorMessage: nil)
            }
        }
        
        resultLabel.text = message
        print(message)
    }
}

extension ViewController {
    func sha256(_ string: String) -> String {
        guard let data = string.data(using: .utf8) else {
            return ""
        }
        var hash = [UInt8](repeating: 0,  count: Int(CC_SHA256_DIGEST_LENGTH))
        data.withUnsafeBytes {
            _ = CC_SHA256($0, CC_LONG(data.count), &hash)
        }
        let shaData = Data(bytes: hash)
        let sign = shaData.map { String(format: "%02hhx", $0) }.joined()
        return sign
    }
    
    func md5(_ string: String) -> String {
        guard let data = string.data(using: .utf8) else {
            return ""
        }
        var digestData = Data(count: Int(CC_MD5_DIGEST_LENGTH))
        
        _ = digestData.withUnsafeMutableBytes {digestBytes in
            data.withUnsafeBytes {messageBytes in
                CC_MD5(messageBytes, CC_LONG(data.count), digestBytes)
            }
        }
        return digestData.map { String(format: "%02hhx", $0) }.joined()
    }
}

