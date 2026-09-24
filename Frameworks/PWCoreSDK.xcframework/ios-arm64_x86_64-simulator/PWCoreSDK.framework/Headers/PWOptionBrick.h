//
//  PWOptionBrick.h
//  PWCoreSDK
//
//  Created by Tien Nhat Vu on 1/18/18.
//  Copyright © 2018 Paymentwall. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PWCardScannerProtocol.h"
#import "PWBrick3DSProtocol.h"
#import "PWPaymentOptionProtocol.h"

NS_ASSUME_NONNULL_BEGIN

@interface PWOptionBrick : NSObject <PWPaymentOptionProtocol>

@property(nonatomic, copy) NSString* overrideProjectKey;

/**
 The merchant SECRET for this option, overriding the one set with -[PWCoreSDK setGlobalSecretKey:].

 ⚠️ ONLY ONE THING USES IT, and it is optional. A charge that Paymentwall holds for fraud review
 comes back captured with `risk: "pending"`, and the SDK polls that charge until the review
 finishes. That endpoint authenticates with the secret, so with no secret the SDK cannot poll: the
 payment is then reported as PWPaymentResponseCodePending rather than as a success, and the outcome
 reaches you through Paymentwall's pingback instead.

 ⚠️ A SECRET KEY IN AN APP CAN BE EXTRACTED FROM IT. Setting this trades shipping the key for
 on-device polling. To avoid that, leave it unset: handle PWPaymentResponseCodePending and read the
 outcome from your own backend instead.
 */
@property(nonatomic, copy) NSString* overrideSecretKey;


/**
 Card scanner plugin, powered by CardIO

 @param cardScannerPlugin require PWCardScannerPlugin
 */
-(void)setCardScannerPlugin:(nullable id<PWCardScannerProtocol>)cardScannerPlugin;


/**
 Native 3-D Secure 2 provider. Optional.

 Register one and a 3DS2 challenge is drawn natively by the provider. Register none and the SDK
 shows the issuer's page in a web view, which is also a complete 3-D Secure flow.

 @param plugin an object conforming to PWBrick3DSProtocol
 */
-(void)set3DSPlugin:(nullable id<PWBrick3DSProtocol>)plugin;


/**
 Handle token charge result from your backend or app

 @param isSuccess Success result
 @param chargeObject Dictionary, set if you want to store the customer's card for next time purchase
 @param secureURL If 3D-Secure is enabled, process the URL in your app or set the URL here for the SDK to handle, require your backend to handle 3D-Secure redirect and return the result
 @param error If set, the transaction is cancelled
 */
-(void)handleBackendChargeResult:(BOOL)isSuccess
                    chargeObject:(nullable NSDictionary *)chargeObject
                       secureURL:(nullable NSURL *)secureURL
                    errorMessage:(nullable NSString *)error;

@end

NS_ASSUME_NONNULL_END
