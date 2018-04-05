//
//  VituralCurrency.h
//  PWLocalSDK
//
//  Created by ; Tran on 6/15/15.
//  Copyright (c) 2015 Paymentwall. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface PWWidgetVirtualCurrency : NSObject

@property (nonatomic, strong) NSString *widget;             //Required
@property (nonatomic, strong) NSString *ps;
@property (nonatomic, strong) NSString *sign;
@property (nonatomic, strong) NSString *birthday;
@property (nonatomic, strong) NSString *email;
@property (nonatomic, strong) NSString *sex;
@property (nonatomic, strong) NSString *evaluation;
@property (nonatomic, strong) NSString *location_city;
@property (nonatomic, strong) NSString *location_state;
@property (nonatomic, strong) NSString *location_address;
@property (nonatomic, strong) NSString *location_country;
@property (nonatomic, strong) NSString *location_zip;
@property (nonatomic, strong) NSString *country_code;
@property (nonatomic, strong) NSString *rv;
@property (nonatomic, strong) NSString *th;
@property (nonatomic, strong) NSString *tm;
@property (nonatomic, strong) NSString *pingback_url;
@property (nonatomic, strong) NSString *success_url;
@end
