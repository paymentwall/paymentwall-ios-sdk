//
//  PWLocalStatusResponse.h
//  PWLocalSDK
//
//  Created by Cong Tran on 8/27/15.
//  Copyright (c) 2015 Paymentwall. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PaymentStatus.h"

//typedef enum {
//    PWLOCAL_STAUTS_SUCCESSFUL = 0,
//    PWLOCAL_STATUS_FAILED = 1,
//    
//} PWLocalStatusResponseCode;

typedef NS_ENUM(NSUInteger, PWLocalStatusResponseCode) {
    PWLOCAL_STAUTS_SUCCESSFUL = 0,
    PWLOCAL_STATUS_FAILED = 1
};

extern NSString *const PAYMENT_STATUS_SUCCESSFUL;
extern NSString *const PAYMENT_STATUS_DEFAULT_ERROR;
extern NSString *const PAYMENT_STATUS_FIELD_ERROR;

@interface PWLocalStatusResponse : NSObject

@property (nonatomic, assign) PWLocalStatusResponseCode code;
@property (nonatomic, strong) NSString *message;
@property (nonatomic, strong) NSArray *dataResponse;

@end
