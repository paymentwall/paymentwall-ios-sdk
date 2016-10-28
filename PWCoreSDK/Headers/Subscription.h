//
//  Subscription.h
//  PWLocalSDK
//
//  Created by Cong Tran on 8/27/15.
//  Copyright (c) 2015 Paymentwall. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface Subscription : NSObject

@property (nonatomic, strong) NSString *object;
@property (nonatomic, strong) NSString *subsriptionID;
@property (nonatomic, strong) NSString *period;
@property (nonatomic, assign) int periodDuration;
@property (nonatomic, assign) int paymentsLimit;
@property (nonatomic, assign) int isTrial;
@property (nonatomic, assign) int started;
@property (nonatomic, assign) int expired;
@property (nonatomic, assign) int active;
@property (nonatomic, assign) int dateStarted;
@property (nonatomic, assign) int dateNext;

-(id)initWithDictionary:(NSDictionary *) dictionary;

@end
