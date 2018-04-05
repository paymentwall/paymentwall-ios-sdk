//
//  PWOptionMyCard.h
//  PWOptionMyCard
//
//  Created by Tien Nhat Vu on 3/15/18.
//  Copyright © 2018 Paymentwall. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PWConstants.h"

NS_ASSUME_NONNULL_BEGIN

extern NSString * _Nonnull const PWPaymentTypeMycard;

@interface PWOptionMyCard : NSObject

///Optional
@property(nonatomic, copy, nullable) NSString* overrideProjectKey;
@property(nonatomic, copy, nullable) NSString* overrideSecretKey;
@property(nonatomic) PWSignatureType overrideSignVersion;

@end

NS_ASSUME_NONNULL_END
