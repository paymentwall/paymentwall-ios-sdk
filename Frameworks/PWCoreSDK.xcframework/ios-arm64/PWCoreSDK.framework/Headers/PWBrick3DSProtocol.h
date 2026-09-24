//
//  PWBrick3DSProtocol.h
//  PWCoreSDK
//
//  Copyright © 2026 Paymentwall. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#ifndef PWBrick3DSProtocol_h
#define PWBrick3DSProtocol_h

NS_ASSUME_NONNULL_BEGIN

#pragma mark - 3-D Secure 2

/// How a native 3-D Secure 2 challenge reports its result. Implemented by the SDK.
///
/// Every method is called on the main thread.
@protocol PWBrick3DSChallengeDelegate <NSObject>

/// The issuer authenticated the payer.
///
/// @param secureToken the token the challenge produced. It has to reach your server, which sends it
///   as `secure_token` on a SECOND charge — a native challenge is the middle of a payment,
///   not the end of one.
-(void)brick3DSDidAuthenticateWithSecureToken:(NSString *)secureToken;

/// The challenge did not authenticate.
///
/// @param cancelled YES when the PAYER stopped it. That is a different outcome from a refusal and
///   is not reported as a declined card.
-(void)brick3DSDidFailWithMessage:(nullable NSString *)message cancelled:(BOOL)cancelled;

@end

/// A native 3-D Secure 2 challenge provider.
///
/// **OPTIONAL.** Register one with `-[PWOptionBrick set3DSPlugin:]` and a 3DS2 challenge is drawn
/// natively; register none and the SDK shows the issuer's page in a web view, which is also a
/// complete 3-D Secure flow.
@protocol PWBrick3DSProtocol <NSObject>

/// Configure a session and set it up with the gateway's token.
///
/// @param serverJWT a session credential. Do not log it.
/// @param production NO selects the provider's staging environment.
/// @param completion called on the main thread. `ready` NO means no native challenge can run for
///   this payment, and the SDK falls back to the web view rather than failing the payment.
-(void)prepareWithServerJWT:(NSString *)serverJWT
                 production:(BOOL)production
                 completion:(void (^)(BOOL ready, NSString * _Nullable message))completion;

/// Run the challenge.
///
/// @param presentingViewController the view controller the provider may present its own UI from.
-(void)startChallengeWithTransactionId:(NSString *)transactionId
                               payload:(NSString *)payload
              presentingViewController:(UIViewController *)presentingViewController
                              delegate:(id<PWBrick3DSChallengeDelegate>)delegate;

/// Drop the session and anything it holds.
///
/// Required rather than optional: a provider handed a view controller keeps it until told
/// otherwise.
-(void)release3DSSession;

@end

NS_ASSUME_NONNULL_END

#endif /* PWBrick3DSProtocol_h */
