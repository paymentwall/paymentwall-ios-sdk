//
//  PWOptionMint.h
//  PWCoreSDK
//
//  Created by Tien Nhat Vu on 1/18/18.
//  Copyright © 2018 Paymentwall. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PWPaymentOptionProtocol.h"

NS_ASSUME_NONNULL_BEGIN

@interface PWOptionMint : NSObject <PWPaymentOptionProtocol>

@property(nonatomic, copy) NSString* overrideProjectKey;

@end

NS_ASSUME_NONNULL_END
