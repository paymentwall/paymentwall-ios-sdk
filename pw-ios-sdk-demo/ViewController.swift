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
        setupPayment()
        PWCoreSDK.sharedInstance().showPaymentOptionsViewController(withParentViewcontroller: self, delegate: self, showCompletion: nil)
    }
    
    func setupPaymentwall() {
        self.setupUI()
        
        ///Setup CoreSDK payment systems
        PWCoreSDK.sharedInstance().setupPaymentwall(withProjectKey: "YOUR_PUBLIC_KEY", secretKey: "YOUR_SECRET_KEY", requestTimeout: 30, clearPaymentMethodsAfterFinish: false)
        
        PWCoreSDK.sharedInstance().addBrickPayment(withPublicKey: nil, useNativeFinishDialog: true, cardScannerPlugin: PWCardScannerPlugin.sharedInstance())
        PWCoreSDK.sharedInstance().addMintPayment(withAppID: nil)
        PWCoreSDK.sharedInstance().addMobiamoPayment(withAppID: nil, noPrice: true)
        PWCoreSDK.sharedInstance().addPWLocalPayment(with: .DIGITAL_GOODS_FLEXIBLE, secretKey: nil)
        
        //Setup CoreSDK plugins for native payment systems
        let alipayInternational = setupAlipayInternational()
        let wechatpay = setupWechatpay()
        let mycard = setupMYCard()
        
        PWCoreSDK.sharedInstance().addCustomPaymentOptions([alipayInternational,wechatpay, mycard])
    }
    
    func setupUI() {
        ///Setup CoreSDK UI
        PWCoreSDK.sharedInstance().setUseGameUI(false)
        PWCoreSDK.sharedInstance().setShowBrickFooter(true)
        
        let custom = PWCustomizationPlugin()
        custom.headerBackgroundColor = UIColor.red
        custom.barStyle = .black
        custom.infoCardTextAttribute = [NSFontAttributeName: UIFont(name: "HelveticaNeue-Light", size: 16)!, NSForegroundColorAttributeName: UIColor.purple]
        custom.optionTextColor = UIColor.green
        custom.optionBackgroundImageMode = .scaleAspectFill
        let customBtn = UIButton(type: .custom)
        customBtn.backgroundColor = UIColor.black
        customBtn.tintColor = UIColor.black
        custom.buttonConfig = customBtn
        PWCoreSDK.sharedInstance().setUseCustomization(custom)
    }
    
    func setupAlipayInternational() -> PWAlipayPlugin {
        let alipay = PWAlipayPlugin()
        alipay.appId = "external" //International
        alipay.appScheme = "pwsdkdemo"
        
        //international alipay
        alipay.itbPay = "30m"
        alipay.forexBiz = "FP"
        alipay.appenv = "system=ios^version=\(UIDevice.current.systemVersion)"
        
        return alipay
    }
    
    func setupWechatpay() -> PWWechatpayPlugin {
        let wechatpay = PWWechatpayPlugin()
        wechatpay.appScheme = "WECHATPAY_APPID"
        return wechatpay
    }
    
    func setupMYCard() -> PWMyCardPlugin {
        let mycard = PWMyCardPlugin()
        return mycard
    }
    
    func setupPayment() {
        ///Setup payment object
        let payment = PaymentObject()
        payment.name = "item"
        payment.price = 0.99
        payment.currency = "USD"
        payment.image = nil
        payment.userID = "testuser1"
        payment.itemID = "itemid1"
        payment.signVersion = 3
        var customSetting = ["widget":"m2_1",
                             "ag_type":"fixed"]
        //If using custom signing:
        //let strToSign = PWCoreSDK.sharedInstance().getStringToSign(customSetting, paymentObject: payment) //Call after setting all other value
        //customSetting["key"] = "YOUR_PUBLIC_KEY"
        //customSetting["sign"] = sha256(text: "\(strToSign!)YOUR_SECRET_KEY")
        payment.pwLocalParams = customSetting
        PWCoreSDK.sharedInstance().setPaymentObject(payment)
    }
}

extension ViewController: PWCoreSDKDelegate {
    func paymentResponse(_ response: PWCoreSDKResponse?) {
        guard let response = response else {
            return
        }
        
        print("\(self.statusMsg(type: response.paymentType, msg: response.message))")
        resultLabel.text = statusMsg(type: response.paymentType, msg: response.message)
        
        switch response.responseCode {
        case .SUCCESSFUL:
            let alert = UIAlertView(title: "Congrats", message: "Successfully payment", delegate: nil, cancelButtonTitle: "OK")
            alert.show()
            break
        case .FAILED:
            break
        case .CANCEL:
            break
        case .MERCHANT_PROCESSING:
            /*
            Process the one-time token in your backend asynchronous
            After finish:
            - Success without asking to store card: 
             NotificationCenter.default.post(name: Notification.Name(BRICK_TOKEN_PROCESSED_FINISH), object: nil, userInfo: nil)
            - Success with asking to store card:
             NotificationCenter.default.post(name: Notification.Name(BRICK_TOKEN_PROCESSED_FINISH), object: nil, userInfo: chargedObjectDict)
            - Error:
             NotificationCenter.default.post(name: Notification.Name(BRICK_TOKEN_PROCESSED_FINISH), object: nil, userInfo: ["error":"some error"])
            - 3D secure:
             NotificationCenter.default.post(name: Notification.Name(BRICK_TOKEN_PROCESSED_FINISH), object: nil, userInfo: ["secure":"3d secure URL string"])
            >After 3D secure, the SDK will redirect to your sever URL, response ["success":1] will be equal to success without asking to store card.
            */
            break
        }
    }
    
    func statusMsg(type: PaymentType, msg: String) -> String {
        switch type {
        case .NONE:
            return "\(msg)"
        case .MINT:
            return "Mint \(msg)"
        case .PWLOCAL:
            return "PWlocal \(msg)"
        case .BRICK:
            return "Brick \(msg)"
        case .MOBIAMO:
            return "Mobiamo \(msg)"
        case .OTHERS:
            return "Others \(msg)"
        }
    }
}

