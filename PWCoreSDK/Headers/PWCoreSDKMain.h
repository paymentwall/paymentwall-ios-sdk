//
//  PWCoreSDKMain.h
//  PWCoreSDK
//
//  Created by Tien Nhat Vu on 9/30/16.
//  Copyright © 2016 Paymentwall. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PWLocalSDK.h"
#import "PWCoreSDKResponse.h"
#import "PWCoreSDKDelegate.h"

@class PaymentOptionsViewController;

extern NSString * _Nonnull const BRICK_TOKEN_PROCESSED_FINISH;
extern NSString * _Nonnull const PAYMENT_FINISH_LOAD;

@interface PWCoreSDK : NSObject

/**
 *  Creating payment info
 *
 *  @param paymentName              Name of the item
 *  @param paymentAmount            Payment price
 *  @param paymentCurrency          Payment currency
 *  @param paymentImage             Item image
 *  @param useNativeFinishDialog    Set to false if you wish to use application payment successful dialog
 *  @param requestTimeout           Timeout for payment request
 */

+ (void)setPaymentName:(NSString * _Nullable)paymentName
         paymentAmount:(NSString * _Nonnull)paymentAmount
       paymentCurrency:(NSString * _Nonnull)paymentCurrency
          paymentImage:(UIImage * _Nullable)paymentImage
 useNativeFinishDialog:(BOOL)useNativeFinishDialog
        requestTimeout:(NSTimeInterval)requestTimeout;


/**
 Add credit card payment option

 @param publicKey brick public key
 */
+ (void)createNewBrickPaymentWithPublicKey:( NSString * _Nonnull )publicKey;

    
/**
 Add prepaid card payment option

 @param appID  mint app id
 @param userID user id
 */
+ (void)createNewMintPaymentWithAppID:(NSString * _Nonnull )appID
                               userID:(NSString * _Nullable)userID;

    
/**
 Add SMS payment option

 @param appID     mobiamo app id
 @param userID    user id
 @param paymentID payment id
 @param noPrice   set to true to use server price
 */
+ (void)createNewMobiamoPaymentWithAppID:(NSString * _Nonnull )appID
                                  userID:(NSString * _Nullable)userID
                               paymentID:(NSString * _Nullable)paymentID
                                 noPrice:(BOOL)noPrice;

    
/**
 Add native payment with webform

 @param secretKey        PWLocal secret key
 @param type             API type (default DIGITAL_GOODS)
 @param customRequestDic custom request dictionary if default one doesn't suit your needs
 */
+ (void)createNewPWLocalCustomPaymentWithSecretKey:(NSString * _Nonnull )secretKey
                                           apiType:(apiType)type
                                   appDownloadLink:(NSString * _Nonnull)appDownloadLink
                                  customRequestDic:(NSDictionary * _Nonnull )customRequestDic;

    
/**
 Add native payment with webform
 
 @param secretKey        PWLocal secret key
 @param virtualCurrency  VirtualCurrency object, see the header for required fields
 */
+ (void)createNewPWLocalVirtualCurrencyPaymentWithSecretKey:(NSString * _Nonnull )secretKey
                                            appDownloadLink:(NSString * _Nonnull)appDownloadLink
                                             virualCurrency:(VirtualCurrency * _Nonnull )virtualCurrency;

    
/**
 Add native payment with webform
 
 @param secretKey                PWLocal secret key
 @param digitalGoodsDefautWidget DigitalGoodsDefautWidget object, see the header for required fields
 */
+ (void)createNewPWLocalDigitalGoodsDefautWidgetPaymentWithSecretKey:(NSString * _Nonnull )secretKey
                                                     appDownloadLink:(NSString * _Nonnull)appDownloadLink
                                            digitalGoodsDefautWidget:(DigitalGoodsDefautWidget * _Nonnull )digitalGoodsDefautWidget;

/**
 Add native payment with webform
 
 @param secretKey                  PWLocal secret key
 @param digitalGoodsFlexibleWidget DigitalGoodsFlexibleWidget object, see the header for required fields
 */
+ (void)createNewPWLocalDigitalGoodsFlexibleWidgetPaymentWithSecretKey:(NSString * _Nonnull )secretKey
                                                       appDownloadLink:(NSString * _Nonnull)appDownloadLink
                                            digitalGoodsFlexibleWidget:(DigitalGoodsFlexibleWidget * _Nonnull )digitalGoodsFlexibleWidget;

/**
 Add native payment with webform
 
 @param secretKey         PWLocal secret key
 @param cartDefaultWidget CartDefaultWidget object, see the header for required fields
 */
+ (void)createNewPWLocalCartWidgetPaymentWithSecretKey:(NSString * _Nonnull )secretKey
                                       appDownloadLink:(NSString * _Nonnull)appDownloadLink
                                     cartDefaultWidget:(CartDefaultWidget * _Nonnull )cartDefaultWidget;

/**
 Add native custom payment option with their own SDK for easier payment

 @param customPaymentOptions array of customPaymentOptions object, please refer to docs to see how to initalize them
 */
+ (void)addCustomPaymentOptions:(NSArray* _Nonnull)customPaymentOptions;

/**
 To get payment's name, price, currency code

 @return NSDictionary
 */
+ (NSDictionary* _Nonnull )getPaymentObjectDetails;

/**
 Show payment options listing view controller

 @param ViewController  parent view controller, if you don't have one, use [[UIApplication sharedApplication].rootViewController]
 @param target          delegate class, need to implement `PWCoreSDKDelegate`
 @param completionBlock execute after showing payment options view controller
 */
+ (void)showPaymentOptionsViewControllerWithParentViewcontroller:(UIViewController * _Nonnull )ViewController
                                                         delegate:(nullable id)target
                                                   showCompletion:(nullable void (^)())completionBlock;

@end
