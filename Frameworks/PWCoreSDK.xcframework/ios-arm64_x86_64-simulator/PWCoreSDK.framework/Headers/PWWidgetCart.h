//
//  CartDefaultWidget.h
//  PWLocalSDK
//
//  Created by Cong Tran on 6/15/15.
//  Copyright (c) 2015 Paymentwall. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PWPaymentObject.h"

// Optional widget parameters: set the ones your flow needs and leave the rest nil. Each is
// explicitly `nullable`, so Swift imports them as real optionals.
NS_ASSUME_NONNULL_BEGIN

@interface PWWidgetCart : NSObject

@property (nonatomic, strong) NSString * _Nullable widget;                 //Required
@property (nonatomic, strong) NSString * _Nullable firstname;
@property (nonatomic, strong) NSString * _Nullable lastname;
@property (nonatomic, strong) NSString * _Nullable email;
@property (nonatomic, strong) NSString * _Nullable evaluation;
@property (nonatomic, strong) NSString * _Nullable birthday;
@property (nonatomic, strong) NSString * _Nullable sex;
@property (nonatomic, strong) NSString * _Nullable location_city;
@property (nonatomic, strong) NSString * _Nullable location_state;
@property (nonatomic, strong) NSString * _Nullable location_address;
@property (nonatomic, strong) NSString * _Nullable location_country;
@property (nonatomic, strong) NSString * _Nullable location_zip;
@property (nonatomic, strong) NSString * _Nullable sign;
@property (nonatomic, strong) NSString * _Nullable pingback_url;

@end

NS_ASSUME_NONNULL_END
