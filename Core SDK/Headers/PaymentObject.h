//
//  PaymentObject.h
//  PWCoreSDK
//
//  Created by Tien Nhat Vu on 10/5/16.
//  Copyright © 2016 Paymentwall. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface PaymentObject : NSObject

@property (strong, nonatomic) NSString* _Nonnull name;
@property (assign, nonatomic) double price;
@property (strong, nonatomic) NSString* _Nonnull currency;
@property (strong, nonatomic) UIImage* _Nullable image;
@property (strong, nonatomic) NSString* _Nonnull itemID;
@property (strong, nonatomic) NSString* _Nonnull userID;
@property (assign, nonatomic) int signVersion; //2 for md5, 3 for sha256
@property (strong, nonatomic) id _Nullable pwLocalParams; //Can be Dictionary or any of the defined class, refer their headers for required property or [PWLocal docs]: https://www.paymentwall.com/en/documentation/Digital-Goods-API/710 "PWLocal params". If this object is custom Dictionary, key like prices, amount, currencyCode, currencies, ag_name, ag_external_id, uid will be ignored

@end
