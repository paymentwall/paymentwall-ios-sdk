//
//  PWUnionpayResponse.h
//  PaymentwallUnionpaySDK
//
//  Created by Tien Nhat Vu on 10/19/16.
//  Copyright © 2016 Paymentwall. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "UnionpayOrder.h"

typedef enum {
    PWUNIONPAY_SUCCESSFUL = 0,
    PWUNIONPAY_FAILED = 1,
    PWUNIONPAY_CANCEL = 2
} PWAlipayResponseCode;

extern NSString *const _Nonnull PWUNIONPAY_CANCEL_PAYMENT;
extern NSString *const _Nonnull PWUNIONPAY_DEFAULT_ERROR;
extern NSString *const _Nonnull PWUNIONPAY_MISSING_PARAMS;

@interface PWUnionpayResponse : NSObject

@property (nonatomic, assign) int responseCode;
@property (nonatomic, strong) NSString *_Nonnull paymentName;
@property (nonatomic, strong) NSString *_Nonnull paymentAmount;
@property (nonatomic, strong) NSString *_Nonnull paymentCurrency;
@property (nonatomic, strong) NSString *_Nonnull userID;
@property (nonatomic, strong) NSString *_Nullable message;
@property (nonatomic, strong) UnionpayOrder * _Nullable order;


@end
