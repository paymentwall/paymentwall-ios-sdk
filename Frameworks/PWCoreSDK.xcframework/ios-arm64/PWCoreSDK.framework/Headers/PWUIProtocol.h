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

// The five below are @optional so that a status view supplied through -[PWUIProtocol loadableView]
// keeps compiling when the SDK adds one. Each is guarded by -respondsToSelector: at the call site;
// a view that implements none still works.
@optional

/// The charge is TAKEN and Paymentwall is reviewing it for fraud, and the SDK is polling.
///
/// A wait with no known end, like `-showWaitingForAppConfirmation` and unlike the ordinary
/// processing state: the SDK is not waiting on a request it made, it is waiting on a human decision.
/// A status view that does not implement this gets the ordinary processing wording.
///
/// @param chargeId Paymentwall's id for the charge, shown so the payer can quote it.
-(void)showChargeUnderReview:(NSString *)chargeId;

/// The payment being processed, so the overlay can print WHAT is being paid — the status screens say
/// "Processing $40.00" and "Paid $40.00". Sent once per payment.
-(void)setPaymentObject:(PWPaymentObject *)paymentObject;

/// How the payer would name the method that settled it — "Visa •• 4242", "Prepaid Card". Fills the
/// "Method" row on the processing screen and the "Paid with" row on the success screen. Sent by the
/// option's own view controller, which is the only place that knows; when nothing sends it, the row is
/// simply absent.
-(void)setPaymentMethodDescription:(NSString *)methodDescription;

/// The success state's countdown and its "Return to app" button.
///
/// `seconds` is how long the overlay will wait before dismissing itself; `action` finishes NOW
/// instead of waiting. `action` is idempotent, so the button and the timer cannot both report the
/// same payment.
-(void)setAutoDismissAfterSeconds:(NSTimeInterval)seconds action:(void (^)(void))action;

/// The processing state, re-worded for a wait on the HOST APP rather than on the network.
///
/// Called when an option needs a signature it cannot compute: a `stringToSign` goes to your delegate
/// and the SDK makes no request until you answer. A view that does not implement this gets
/// -showLoadingWithMessage:subMessage: instead.
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

