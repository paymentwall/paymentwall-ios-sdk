//
//  PWOptionWechatpay.h
//  PaymentwallWechatpaySDK
//
//  Created by Tien Nhat Vu on 10/19/16.
//  Copyright © 2016 Paymentwall. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PWConstants.h"

NS_ASSUME_NONNULL_BEGIN

extern NSString *const PWPaymentTypeWechatpay;

/**
 Required
 You have to add your Wechatpay App ID as your URL Schemes in order to capture redirect
 */
@interface PWOptionWechatpay : NSObject

///Required, must have "https://" scheme
@property(nonatomic, copy) NSString* universalLink;

///Optional
@property(nonatomic, copy, nullable) NSString* overrideProjectKey;
@property(nonatomic, copy, nullable) NSString* overrideSecretKey;
@property(nonatomic) PWSignatureType overrideSignVersion;

@end

NS_ASSUME_NONNULL_END
