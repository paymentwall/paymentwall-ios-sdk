//
//  PWAlipayPlugin.h
//  PaymentwallAlipaySDK
//
//  Created by Tien Nhat Vu on 10/11/16.
//  Copyright © 2016 Paymentwall. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface PWAlipayPlugin : NSObject

///Required
@property (nonatomic, strong) NSString* appId; //Required for domestic account, default for internation = external
@property (nonatomic, strong) NSString* appScheme; //To redirect back from Alipay app

//International account
@property (nonatomic, strong) NSString* itbPay; //Default: 30m
@property (nonatomic, strong) NSString* forexBiz; //Required for international account, default: FP
@property (nonatomic, strong) NSString* appenv; //"system=[client platform name]^version=[system version]" eg ”system=iOS^version=9”

///Optional
@property (nonatomic, strong) NSString* pwProjectKey; //If nil, use default key from PWCoreSDK
@property (nonatomic, strong) NSString* pwSecretKey; //If nil, use default key from PWCoreSDK, if both nil, assign `signString` property below before showing payment dialog

-(NSString * _Nullable)getStringToSign; //Call after you assign all required value AND setup PaymentObject in order to get string to sign. If you use this feature, you have to keep this class instance pointer to assign new signString everytime after new payment object is set
@property (nonatomic, strong) NSString* signString; //Use this property only if you want to calculate sign by your app or server

NS_ASSUME_NONNULL_END

@end

