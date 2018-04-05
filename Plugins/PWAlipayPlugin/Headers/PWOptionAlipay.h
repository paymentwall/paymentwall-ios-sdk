//
//  PWOptionAlipay.h
//  PWAlipayPlugin
//
//  Created by Tien Nhat Vu on 3/22/18.
//  Copyright © 2018 Paymentwall. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PWConstants.h"

NS_ASSUME_NONNULL_BEGIN

extern NSString *const PWPaymentTypeAlipay;

@interface PWOptionAlipay : NSObject

///Required
@property (nonatomic, copy) NSString* appId; //Required for domestic account, default for internation = external
@property (nonatomic, copy) NSString* appScheme; //To redirect back from Alipay app

//International account
@property (nonatomic, copy) NSString* itbPay; //Default: 30m
@property (nonatomic, copy) NSString* forexBiz; //Required for international account, default: FP
@property (nonatomic, copy) NSString* appenv; //"system=[client platform name]^version=[system version]" eg ”system=iOS^version=9”

///Optional
@property(nonatomic, copy, nullable) NSString* overrideProjectKey;
@property(nonatomic, copy, nullable) NSString* overrideSecretKey;
@property(nonatomic) PWSignatureType overrideSignVersion;

@end

NS_ASSUME_NONNULL_END
