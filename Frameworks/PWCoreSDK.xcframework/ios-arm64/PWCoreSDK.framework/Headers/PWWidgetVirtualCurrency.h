//
//  VituralCurrency.h
//  PWLocalSDK
//
//  Created by ; Tran on 6/15/15.
//  Copyright (c) 2015 Paymentwall. All rights reserved.
//

#import <Foundation/Foundation.h>

// Optional widget parameters: set the ones your flow needs and leave the rest nil. Each is
// explicitly `nullable`, so Swift imports them as real optionals.
NS_ASSUME_NONNULL_BEGIN

@interface PWWidgetVirtualCurrency : NSObject

@property (nonatomic, strong) NSString * _Nullable widget;             //Required
@property (nonatomic, strong) NSString * _Nullable ps;
@property (nonatomic, strong) NSString * _Nullable sign;
@property (nonatomic, strong) NSString * _Nullable birthday;
@property (nonatomic, strong) NSString * _Nullable email;
@property (nonatomic, strong) NSString * _Nullable sex;
@property (nonatomic, strong) NSString * _Nullable evaluation;
@property (nonatomic, strong) NSString * _Nullable location_city;
@property (nonatomic, strong) NSString * _Nullable location_state;
@property (nonatomic, strong) NSString * _Nullable location_address;
@property (nonatomic, strong) NSString * _Nullable location_country;
@property (nonatomic, strong) NSString * _Nullable location_zip;
@property (nonatomic, strong) NSString * _Nullable country_code;
@property (nonatomic, strong) NSString * _Nullable rv;
@property (nonatomic, strong) NSString * _Nullable th;
@property (nonatomic, strong) NSString * _Nullable tm;
@property (nonatomic, strong) NSString * _Nullable pingback_url;
@property (nonatomic, strong) NSString * _Nullable success_url;
@end

NS_ASSUME_NONNULL_END
