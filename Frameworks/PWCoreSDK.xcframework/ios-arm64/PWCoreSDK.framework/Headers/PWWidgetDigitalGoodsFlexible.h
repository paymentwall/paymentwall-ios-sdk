//
//  PWWidgetDigitalGoodsFlexible.h
//  PWLocalSDK
//
//  Created by Cong Tran on 6/15/15.
//  Copyright (c) 2015 Paymentwall. All rights reserved.
//

#import <Foundation/Foundation.h>

// These are OPTIONAL widget parameters - you set the ones your flow needs - so they are declared
// `nullable` rather than left unspecified. An unspecified pointer imports into Swift as an
// implicitly-unwrapped optional, which gives the caller a crash instead of a diagnostic.
NS_ASSUME_NONNULL_BEGIN

@interface PWWidgetDigitalGoodsFlexible : NSObject

@property (nonatomic, strong) NSString * _Nullable widget;                                 //Required
@property (nonatomic, strong) NSString * _Nullable ps;
@property (nonatomic, strong) NSString * _Nullable ag_type;                                //Required
@property (nonatomic, strong) NSString * _Nullable ag_period_length;                       //Required*
@property (nonatomic, strong) NSString * _Nullable ag_period_type;                         //Required
@property (nonatomic, strong) NSString * _Nullable ag_recurring;
@property (nonatomic, strong) NSString * _Nullable ag_promo;
@property (nonatomic, strong) NSString * _Nullable ag_trial;
@property (nonatomic, strong) NSString * _Nullable ag_post_trial_period_length;
@property (nonatomic, strong) NSString * _Nullable ag_post_trial_period_type;
@property (nonatomic, strong) NSString * _Nullable ag_post_trial_external_id;
@property (nonatomic, strong) NSString * _Nullable post_trial_amount;
@property (nonatomic, strong) NSString * _Nullable post_trial_currencyCode;
@property (nonatomic, strong) NSString * _Nullable ag_post_trial_name;
@property (nonatomic, strong) NSString * _Nullable hide_post_trial_good;
@property (nonatomic, strong) NSString * _Nullable ts;
@property (nonatomic, strong) NSString * _Nullable sign;
@property (nonatomic, strong) NSString * _Nullable birthday;
@property (nonatomic, strong) NSString * _Nullable country_code;
@property (nonatomic, strong) NSString * _Nullable email;
@property (nonatomic, strong) NSString * _Nullable evaluation;
@property (nonatomic, strong) NSString * _Nullable firstname;
@property (nonatomic, strong) NSString * _Nullable lang;
@property (nonatomic, strong) NSString * _Nullable lastname;
@property (nonatomic, strong) NSString * _Nullable location_city;
@property (nonatomic, strong) NSString * _Nullable location_state;
@property (nonatomic, strong) NSString * _Nullable location_address;
@property (nonatomic, strong) NSString * _Nullable location_country;
@property (nonatomic, strong) NSString * _Nullable location_zip;
@property (nonatomic, strong) NSString * _Nullable sex;
@property (nonatomic, strong) NSString * _Nullable success_url;
@property (nonatomic, strong) NSString * _Nullable pingback_url;
@property (nonatomic, strong) NSString * _Nullable show_trial_non_recurring;
@property (nonatomic, strong) NSString * _Nullable show_trial_recurring;
@property (nonatomic, strong) NSString * _Nullable show_post_trial_non_recurring;
@property (nonatomic, strong) NSString * _Nullable show_post_trial_recurring;
@end

NS_ASSUME_NONNULL_END
