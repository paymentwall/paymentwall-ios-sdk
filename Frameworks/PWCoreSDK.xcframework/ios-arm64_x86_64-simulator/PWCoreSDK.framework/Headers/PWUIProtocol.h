//
//  PWUIProtocol.h
//  PWCoreSDK
//
//  Created by Tien Nhat Vu on 2/7/18.
//  Copyright © 2018 Paymentwall. All rights reserved.
//

#import "PWPaymentOptionProtocol.h"
//#import "PWCustomization.h"
@class PWCustomization;

#ifndef PWUIProtocol_h
#define PWUIProtocol_h

#pragma mark - Customizationable
@protocol PWCustomizationable <NSObject>
-(void)setCustomization:(PWCustomization *)customization;
@end

//#pragma mark - Customization
//@protocol PWCustomizationProtocol <NSObject>
//-(void)applyCustomizationToView:(id)view;
//@end

#pragma mark - External theme
@protocol PWUILoadbleProtocol <NSObject>
-(void)showLoadingWithMessage:(NSString *)message subMessage:(NSString *)subMessage;
-(void)showSuccessWithMessage:(NSString *)message subMessage:(NSString *)subMessage;
-(void)showFailedWithMessage:(NSString *)message subMessage:(NSString *)subMessage withButton:(BOOL)withButton;
-(void)startAnimateLoading;
-(void)hideWithCompletion:(void (^)(void))completionBlock;

// THE FOUR BELOW ARE @optional, AND THAT IS THE POINT. An integrator may supply their own status
// view through -[PWUIProtocol loadableView]; making any of these required would stop their existing
// view compiling on upgrade. The SDK's own PWLoadableView implements all four, and PWPopupHelper
// -respondsToSelector: checks each one, so a view that implements none behaves exactly as before.
@optional

/// The payment being processed, so the overlay can print WHAT is being paid — the status screens say
/// "Processing $40.00" and "Paid $40.00". Before this the overlay was told neither the amount nor the
/// product. Sent once per payment.
-(void)setPaymentObject:(PWPaymentObject *)paymentObject;

/// How the payer would name the method that settled it — "Visa •• 4242", "Prepaid Card". Fills the
/// "Method" row on the processing screen and the "Paid with" row on the success screen. Sent by the
/// option's own view controller, which is the only place that knows; when nothing sends it, the row is
/// simply absent.
-(void)setPaymentMethodDescription:(NSString *)methodDescription;

/// The success state's countdown and its "Return to app" button. `seconds` is what
/// -[PWPopupHelper showSuccessWithMessage:subMessage:duration:completion:] was already going to wait
/// before dismissing; `action` finishes NOW instead of waiting, and is safe to call twice — the caller
/// makes it idempotent, so the button and the timer cannot both report the same payment.
///
/// Without this the overlay could still dismiss itself, but the payer would sit in front of a finished
/// payment with no way to leave and no idea how long it would take.
-(void)setAutoDismissAfterSeconds:(NSTimeInterval)seconds action:(void (^)(void))action;

/// The processing state, re-worded for a wait on the HOST APP rather than on the network.
///
/// The SDK reaches this whenever an option needs a signature it cannot compute: `isRequiringSign` is
/// set, a `stringToSign` goes to the merchant's delegate, and the method returns WITHOUT making a
/// request. Until this existed that condition drew the ordinary "processing" screen, so a wait on the
/// integrator's own backend was indistinguishable from a slow network — for up to the 60s timeout.
///
/// A view that does not implement it keeps getting -showLoadingWithMessage:subMessage:, which is what
/// it got before, so this cannot change an integrator's overlay by being added.
-(void)showWaitingForAppConfirmation;
@end

@protocol PWUIProtocol <NSObject>
-(NSBundle *)bundle;
-(NSString *)name;
-(UIView<PWUILoadbleProtocol> *)loadableView;
-(void)showUIWithOptionList:(NSArray<OptionObject> *)optionList paymentObject:(PWPaymentObject *)paymentObject delegate:(PWDelegateObject)delegate parentVC:(UIViewController *)parentVC;

@optional
-(void)setCustomization:(PWCustomization *)customization;

@end



#endif /* PWUIProtocol_h */

