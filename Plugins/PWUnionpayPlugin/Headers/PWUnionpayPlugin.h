//
//  PWUnionpayPlugin.h
//  PaymentwallUnionpaySDK
//
//  Created by Tien Nhat Vu on 10/19/16.
//  Copyright © 2016 Paymentwall. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "PWUnionpayResponse.h"

NS_ASSUME_NONNULL_BEGIN

@protocol PWUnionpayPluginDelegate <NSObject>

@optional
-(void) pwUnionpayResponse:(PWUnionpayResponse*) response;

@end

@interface PWUnionpayPlugin : NSObject

-(void)makePayment;

//Use delegate or completion handler block to call UnionpaySDK
@property (nonatomic, weak) id <PWUnionpayPluginDelegate> delegate;
@property (nonatomic, copy) void (^_Nullable signatureFetched)(PWUnionpayResponse *response);
-(void)doAfterFetchedSignature:(void (^_Nullable)(PWUnionpayResponse *response))signatureFetched;

//Required
@property (nonatomic, strong) NSString* pwProjectKey;
@property (nonatomic, strong) NSString* pwSecretKey;
@property (nonatomic, assign) int signVersion; // 2 for MD5, 3 for SHA256
@property (nonatomic, strong) NSString* userId; // User id
@property (nonatomic, strong) NSString* agExternalId; // Item id

@end

NS_ASSUME_NONNULL_END
