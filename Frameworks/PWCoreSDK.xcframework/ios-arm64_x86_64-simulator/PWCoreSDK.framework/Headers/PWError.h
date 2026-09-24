//
//  PWError.h
//  PWCoreSDK
//
//  Created by Tien Nhat Vu on 2/21/18.
//  Copyright © 2018 Paymentwall. All rights reserved.
//

#import <Foundation/Foundation.h>

#pragma mark - Common Error
extern NSString *const PWErrorMessageKey;
extern NSString *const PWErrorType;
extern NSString *const PWErrorDomain;

extern NSString *const PWErrorUnknown;
extern NSString *const PWErrorDefault;
extern NSString *const PWErrorTimedOut;
extern NSString *const PWErrorMissingField;
extern NSString *const PWErrorInvalidSignVersion;

// Configuration failures. Reported through PWCoreSDK.configurationFailureHandler rather than the
// payment delegate, because they occur during set-up, before a payment delegate exists.
extern NSString *const PWErrorInvalidPaymentOption;
extern NSString *const PWErrorInvalidIdentifier;
extern NSString *const PWErrorInvalidUIPackage;
extern NSString *const PWErrorCustomizationUnsupported;
/// The currency is not a three-letter ISO 4217 code. Reported, not refused - the payment still goes
/// ahead. Worth checking for, because a malformed code does not fail loudly: the symbol lookup
/// answers "$" for "usd", "US" and "!!" alike, so a mis-set currency renders a DOLLAR SIGN over an
/// amount in some other currency.
extern NSString *const PWErrorInvalidCurrency;
/// The price carries more decimal places than the currency has minor units - JPY 100.5, say, which
/// is not an amount the yen can express. The sheet rounds it for display, so what the payer READS
/// and what the gateway CHARGES can differ by a minor unit.
extern NSString *const PWErrorAmountPrecision;
/// The wallet SDK your app links is not a version the plugin supports. The wallet plugins ship
/// headers only, so the library that gets linked is your choice; the SDK checks it once per process
/// and reports a mismatch here without blocking the payment. The supported version range for each
/// wallet is in the README.
extern NSString *const PWErrorVendorSDKVersion;

#pragma mark - Brick Error
extern NSString *const BRErrorMessageKey;
extern NSString *const BRErrorType;
extern NSString *const BRErrorDomain;

// Content
extern NSString *const BRError;
extern NSString *const BRErrorPublicKeyInvalid;

extern NSString *const BRErrorCardNumberContentNonNumber;
extern NSString *const BRErrorCardNumberInvalid;
extern NSString *const BRErrorCardNumberEmpty;

extern NSString *const BRErrorCardCVCContentNonNumber;
extern NSString *const BRErrorCardCVCEmpty;

extern NSString *const BRErrorCardExpireMonthNonNumber;
extern NSString *const BRErrorCardExpireMonthInvalid;
extern NSString *const BRErrorCardExpireMonthEmpty;

extern NSString *const BRErrorCardExpireYearNonNumber;
extern NSString *const BRErrorCardExpireYearInvalid;
extern NSString *const BRErrorCardExpireYearEmpty;

extern NSString *const BRErrorEmailEmpty;
extern NSString *const BRErrorEmailIsInvalid;

/// The risk review finished and the charge does NOT stand.
///
/// Reported to the merchant; it is not shown to the payer.
extern NSString *const BRErrorChargeDeclined;

extern NSString *const BRErrorNoInternet;
extern NSString *const BRErrorInvalid3DURL;

#pragma mark - Mint Error
extern NSString *const MIErrorInvalidEpin;

