//
//  PWCoreSDKResponse.h
//  PWCoreSDK
//
//  Created by Tien Nhat Vu on 9/30/16.
//  Copyright © 2016 Paymentwall. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BrickToken.h"


/**
 PaymentType
 */
typedef NS_ENUM(NSUInteger, PaymentType) {
    NONE = 0,
    MINT = 1,
    PWLOCAL = 2,
    BRICK = 3,
    MOBIAMO = 4
};

/**
 PaymentResponseCode
 */
typedef NS_ENUM(NSUInteger, PaymentResponseCode) {
    SUCCESSFUL = 0,
    FAILED = 1,
    CANCEL = 2
};

extern NSString *const PAYMENT_SUCCESSFUL;
extern NSString *const PAYMENT_FAIL;
extern NSString *const PAYMENT_CANCELED;

@interface PWCoreSDKResponse : NSObject

@property (nonatomic, assign) PaymentResponseCode responseCode;
@property (nonatomic, assign) PaymentType paymentType;
@property (nonatomic, strong) NSString *paymentName;
@property (nonatomic, strong) NSString *paymentAmount;
@property (nonatomic, strong) NSString *paymentCurrency;
@property (nonatomic, strong) NSString *userID;
@property (nonatomic, strong) NSString *message;
@property (nonatomic, strong) NSString *productID;
@property (nonatomic, strong) BrickToken *token;

@end
