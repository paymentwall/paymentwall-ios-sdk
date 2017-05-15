//
//  PWCoreSDKMain.h
//  PWCoreSDK
//
//  Created by Tien Nhat Vu on 9/30/16.
//  Copyright © 2016 Paymentwall. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PWCoreSDKResponse.h"
#import "PWCoreSDKDelegate.h"
#import "PWLocalStatusResponse.h"
@class PaymentOptionsViewController;

#import "PaymentObject.h"

extern NSString * _Nonnull const BRICK_TOKEN_PROCESSED_FINISH;
extern NSString * _Nonnull const PAYMENT_FINISH_LOAD;

@interface PWCoreSDK : NSObject

+(instancetype _Nonnull)sharedInstance;

#pragma mark -Payment options
/**
 Setup the SDK

 @param pwProjectKey pwProjectKey, required
 @param pwSecretKey pwSecretKey, use only for PWLocal and plugin SDK, if nil, either specify secret key for each payment option or calculate the sign by yourself and add it to `paymentObject.pwLocalParams`
 @param signVersion signVersion, 2 = md5, 3 = sha256
 @param requestTimeout request timeout in second
 */
-(void)setupPaymentwallWithProjectKey:(NSString * _Nonnull)pwProjectKey
                            secretKey:(NSString * _Nullable)pwSecretKey
                          signVersion:(int)signVersion
                       requestTimeout:(NSTimeInterval)requestTimeout;

/**
 Set the Payment object, for new request, only need to set this and call showPaymentOptionsViewControllerWithParentViewcontroller

 @param paymentObject include payment params like price, name, currency,..
 */
-(void)setPaymentObject:(PaymentObject *_Nonnull)paymentObject;

/**
 Add credit card payment option
 
 @param publicKey brick public key, use default if null
 @param useNativeFinishDialog if true, indicate that you want Brick to display successful or failed payment dialog, otherwise, you want to display yourself.
 @param cardScannerPlugin require cardScannerPlugin, set the plugin to this param to use
 */
-(void)addBrickPaymentWithPublicKey:( NSString * _Nullable)publicKey
              useNativeFinishDialog:(BOOL)useNativeFinishDialog
                  cardScannerPlugin:(id _Nullable)cardScannerPlugin;

/**
 Add prepaid card payment option
 
 @param appID  mint app id, use default if null
 */
-(void)addMintPaymentWithAppID:(NSString * _Nullable )appID;

/**
 Add SMS payment option
 
 @param appID     mobiamo app id, use default if null
 @param noPrice   set to true to use default price for the current country
 */
-(void)addMobiamoPaymentWithAppID:(NSString * _Nullable )appID
                          noPrice:(BOOL)noPrice;

/**
 Create native PWLocal payment option

 @param type Can be VIRTUAL_CURRENCY / DIGITAL_GOODS_FLEXIBLE / DIGITAL_GOODS_DEFAULT / CART.
 @param secretKey Set this if you want the SDK to calculate signature for your params, It's suggest that you calculate signature by your server for more secure and leave this param nil, if you don't provide signature in params, default secret key will be used.
 */
-(void)addPWLocalPaymentWithType:(apiType)type
                       secretKey:(NSString *_Nullable)secretKey;

/**
 Add native custom payment option with their own SDK for easier payment
 
 @param customPaymentOptions array of customPaymentOptions object, please refer to docs to see how to initalize them
 */
-(void)addCustomPaymentOptions:(NSArray* _Nonnull)customPaymentOptions;

/**
 Show payment options listing view controller
 
 @param ViewController  parent view controller, if you don't have one, use [[UIApplication sharedApplication].rootViewController]
 @param target          delegate class, need to implement `PWCoreSDKDelegate`
 @param completionBlock execute after showing payment options view controller
 */
-(void)showPaymentOptionsViewControllerWithParentViewcontroller:(UIViewController * _Nonnull )ViewController
                                                        delegate:(nullable id <PWCoreSDKDelegate>)target
                                                  showCompletion:(nullable void (^)())completionBlock;

/**
 Using for handle callback from local payment option app (eg. Alipay, Unionpay, Paypal,...)
 Put in AppDelegate's -(BOOL)application:(UIApplication *)application openURL:(NSURL *)url sourceApplication:(NSString *)sourceApplication annotation:(id)annotation in APPDelegate. In iOS9.0 and above versions (including iOS9.0), please call this method in -(BOOL)application:(UIApplication *)app openURL:(NSURL *)url options:(NSDictionary *)options
 
 @param url url for callback
 */
-(void)handleOpenURL:(NSURL *_Nullable)url;

#pragma mark -PWLocal helpers
/**
 @brief Create string to sign from your params.
 @discussion If you don't use "success_url", default will be "pwlocal://paymentsuccessful", you can track this value on your webview's "shouldStartLoadWithRequest" or similar to close webview if you decide to use your own webview.
 
 @param params Can be Dictionary or object: DigitalGoodsDefautWidget / DigitalGoodsFlexibleWidget / VirtualCurrency / CartDefaultWidget.
 @return NSString Combine this string with your secret key to calculate the signature.
 */
-(NSString *_Nonnull) getStringToSign:(id _Nonnull)params;

/**
 Get default PWLocal extra headers for tracking

 @return Default extra headers as dictionary
 */
-(NSMutableDictionary *_Nonnull)getExtraPWLocalHeader;


/**
 Set back the extra headers after configuration the default value

 @param extraHeaders extra headers as dictionary
 */
-(void)setExtraPWLocalHeader:(NSDictionary *_Nonnull)extraHeaders;

/**
 Check payment status, SUPPORT DIGITAL GOODS FLEXIBLE WIDGET ONLY
 
 @param key Public project key
 @param agExternalId Merchant's product SKU ID
 @param uid ID of the end-user in merchant's system
 @param signVersion Sign version of project
 @param secret Secret project key
 @param completionBlock Do after response fetched
 */
-(void)checkPWLocalPaymentStatusWithKey:(NSString * _Nonnull)key
                           agExternalId:(NSString* _Nonnull)agExternalId
                                    uid:(NSString* _Nonnull)uid
                            signVersion:(int)signVersion
                           andSecretKey:(NSString* _Nullable)secret
                             completion:(void (^_Nullable)(PWLocalStatusResponse * _Nullable response))completionBlock;

#pragma mark - Extra
/**
 To get payment's name, price, currency code

 @return NSDictionary
 */
-(NSDictionary* _Nonnull)getPaymentObjectDetails;

/**
 Set use new flat UI, require PWCoreSDKResourceFlat.bundle
 Default is game style, use PWCoreSDKResource.bundle

 @param useFlatUI use flat UI
 */
-(void)setUseFlatUI:(BOOL)useFlatUI;

@end
