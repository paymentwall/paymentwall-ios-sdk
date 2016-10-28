//
//  PWLocalResponse.h
//  PWLocalSDK
//
//  Created by Cong Tran on 6/15/15.
//  Copyright (c) 2015 Paymentwall. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef enum {
    PWLOCAL_SUCCESSFUL = 0,
    PWLOCAL_FAILED = 1,
    PWLOCAL_CANCELED = 2
    
} PWLocalResponseCode;

extern NSString *const PWLOCAL_PAYMENT_SUCCESSFUL;
extern NSString *const PWLOCAL_PAYMENT_FAIL;
extern NSString *const PWLOCAL_PAYMENT_CANCELED;

@interface PWLocalResponse : NSObject

@property (nonatomic, assign) int code;
@property (nonatomic, strong) NSString *message;

@end
