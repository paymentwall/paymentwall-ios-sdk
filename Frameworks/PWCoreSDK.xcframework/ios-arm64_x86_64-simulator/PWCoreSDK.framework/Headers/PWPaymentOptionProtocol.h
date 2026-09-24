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
/// `Local` is raw value 0, and is what an option that states nothing gets.
typedef NS_ENUM(NSInteger, PWPaymentOptionPresentation) {
    /// Grouped with the other local methods behind a single row. The default.
    PWPaymentOptionPresentationLocal = 0,
    /// Gets its own top-level row, the way card and Mint do.
    ///
    /// **No longer distinguishes anything since 4.1.0** — every option gets its own row.
    PWPaymentOptionPresentationMain = 1,
};

/// The contract a payment option implements.
///
/// **Networking is not part of it.** An option that needs to make a request owns its own client —
/// create a `PWHTTPTransport` (see `PWHTTPTransport.h`).
@protocol PWPaymentOptionProtocol <NSObject>

-(void)setDelegate:(PWDelegateObject)delegate;
-(void)setCurrentPaymentObject:(PWPaymentObject *)currentPaymentObject;
-(void)setCurrentProjectKey:(NSString *)currentProjectKey;

-(NSString *)getPSName;
-(UIImage *)getLogoImage;
-(NSString *)getPaymentType;

-(void)makePaymentWithParentViewController:(UIViewController *)parentVC;

@optional

/// Where this option appears in the default option list.
///
/// **Deprecated in 4.1.0 and no longer read by the SDK.** The default UI used to split options into
/// a top-level group and a "Local Payments" sub-list; it now shows every registered option as one row
/// in the order you register them, so where a row appears is decided by your array and not by this.
///
/// It is kept so that existing options still compile, and will be removed in the next major version.
/// Implementing it is harmless and has no effect.
-(PWPaymentOptionPresentation)presentation
    __attribute__((deprecated("Not read since 4.1.0: the option list is flat and follows your registration order.")));
-(PWPaymentObject *)currentPaymentObject;
-(UIViewController *)optionViewController;
-(void)handlePingbackURL:(NSURL *)url;
-(BOOL)handlePingbackUniversalLink:(NSUserActivity *)userActivity;
/// Called when the integrator has signed a `stringToSign` this option asked for.
///
/// Optional: only an option that requests a signature needs it, and the built-in card and Mint
/// options do not. Omit it rather than implementing it as a no-op — the SDK checks whether it is
/// implemented to decide whether this option can sign.
-(void)continuePaymentWithSign:(NSString *)sign;
-(void)setCurrentSecretKey:(NSString *)currentSecretKey;
-(void)setCurrentSignVersion:(NSInteger)currentSignVersion;

/// This option's own project key, set on the option itself rather than inherited from
/// `-[PWCoreSDK setGlobalProjectKey:]`.
///
/// Implement it — or just declare the `overrideProjectKey` property every built-in option already
/// has — if your option can pay against a project of its own. The SDK reads it to decide whether a
/// global project key is needed at all: an app whose every option carries its own key does not have
/// to set one.
///
/// An option that does not implement this is taken to need the global key.
-(NSString *)overrideProjectKey;

@end

typedef id<PWPaymentOptionProtocol> OptionObject;

#endif /* PWPaymentOptionProtocol_h */
