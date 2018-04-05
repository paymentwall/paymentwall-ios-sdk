//
//  PWWidgetDigitalGoodsFlexible.h
//  PWLocalSDK
//
//  Created by Cong Tran on 6/15/15.
//  Copyright (c) 2015 Paymentwall. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface PWWidgetDigitalGoodsFlexible : NSObject

@property (nonatomic, strong) NSString *widget;                                 //Required
@property (nonatomic, strong) NSString *ps;
@property (nonatomic, strong) NSString *ag_type;                                //Required
@property (nonatomic, strong) NSString *ag_period_length;                       //Required*
@property (nonatomic, strong) NSString *ag_period_type;                         //Required
@property (nonatomic, strong) NSString *ag_recurring;
@property (nonatomic, strong) NSString *ag_promo;
@property (nonatomic, strong) NSString *ag_trial;
@property (nonatomic, strong) NSString *ag_post_trial_period_length;
@property (nonatomic, strong) NSString *ag_post_trial_period_type;
@property (nonatomic, strong) NSString *ag_post_trial_external_id;
@property (nonatomic, strong) NSString *post_trial_amount;
@property (nonatomic, strong) NSString *post_trial_currencyCode;
@property (nonatomic, strong) NSString *ag_post_trial_name;
@property (nonatomic, strong) NSString *hide_post_trial_good;
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
@property (nonatomic, strong) NSString *pingback_url;
@property (nonatomic, strong) NSString *show_trial_non_recurring;
@property (nonatomic, strong) NSString *show_trial_recurring;
@property (nonatomic, strong) NSString *show_post_trial_non_recurring;
@property (nonatomic, strong) NSString *show_post_trial_recurring;
@end
