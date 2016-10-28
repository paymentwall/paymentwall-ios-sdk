//
//  PaymentStatus.h
//  PWLocalSDK
//
//  Created by Cong Tran on 8/27/15.
//  Copyright (c) 2015 Paymentwall. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Subscription.h"

@interface PaymentStatus : NSObject

@property (nonatomic, strong) NSString *object;
@property (nonatomic, strong) NSString *paymentStatusID;
@property (nonatomic, assign) int created;
@property (nonatomic, strong) NSString *amount;
@property (nonatomic, strong) NSString *currency;
@property (nonatomic, assign) BOOL refunded;
@property (nonatomic, strong) NSString *risk;
@property (nonatomic, strong) NSString *uid;
@property (nonatomic, strong) NSString *projectID;
@property (nonatomic, strong) Subscription *subscription;

-(id) initWithDictionary:(NSDictionary*) dictionary;

@end
