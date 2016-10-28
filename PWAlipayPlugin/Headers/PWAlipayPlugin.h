//
//  PWAlipayPlugin.h
//  PaymentwallAlipaySDK
//
//  Created by Tien Nhat Vu on 10/11/16.
//  Copyright © 2016 Paymentwall. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PWAlipayResponse.h"

NS_ASSUME_NONNULL_BEGIN

@protocol PWAlipayPluginDelegate <NSObject>

@optional
-(void) pwAlipayResponse:(PWAlipayResponse*) response;

@end


@interface PWAlipayPlugin : NSObject
    
- (void)makePayment;

//Use delegate or completion handler block to call AlipaySDK
@property (nonatomic, weak) id <PWAlipayPluginDelegate> delegate;

@property (nonatomic, copy) void (^_Nullable signatureFetched)(PWAlipayResponse *response);
-(void)doAfterFetchedSignature:(void (^_Nullable)(PWAlipayResponse *response))signatureFetched;

//Required
@property (nonatomic, strong) NSString* pwProjectKey;
@property (nonatomic, strong) NSString* pwSecretKey;
@property (nonatomic, assign) int signVersion; // 2 for MD5, 3 for SHA256
@property (nonatomic, strong) NSString* userId; // User id
@property (nonatomic, strong) NSString* agExternalId; // Item id
@property (nonatomic, strong) NSString* appId; //Required for domestic account, default for internation: external

//International account
@property (nonatomic, strong) NSString* itbPay; //Default: 30m
@property (nonatomic, strong) NSString* forexBiz; //Required for international account, default: FP
@property (nonatomic, strong) NSString* appenv; //”system=client platform name ^version=business system version” eg ”system=iOS^version=9”

@end

NS_ASSUME_NONNULL_END
