//
//  PWLocalStatusResponse.h
//  PWLocalSDK
//
//  Created by Cong Tran on 8/27/15.
//  Copyright (c) 2015 Paymentwall. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PaymentStatus.h"

typedef NS_ENUM(int, PWLocalStatusResponseCode) {
    PWLOCAL_STAUTS_SUCCESSFUL,
    PWLOCAL_STATUS_FAILED
};

extern NSString *const PAYMENT_STATUS_SUCCESSFUL;
extern NSString *const PAYMENT_STATUS_DEFAULT_ERROR;
extern NSString *const PAYMENT_STATUS_FIELD_ERROR;

@interface PWLocalStatusResponse : NSObject

@property (nonatomic, assign) PWLocalStatusResponseCode code;
@property (nonatomic, strong) NSString *message;
@property (nonatomic, strong) NSArray *dataResponse;

@end
