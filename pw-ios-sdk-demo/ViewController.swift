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
    
    func setupPaymentObject() -> PWPaymentObject {
        ///Setup payment object
        let payment = PWPaymentObject()
        payment.currency = "USD"
        payment.price = NSDecimalNumber(string: "0.99")
        payment.userID = "testuid"
        payment.itemID = "testid"
        payment.name = "test"
        return payment
    }
    
    func setupUI() {
        ///Setup CoreSDK UI
        let custom = PWCustomization()
        custom.headerBackgroundColor = UIColor.green
        custom.infoTextFont = UIFont(name: "Times New Roman", size: 16)
        custom.cellTextFont = UIFont(name: "Times New Roman", size: 16)
        custom.barStyle = UIBarStyle.black
        custom.commonTextColor = UIColor.red
        custom.cellTextColor = UIColor.purple
        custom.loaderExtraMessageTextColor = UIColor.green
        PWCoreSDK.sharedInstance().setCustomizationForDefaultUI(custom)
        //        PWCoreSDK.sharedInstance().setUIPackage(PWGameUIPlugin())
    }
    
    func setupPaymentwall() {
        self.setupUI()
        
        ///Setup CoreSDK payment systems
//        PWCoreSDK.sharedInstance().setGlobalProjectKey("YOUR_PUBLIC_KEY")
//        PWCoreSDK.sharedInstance().setGlobalSecretKey("YOUR_SECRET_KEY")
        PWCoreSDK.sharedInstance().setGlobalProjectKey("f29e7441a54debd44f903a2b7c40b15d")
//        PWCoreSDK.sharedInstance().setGlobalSecretKey("dec31fb340f14b63b42f458431e12d12")
        
        brick = PWOptionBrick()
        brick.overrideProjectKey = "t_d13a62cafbfc534efdecef3b7b63c0"
        brick.setCardScannerPlugin(PWCardScannerPlugin())
        
        mint = PWOptionMint()
        
        mobiamo = PWOptionMobiamo()
        
        let widgetFlex = PWWidgetDigitalGoodsFlexible()
        widgetFlex.widget = "m2_1"
        widgetFlex.ag_type = "fixed"
        widgetFlex.success_url = "https://google.com"
        widget = PWOptionWidget(type: PWWidgetType.digitalGoodsFlexible, extraParams: widgetFlex)
        widget.overrideProjectKey = "dea07cfb5300badc9b002009facad651"
        widget.overrideSecretKey = "dec31fb340f14b63b42f458431e12d12"
        
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
                PWCoreSDK.sharedInstance().continuePayment(withSign: md5("\(response.stringToSign!)d283a4f7768976b2f1511e56ee3e1700"))
            case .SHA256:
                PWCoreSDK.sharedInstance().continuePayment(withSign: sha256("\(response.stringToSign!)d283a4f7768976b2f1511e56ee3e1700"))
            }
        case .merchantProcessing:
            /*
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
             >After 3D secure, the SDK will redirect to your sever URL, response ["success":1] will be equal to success without asking to store card.
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

