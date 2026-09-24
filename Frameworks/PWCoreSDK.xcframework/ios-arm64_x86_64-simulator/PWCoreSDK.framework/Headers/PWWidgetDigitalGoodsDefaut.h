//
//  PWWidgetDigitalGoodsDefaut.h
//  PWLocalSDK
//
//  Created by Cong Tran on 6/15/15.
//  Copyright (c) 2015 Paymentwall. All rights reserved.
//

#import <Foundation/Foundation.h>

// Optional widget parameters: set the ones your flow needs and leave the rest nil. Each is
// explicitly `nullable`, so Swift imports them as real optionals.
NS_ASSUME_NONNULL_BEGIN

@interface PWWidgetDigitalGoodsDefaut : NSObject

@property (nonatomic, strong) NSString * _Nullable widget;                 //Required
@property (nonatomic, strong) NSString * _Nullable ps;
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
@property (nonatomic, strong) NSString * _Nullable default_goodsid;
@property (nonatomic, strong) NSArray<NSString *> * _Nullable hide_goodsid;
@property (nonatomic, strong) NSString * _Nullable display_goodsid;
@property (nonatomic, strong) NSString * _Nullable pingback_url;

@end

NS_ASSUME_NONNULL_END
