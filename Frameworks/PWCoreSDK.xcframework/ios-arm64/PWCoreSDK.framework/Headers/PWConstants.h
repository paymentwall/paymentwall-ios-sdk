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
extern NSString * const PWPaymentTypeNone;

/// The URL the SDK's own web views treat as "the page asked to close".
///
/// A page rendered inside the SDK signals that it is finished by navigating to this URL, or by
/// calling `window.close`. Compare against this constant rather than hard-coding the string.
///
/// **Published, not configurable:** the value is shared with the Android SDK, so both platforms
/// recognise the same signal.
extern NSString * const PWWebViewCloseSignalURL;

/**
 PaymentResponseCode
 */
typedef NS_ENUM(NSUInteger, PWPaymentResponseCode) {
    PWPaymentResponseCodeSuccessful,
    PWPaymentResponseCodeFailed,
    PWPaymentResponseCodeCancel,
    PWPaymentResponseCodeMerchantProcessing,
    PWPaymentResponseCodeSignatureRequiring,
    /// The payment's outcome is NOT KNOWN.
    ///
    /// Reported when the SDK loses the page mid-payment — a web view navigation failure — so the
    /// charge may or may not have been authorised server-side.
    ///
    /// **Reconcile server-side before shipping goods, and do not treat this as a failure.**
    /// Refunding or refusing to ship on this code alone risks acting on a payment that actually
    /// succeeded. Before 2.0 this case did not exist and these payments reported
    /// `PWPaymentResponseCodeFailed`.
    PWPaymentResponseCodeUnknown
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
