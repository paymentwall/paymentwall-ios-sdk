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
/// value the PAYER TYPED, carried through so an integrator can use it (a receipt, a fraud signal,
/// their own record). It is the same thing the Android SDK hands back as
/// `CardToken(token, cardholder, email, fingerprint)`, which is why this exists at all: the two SDKs
/// gave their integrators different data from the same screen.
///
/// **Nil when the SDK's own UI did not collect it** — an integrator using their own UI package, the
/// stored-card path (the name was never asked for again), or any release before 4.0.
@property (nonatomic, nullable, readonly) NSString *cardholder;
@property (nonatomic, nullable, readonly) NSString *fingerprint;

@end

NS_ASSUME_NONNULL_END
