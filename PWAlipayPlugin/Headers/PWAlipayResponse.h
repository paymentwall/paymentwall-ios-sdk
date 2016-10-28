//
//  PWAlipayResponse.h
//  PaymentwallAlipaySDK
//
//  Created by Tien Nhat Vu on 10/18/16.
//  Copyright © 2016 Paymentwall. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef enum {
    PWALIPAY_SUCCESSFUL = 0,
    PWALIPAY_FAILED = 1,
    PWALIPAY_CANCEL = 2
} PWAlipayResponseCode;

extern NSString *const _Nonnull PWALIPAY_CANCEL_PAYMENT;
extern NSString *const _Nonnull PWALIPAY_DEFAULT_ERROR;
extern NSString *const _Nonnull PWALIPAY_MISSING_PARAMS;

@interface PWAlipayResponse : NSObject

@property (nonatomic, assign) int responseCode;
@property (nonatomic, strong) NSString *_Nonnull paymentName;
@property (nonatomic, strong) NSString *_Nonnull paymentAmount;
@property (nonatomic, strong) NSString *_Nonnull paymentCurrency;
@property (nonatomic, strong) NSString *_Nonnull userID;
@property (nonatomic, strong) NSString *_Nullable message;
@property (nonatomic, strong) NSString *_Nullable alipayOrderString;

@end
