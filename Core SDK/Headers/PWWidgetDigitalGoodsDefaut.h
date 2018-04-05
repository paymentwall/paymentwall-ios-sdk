//
//  PWWidgetDigitalGoodsDefaut.h
//  PWLocalSDK
//
//  Created by Cong Tran on 6/15/15.
//  Copyright (c) 2015 Paymentwall. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface PWWidgetDigitalGoodsDefaut : NSObject

@property (nonatomic, strong) NSString *widget;                 //Required
@property (nonatomic, strong) NSString *ps;
@property (nonatomic, strong) NSString *ts;
@property (nonatomic, strong) NSString *sign;
@property (nonatomic, strong) NSString *birthday;
@property (nonatomic, strong) NSString *country_code;
@property (nonatomic, strong) NSString *email;
@property (nonatomic, strong) NSString *evaluation;
@property (nonatomic, strong) NSString *firstname;
@property (nonatomic, strong) NSString *lang;
@property (nonatomic, strong) NSString *lastname;
@property (nonatomic, strong) NSString *location_city;
@property (nonatomic, strong) NSString *location_state;
@property (nonatomic, strong) NSString *location_address;
@property (nonatomic, strong) NSString *location_country;
@property (nonatomic, strong) NSString *location_zip;
@property (nonatomic, strong) NSString *sex;
@property (nonatomic, strong) NSString *success_url;
@property (nonatomic, strong) NSString *default_goodsid;
@property (nonatomic, strong) NSArray  *hide_goodsid;
@property (nonatomic, strong) NSString *display_goodsid;
@property (nonatomic, strong) NSString *pingback_url;

@end
