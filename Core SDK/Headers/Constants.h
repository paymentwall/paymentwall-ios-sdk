//
//  Constants.h
//  PWCoreSDK
//
//  Created by Tien Nhat Vu on 5/9/17.
//  Copyright © 2017 Paymentwall. All rights reserved.
//

#import <Foundation/Foundation.h>

#ifndef Constants_h
#define Constants_h

/**
 PaymentType
 */
typedef NS_ENUM(NSUInteger, PaymentType) {
    NONE = 0,
    MINT = 1,
    PWLOCAL = 2,
    BRICK = 3,
    MOBIAMO = 4,
    OTHERS = 5
};

/**
 PaymentResponseCode
 */
typedef NS_ENUM(NSUInteger, PaymentResponseCode) {
    SUCCESSFUL = 0,
    FAILED = 1,
    CANCEL = 2
};


/**
 PWLocal API types
 */
typedef NS_ENUM(int, apiType) {
    VIRTUAL_CURRENCY,
    DIGITAL_GOODS_FLEXIBLE,
    DIGITAL_GOODS_DEFAULT,
    CART
};

#endif /* Constants_h */
