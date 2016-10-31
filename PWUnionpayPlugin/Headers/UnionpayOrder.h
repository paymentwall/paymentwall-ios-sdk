//
//  UnionpayOrder.h
//  PaymentwallUnionpaySDK
//
//  Created by Tien Nhat Vu on 10/19/16.
//  Copyright © 2016 Paymentwall. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface UnionpayOrder : NSObject

@property (nonatomic, copy) NSString *version;
@property (nonatomic, copy) NSString *encoding;
@property (nonatomic, copy) NSString *signMethod;
@property (nonatomic, copy) NSString *txnType;
@property (nonatomic, copy) NSString *txnSubType;
@property (nonatomic, copy) NSString *bizType;
@property (nonatomic, copy) NSString *channelType;
@property (nonatomic, copy) NSString *merId;
@property (nonatomic, copy) NSString *backUrl;
@property (nonatomic, copy) NSString *orderId;
@property (nonatomic, copy) NSString *currencyCode;
@property (nonatomic, copy) NSString *txnAmt;
@property (nonatomic, copy) NSString *txnTime;
@property (nonatomic, copy) NSString *certId;
@property (nonatomic, copy) NSString *signature;
@property (nonatomic, copy) NSString *tn;

-(instancetype)initWithDict:(NSDictionary *)dict;

@end
