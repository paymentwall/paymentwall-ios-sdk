//
//  PWBrickToken.h
//  PWCoreSDK
//
//  Created by Tien Nhat Vu on 1/19/18.
//  Copyright © 2018 Paymentwall. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface PWBrickToken : NSObject

@property (nonatomic, readonly) NSString *type;
@property (nonatomic, readonly) NSString *token;
@property (nonatomic, readonly) NSInteger expiredIn;
@property (nonatomic, readonly) NSInteger active;
@property (nonatomic, readonly) NSString *cardType;
@property (nonatomic, readonly) NSString *cardLast4Pin;
@property (nonatomic, readonly) NSString *cardBin;
@property (nonatomic, readonly) NSString *cardExpMonth;
@property (nonatomic, readonly) NSString *cardExpYear;
@property (nonatomic, readonly) NSString *issuingCountry;
@property (nonatomic, nullable, readonly) NSString *email;
@property (nonatomic, nullable, readonly) NSString *fingerprint;

@end

NS_ASSUME_NONNULL_END
