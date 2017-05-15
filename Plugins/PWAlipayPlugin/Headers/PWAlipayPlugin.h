//
//  PWAlipayPlugin.h
//  PaymentwallAlipaySDK
//
//  Created by Tien Nhat Vu on 10/11/16.
//  Copyright © 2016 Paymentwall. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface PWAlipayPlugin : NSObject

//Optional
@property (nonatomic, strong) NSString* _Nullable pwProjectKey; //If nil, use default key from PWCoreSDK
@property (nonatomic, strong) NSString* _Nullable pwSecretKey; //If nil, use default key from PWCoreSDK, if both nil, assign `signString` property below before showing payment dialog
@property (nonatomic, assign) int signVersion; // 2 for MD5, 3 for SHA256

//Required
@property (nonatomic, strong) NSString* _Nonnull appId; //Required for domestic account, default for internation = external
@property (nonatomic, strong) NSString* _Nonnull appScheme; //To redirect back from Alipay app

//International account
@property (nonatomic, strong) NSString* _Nullable itbPay; //Default: 30m
@property (nonatomic, strong) NSString* _Nullable forexBiz; //Required for international account, default: FP
@property (nonatomic, strong) NSString* _Nullable appenv; //"system=[client platform name]^version=[system version]" eg ”system=iOS^version=9”

-(NSString * _Nonnull)getStringToSign; //Call after you assign all required value to get string to sign
@property (nonatomic, strong) NSString* _Nonnull signString; //Use this property only if you want to calculate sign by your app or server

@end
