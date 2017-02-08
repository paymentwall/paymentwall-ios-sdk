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

+(PWLocalViewController*) createNewPWLocalViewController;

// Check payment status
// SUPPORT DIGITAL GOODS FLEXIBLE WIDGET ONLY
+(void)checkPaymentStatusWithKey:(NSString *) key agExternalId:(NSString*) agExternalId uid:(NSString*) uid signVersion:(int)signVersion andSecretKey:(NSString*) secret completion:(PWLocalPaymentStatusCompletionBlock)block;


@end
