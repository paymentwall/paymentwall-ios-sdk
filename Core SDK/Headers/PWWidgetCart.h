//
//  CartDefaultWidget.h
//  PWLocalSDK
//
//  Created by Cong Tran on 6/15/15.
//  Copyright (c) 2015 Paymentwall. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PWPaymentObject.h"

@interface PWWidgetCart : NSObject

@property (nonatomic, strong) NSString *widget;                 //Required
@property (nonatomic, strong) NSString *firstname;
@property (nonatomic, strong) NSString *lastname;
@property (nonatomic, strong) NSString *email;
@property (nonatomic, strong) NSString *evaluation;
@property (nonatomic, strong) NSString *birthday;
@property (nonatomic, strong) NSString *sex;
@property (nonatomic, strong) NSString *location_city;
@property (nonatomic, strong) NSString *location_state;
@property (nonatomic, strong) NSString *location_address;
@property (nonatomic, strong) NSString *location_country;
@property (nonatomic, strong) NSString *location_zip;
@property (nonatomic, strong) NSString *sign;
@property (nonatomic, strong) NSString *pingback_url;

@end
