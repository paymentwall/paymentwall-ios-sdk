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
#import "PWCoreSDKResponse.h"
#import "PWCustomization.h"

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
                   paymentOption:(NSArray *)paymentOption
                        delegate:(id <PWCoreSDKDelegate>)delegate;


/**
 Using for handle callback from local payment option app (eg. Alipay, Unionpay, Paypal,...)
 Put in AppDelegate's -(BOOL)application:(UIApplication *)application openURL:(NSURL *)url sourceApplication:(NSString *)sourceApplication annotation:(id)annotation in APPDelegate.
 In iOS9.0 and above versions (including iOS9.0), please call this method in -(BOOL)application:(UIApplication *)app openURL:(NSURL *)url options:(NSDictionary *)options

 @param url The callback URL
 */
-(void)handlePingbackURL:(NSURL *)url;

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
-(void)setExtraParams:(NSDictionary *)params;

#pragma mark - Optional UI
/**
 Set to use external UI package.
 
 @param package Plugin UI library.
 */
-(void)setUIPackage:(id)package;

/**
 Customize the Default UI.

 @param customization PWCustomization object
 */
-(void)setCustomizationForDefaultUI:(PWCustomization *)customization;

@end

NS_ASSUME_NONNULL_END
