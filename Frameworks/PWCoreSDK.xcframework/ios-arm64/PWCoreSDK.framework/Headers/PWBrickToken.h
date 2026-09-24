//
//  PWBrickToken.h
//  PWCoreSDK
//
//  Created by Tien Nhat Vu on 1/19/18.
//  Copyright © 2018 Paymentwall. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface PWBrickToken : NSObject

/// Send this with the charge as `reference_id` when it is non-nil.
///
/// It ties the charge to a 3-D Secure 2 session the SDK has already set up. Without it the gateway
/// cannot offer a native challenge for this payment.
@property (nonatomic, readonly, nullable) NSString *secureReferenceId;

/// Send this with the charge as `secure_token`.
///
/// Non-nil only on the **second** charge, after a native 3-D Secure challenge has authenticated the
/// payer. When the SDK reports a token carrying this, charge again.
///
/// ⚠️ DO NOT CONFUSE THESE WITH THE `brick_`-PREFIXED NAMES. On the web-view flow Paymentwall POSTs
/// `brick_secure_token` and `brick_charge_id` to your `secure_redirect_url`; those are the names it
/// sends TO you. The names to send back ON THE CHARGE are the unprefixed ones. A charge carrying
/// them is matched to the pending charge rather than starting a second authentication.
@property (nonatomic, readonly, nullable) NSString *secureToken;

/// Send this with the charge as `charge_id`, alongside `secureToken` on that second charge.
///
/// ⚠️ IT IS NOT THE CHARGE OBJECT'S `id`. It is the reference the 3-D Secure lookup produced, which
/// the gateway spells with a leading `d`; sending the charge's own id in this field does not match
/// the authentication to the charge.
@property (nonatomic, readonly, nullable) NSString *chargeId;

@property (nonatomic, readonly) NSString *type;
@property (nonatomic, readonly) NSString *token;
@property (nonatomic, readonly) NSInteger expiredIn;
@property (nonatomic, readonly) NSInteger active;
@property (nonatomic, readonly) NSString *cardType;
@property (nonatomic, readonly) NSString *cardLast4Pin;
@property (nonatomic, readonly) NSString *cardBin;
@property (nonatomic, readonly) NSString *cardExpMonth;
@property (nonatomic, readonly) NSString *cardExpYear;
@property (nonatomic, readonly) NSString *issuingCountry;
@property (nonatomic, nullable, readonly) NSString *email;

/// ⚠️ THE NAME ON THE CARD, and the ONE property here that does not come from the tokenization
/// response.
///
/// Paymentwall's token endpoint is not sent a cardholder name and does not return one; this is the
/// value the PAYER TYPED, carried through so you can use it — a receipt, a fraud signal, your own
/// record.
///
/// **Nil when the SDK's own UI did not collect it** — you supplied your own UI package, or the payer
/// used a stored card, where the name is not asked for again. Also nil in any release before 4.0.
@property (nonatomic, nullable, readonly) NSString *cardholder;
@property (nonatomic, nullable, readonly) NSString *fingerprint;

@end

NS_ASSUME_NONNULL_END
