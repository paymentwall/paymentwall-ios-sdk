//
//  PWLocalSDK.h
//  PWLocalSDK
//
//  Created by Cong Tran on 6/12/15.
//  Copyright (c) 2015 Paymentwall. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PWLocalViewController.h"
#import "PWLocalResponse.h"
#import "DigitalGoodsDefautWidget.h"
#import "DigitalGoodsFlexibleWidget.h"
#import "VirtualCurrency.h"
#import "CartDefaultWidget.h"
#import "PWLocalStatusResponse.h"

@interface PWLocalSDK : NSObject

// Check payment status
// SUPPORT DIGITAL GOODS FLEXIBLE WIDGET ONLY
+(void)checkPaymentStatusWithKey:(NSString *) key agExternalId:(NSString*) agExternalId uid:(NSString*) uid signVersion:(int)signVersion andSecretKey:(NSString*) secret completion:(PWLocalPaymentStatusCompletionBlock)block;

/**
 Extra headers required to process PWLocal, get this to add into your request if you are going to use your own webview, included:
 
 HTTP_X_APP_NAME: app name
 HTTP_X_REQUESTED_WITH: bundle identifier
 HTTP_X_DOWNLOAD_LINK: app download url, default is "url"
 */

+(NSDictionary *) getExtraHeaders;

/**
 Create string to sign from your params, if you don't use "success_url", default will be "pwlocal://paymentsuccessful", you can track this value on your webview's "shouldStartLoadWithRequest" or similar to close webview if you decide to use your own webview
 
 (id)params: Can be Dictionary or object: DigitalGoodsDefautWidget / DigitalGoodsFlexibleWidget / VirtualCurrency / CartDefaultWidget
 */
+(NSString *) getStringToSign:(id)params;


@end
