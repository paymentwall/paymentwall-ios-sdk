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
/// **Published, not configurable:** the same value is recognised on every Paymentwall SDK.
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
    /// succeeded.
    PWPaymentResponseCodeUnknown,
    /// The charge was TAKEN but is being reviewed for fraud, and the review had not finished.
    ///
    /// Paymentwall answers such a charge with `captured: true` and `risk: "pending"`. The SDK polls
    /// the charge while its own screen is on display and reports `PWPaymentResponseCodeSuccessful`
    /// or `PWPaymentResponseCodeFailed` once the review finishes. This code is what you get when it
    /// does NOT finish on the device: the payer left the screen, or the SDK has no secret key and so
    /// cannot poll at all.
    ///
    /// **This is not a success and not a failure — do not ship goods on it.** The outcome arrives
    /// at your server through Paymentwall's pingback, which is the authority.
    ///
    /// **New in 4.1.0**, so a `switch` written against an earlier release does not handle it. It is
    /// added at the END of this enumeration, so every existing case keeps its raw value.
    PWPaymentResponseCodePending
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
