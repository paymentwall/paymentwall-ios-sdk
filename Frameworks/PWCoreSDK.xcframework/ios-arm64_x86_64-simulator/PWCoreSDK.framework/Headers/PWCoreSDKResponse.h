//
//  PWCoreSDKResponse.h
//  PWCoreSDK
//
//  Created by Tien Nhat Vu on 1/19/18.
//  Copyright © 2018 Paymentwall. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PWBrickToken.h"
#import "PWConstants.h"

NS_ASSUME_NONNULL_BEGIN

@interface PWCoreSDKResponse : NSObject

@property (nonatomic, readonly) PWPaymentResponseCode responseCode;
@property (nonatomic, readonly) NSString *paymentType;
@property (nonatomic, readonly) NSString *paymentAmount;
@property (nonatomic, readonly) NSString *paymentCurrency;

@property (nonatomic, readonly, nullable) NSString *message;
@property (nonatomic, readonly, nullable) PWBrickToken *token;
@property (nonatomic, readonly, nullable) NSString *stringToSign;
@property (nonatomic, readonly) PWSignatureType signatureAlgorithm;

@end

/**
 Conform to this protocol to handle payment result
 */
@protocol PWCoreSDKDelegate <NSObject>
-(void)paymentResponse:(PWCoreSDKResponse*) response;
@end

typedef id<PWCoreSDKDelegate> PWDelegateObject;

NS_ASSUME_NONNULL_END
