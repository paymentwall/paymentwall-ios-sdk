//
//  PWPaymentOptionProtocol.h
//  PWCoreSDK
//
//  Created by Tien Nhat Vu on 3/9/18.
//  Copyright © 2018 Paymentwall. All rights reserved.
//

#import "PWPaymentObject.h"
#import "PWCoreSDKResponse.h"

#ifndef PWPaymentOptionProtocol_h
#define PWPaymentOptionProtocol_h

/// Where an option appears in the default option list.
///
/// Replaces the old `isMainOption` flag, whose *absence* meant "local" — so the most common answer
/// was the one an option could not state.
///
/// `Local` is raw value 0 and is still what an option that says nothing gets, so existing grouping
/// is unchanged.
typedef NS_ENUM(NSInteger, PWPaymentOptionPresentation) {
    /// Grouped with the other local methods behind a single row. The default.
    PWPaymentOptionPresentationLocal = 0,
    /// Gets its own top-level row, the way card and Mint do.
    PWPaymentOptionPresentationMain = 1,
};

/// The contract a payment option implements.
///
/// **Networking is deliberately absent.** An option that needs to make a request owns its own
/// client — create a `PWHTTPTransport` (see `PWHTTPTransport.h`). That is what lets this contract
/// be published without exposing the SDK's internal HTTP class.
@protocol PWPaymentOptionProtocol <NSObject>

-(void)setDelegate:(PWDelegateObject)delegate;
-(void)setCurrentPaymentObject:(PWPaymentObject *)currentPaymentObject;
-(void)setCurrentProjectKey:(NSString *)currentProjectKey;

-(NSString *)getPSName;
-(UIImage *)getLogoImage;
-(NSString *)getPaymentType;

-(void)makePaymentWithParentViewController:(UIViewController *)parentVC;

@optional

/// Where this option appears in the default option list. Omit it to be grouped as a local method,
/// which is what almost every payment option wants.
-(PWPaymentOptionPresentation)presentation;
-(PWPaymentObject *)currentPaymentObject;
-(UIViewController *)optionViewController;
-(void)handlePingbackURL:(NSURL *)url;
-(BOOL)handlePingbackUniversalLink:(NSUserActivity *)userActivity;
/// Called when the integrator has signed a `stringToSign` this option asked for.
///
/// **Optional on purpose.** Only an option that requests a signature needs it; the built-in card
/// and Mint options do not. Implementing it as a no-op would be worse than omitting it, because
/// that claims to handle signing and does nothing.
-(void)continuePaymentWithSign:(NSString *)sign;
-(void)setCurrentSecretKey:(NSString *)currentSecretKey;
-(void)setCurrentSignVersion:(NSInteger)currentSignVersion;

@end

typedef id<PWPaymentOptionProtocol> OptionObject;

#endif /* PWPaymentOptionProtocol_h */
