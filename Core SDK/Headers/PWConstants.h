//
//  Constants.h
//  PWCoreSDK
//
//  Created by Tien Nhat Vu on 1/19/18.
//  Copyright © 2018 Paymentwall. All rights reserved.
//

#import <Foundation/Foundation.h>

#ifndef PWConstants_h
#define PWConstants_h

/**
 PaymentType
 */
extern NSString * const PWPaymentTypeMint;
extern NSString * const PWPaymentTypeWidget;
extern NSString * const PWPaymentTypeBrick;
extern NSString * const PWPaymentTypeMobiamo;
extern NSString * const PWPaymentTypeNone;

/**
 PaymentResponseCode
 */
typedef NS_ENUM(NSUInteger, PWPaymentResponseCode) {
    PWPaymentResponseCodeSuccessful,
    PWPaymentResponseCodeFailed,
    PWPaymentResponseCodeCancel,
    PWPaymentResponseCodeMerchantProcessing,
    PWPaymentResponseCodeSignatureRequiring
};

/**
 PWLocal API types
 */
typedef NS_ENUM(NSUInteger, PWWidgetType) {
    PWWidgetTypeVirtualCurrency,
    PWWidgetTypeDigitalGoodsFlexible,
    PWWidgetTypeDigitalGoodsDefault,
    PWWidgetTypeCart
};

typedef NS_ENUM(NSUInteger, PWSignatureType) {
    PWSignatureTypeMD5 = 2,
    PWSignatureTypeSHA256 = 3
};

#endif /* Constants_h */
