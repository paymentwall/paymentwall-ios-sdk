//
//  PWWidgetDigitalGoodsFlexible.h
//  PWLocalSDK
//
//  Created by Cong Tran on 6/15/15.
//  Copyright (c) 2015 Paymentwall. All rights reserved.
//

#import <Foundation/Foundation.h>

// Optional widget parameters: set the ones your flow needs and leave the rest nil. Each is
// explicitly `nullable`, so Swift imports them as real optionals.
NS_ASSUME_NONNULL_BEGIN

@interface PWWidgetDigitalGoodsFlexible : NSObject

/// Which set of payment methods the hosted checkout offers, e.g. `pw_1`. From your project's
/// Widgets page in the Paymentwall merchant area.
///
/// **Optional.** Omit it and Paymentwall offers whatever the project itself is configured to offer.
/// Set it to choose a specific widget — and note that a widget code belongs to one project, so it
/// travels with the project key it was created under.
@property (nonatomic, strong) NSString * _Nullable widget;
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
