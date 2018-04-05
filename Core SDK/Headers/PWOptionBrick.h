//
//  PWOptionBrick.h
//  PWCoreSDK
//
//  Created by Tien Nhat Vu on 1/18/18.
//  Copyright © 2018 Paymentwall. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface PWOptionBrick : NSObject

@property(nonatomic, copy) NSString* overrideProjectKey;


/**
 Card scanner plugin, powered by CardIO

 @param cardScannerPlugin require PWCardScannerPlugin
 */
-(void)setCardScannerPlugin:(id)cardScannerPlugin;


/**
 Handle token charge result from your backend or app

 @param isSuccess Success result
 @param chargeObject Dictionary, set if you want to store the customer's card for next time purchase
 @param secureURL If 3D-Secure is enabled, process the URL in your app or set the URL here for the SDK to handle, require your backend to handle 3D-Secure redirect and return the result
 @param error If set, the transaction is cancelled
 */
-(void)handleBackendChargeResult:(BOOL)isSuccess
                    chargeObject:(nullable NSDictionary *)chargeObject
                       secureURL:(nullable NSURL *)secureURL
                    errorMessage:(nullable NSString *)error;

@end

NS_ASSUME_NONNULL_END
