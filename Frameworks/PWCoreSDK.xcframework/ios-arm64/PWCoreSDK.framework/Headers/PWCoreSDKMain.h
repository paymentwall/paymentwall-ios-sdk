//
//  PWCoreSDKMain.h
//  PWCoreSDK
//
//  Created by Tien Nhat Vu on 1/18/18.
//  Copyright © 2018 Paymentwall. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PWPaymentObject.h"
#import "PWConstants.h"
#import "PWLog.h"
#import "PWCoreSDKResponse.h"
#import "PWCustomization.h"
#import "PWPaymentOptionProtocol.h"
#import "PWUIProtocol.h"

NS_ASSUME_NONNULL_BEGIN

@interface PWCoreSDK : NSObject

+(instancetype)sharedInstance;

#pragma mark - Required

/**
 Set global project key to use with all Payment Option if not overrided

 @param projectKey Paymentwall project key
 */
-(void)setGlobalProjectKey:(NSString *)projectKey;


/**
 Show the payment UI

 @param viewController Source UIViewController to present the view
 @param paymentObject PWPaymentObject contains info of the payment
 @param paymentOption Array of the payment options
 @param delegate Delegate to handle callback from the SDK
 */
-(void)showPaymentVCWithParentVC:(UIViewController *)viewController
                   paymentObject:(PWPaymentObject *)paymentObject
                   paymentOption:(NSArray<id<PWPaymentOptionProtocol>> *)paymentOption
                        delegate:(id <PWCoreSDKDelegate>)delegate;


/**
 Using for handle callback from local payment option app (eg. Alipay, Unionpay, Paypal,...)
 Put in AppDelegate's -(BOOL)application:(UIApplication *)application openURL:(NSURL *)url sourceApplication:(NSString *)sourceApplication annotation:(id)annotation in APPDelegate.
 In iOS9.0 and above versions (including iOS9.0), please call this method in -(BOOL)application:(UIApplication *)app openURL:(NSURL *)url options:(NSDictionary *)options

 @param url The callback URL
 */
-(void)handlePingbackURL:(NSURL *)url;

/// Using for handle callback from local payment option app if using universal link (eg. Wechatpay)
/// Put in AppDelegate's application:continueUserActivity:restorationHandler:
/// @param userActivity NSUserActivity
-(BOOL)handlePingbackUniversalLink:(NSUserActivity *)userActivity;

#pragma mark - Optional
/**
 Some payment option will require signing the request to continue payment. You can call this method after you signed the `stringToSign` inside the `PWCoreSDKDelegate` callback with the appropriated signing algorithm and your secret key
 This is only needed if you do not want to expose your secret key to the SDK.
 
 @param sign Signature string
 */
-(void)continuePaymentWithSign:(NSString *)sign;

/**
 Some payment option will require signing the request to continue payment. You can specify your project's secret key here so that the SDK can help you sign the request to continue.

 @param secretKey Paymentwall secret key
 */
-(void)setGlobalSecretKey:(NSString *)secretKey;

/**
 Specify the signature algorithm that you wanted to use.
 
 @param signType Default is `PWSignatureTypeSHA256`
 */
-(void)setGlobalSignType:(PWSignatureType)signType;

/**
 Request time out for the request in second. Also apply for delegate callback that require futher action such as PWPaymentResponseCodeMerchantProcessing or PWPaymentResponseCodeSignatureRequiring

 @param requestTimeOut Default to 60s
 */
-(void)setRequestTimeOut:(NSTimeInterval)requestTimeOut;

/**
 Add extra params to payment request
 
 @param params : dictionary of extra params
 */
-(void)setExtraParams:(NSDictionary<NSString *, id> *)params;

/// How much the SDK logs about its own network activity. `PWLogLevelNone` by default.
///
/// **It cannot log a request body, a header or a response body** — not by policy, by construction:
/// the logger takes events rather than strings, and strips the query from every URL before printing
/// it. So raising this level cannot put card data or a signature in the device log.
///
/// Leave it at `PWLogLevelNone` in a shipped app.
-(void)setLogLevel:(PWLogLevel)level;

/// Called when the SDK cannot act on how it was configured — a payment option that does not
/// conform to `PWPaymentOptionProtocol`, a malformed `userID`, a missing project key, an
/// unsupported customization, a wallet SDK version mismatch.
///
/// It is a handler rather than a delegate method because these failures happen while the SDK is
/// being **set up**, before any payment starts and therefore before a payment delegate exists.
/// Without it, several of them are silent: the option is dropped, or the value is accepted anyway,
/// and nothing tells the app.
///
/// **Set this before configuring anything else.** `error.localizedDescription` carries the reason,
/// and the `PWError*` constants in `PWError.h` are the values to compare against.
@property (nonatomic, copy, nullable) void (^configurationFailureHandler)(NSError *error);

#pragma mark - Optional UI
/**
 Set to use external UI package.
 
 @param package Plugin UI library.
 */
-(void)setUIPackage:(id<PWUIProtocol>)package;

/**
 Customize the Default UI.

 @param customization PWCustomization object
 */
-(void)setCustomizationForDefaultUI:(PWCustomization *)customization;

@end

NS_ASSUME_NONNULL_END
