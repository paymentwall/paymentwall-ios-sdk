//
//  Payment.swift
//  PaymentwallSDKDemo
//
//  Created by Tien Nhat Vu on 10/26/16.
//  Copyright © 2016 Paymentwall. All rights reserved.
//

import Foundation
import AVFoundation

extension ItemViewController {
    
    func setupPaymentwall() {
        
        PWCoreSDK.setPaymentName(choosenItem.name, paymentAmount: choosenItem.price, paymentCurrency: "USD", paymentImage: choosenItem.image, useNativeFinishDialog: true, requestTimeout: 30)
        
        //Brick : Public key is required, refer below to handling token returned
        PWCoreSDK.createNewBrickPayment(withPublicKey: "t_b60ab18be12e884f6462946377d59d")
        
        //PWLocal : Refer to Docs or header files for required params
        let customSetting = ["ag_type": "fixed", "currencyCode": "USD", "widget": "fp", "amount": "2.99", "sign_version": "3", "key": "7e43822b844fd872abacf67a92fb826c", "uid": "755##qb##2##qb##1", "ag_name": "BASIC", "ag_external_id": "testitem004"]
        PWCoreSDK.createNewPWLocalCustomPayment(withSecretKey: "af022feeb89f61d036da526213634746", apiType: DIGITAL_GOODS, customRequestDic: customSetting)
        //OR any of default class
        //        let digitalGoodsFlexibleWidget = DigitalGoodsFlexibleWidget()
        //        digitalGoodsFlexibleWidget.currencyCode = "USD"
        //        digitalGoodsFlexibleWidget.widget = "m2_1"
        //        digitalGoodsFlexibleWidget.key = "PUBLIC KEY"
        //        digitalGoodsFlexibleWidget.sign_version = "3"
        //        digitalGoodsFlexibleWidget.ag_external_id = "testitem004"
        //        digitalGoodsFlexibleWidget.ag_name = "testitem004"
        //        digitalGoodsFlexibleWidget.uid = "testuser2"
        //        digitalGoodsFlexibleWidget.amount = "0.5"
        //        digitalGoodsFlexibleWidget.ag_type = "fixed"
        //        digitalGoodsFlexibleWidget.evaluation = "1"
        //        digitalGoodsFlexibleWidget.success_url = "http://example.com"
        //        PWCoreSDK.createNewPWLocalDigitalGoodsFlexibleWidgetPayment(withSecretKey: "SECRET KEY", digitalGoodsFlexibleWidget: digitalGoodsFlexibleWidget)
    
        PWCoreSDK.showPaymentOptionsViewController(withParentViewcontroller: self, delegate: self, showCompletion: nil)
    }
}

extension ItemViewController: PWCoreSDKDelegate {
    func paymentResponse(_ response: PWCoreSDKResponse?) {
        guard let response = response else {
            return
        }
        
        print("\(self.statusMsg(type: response.paymentType, msg: response.message))")
        
        switch response.responseCode {
        case .SUCCESSFUL:
            if response.paymentType == .BRICK {
                
                if let returnedToken = response.token {
                    print("token \(returnedToken.token)");
                    
                    //Process payment with token
                    
                    //Call after process token if useNativeFinishDialog == true, THIS IS ONLY FOR SHOWING AFTER PROCESS THE TOKEN, other error will be handle automatically without posting notification
                    //If error happen, pass error Dictionary like below to userInfo, SDK will change success processed to failed
                    DispatchQueue.main.asyncAfter(deadline: .now() + 1) {
                        //let error = ["error":"some error"]
                        NotificationCenter.default.post(name: Notification.Name(BRICK_TOKEN_PROCESSED_FINISH), object: nil, userInfo: nil)
                    }
                }
            }
            break
        case .FAILED:
            break
        case .CANCEL:
            break
        }
    }
    
    func statusMsg(type: PaymentType, msg: String) -> String {
        switch type {
        case .NONE:
            return "None \(msg)"
        case .MINT:
            return "Mint \(msg)"
        case .PWLOCAL:
            return "PWlocal \(msg)"
        case .BRICK:
            return "Brick \(msg)"
        case .MOBIAMO:
            return "Mobiamo \(msg)"
        }
        
    }
    
    //Check PWLocal payment status
    func checkPaymentStatus() {
        PWLocalSDK.checkPaymentStatus(withKey: "7e43822b844fd872abacf67a92fb826c", agExternalId: "testitem004", uid: "testuser2", signVersion: 3, andSecretKey: "af022feeb89f61d036da526213634746", completion: {(response) -> Void in
            
            guard let response = response else {
                return
            }
            
            if response.code == .PWLOCAL_STAUTS_SUCCESSFUL {
                if response.dataResponse.count > 0 {
                    let paymentStatus = response.dataResponse.first!
                    print("paymentStatus \(paymentStatus)")
                }
                else {
                    print("No object")
                }
            }
            else {
                print("\(response.message)")
            }
        })
    }
}
