//
//  PWPaymentObject.h
//  PWCoreSDK
//
//  Created by Tien Nhat Vu on 1/18/18.
//  Copyright © 2018 Paymentwall. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface PWPaymentObject : NSObject

@property (copy, nonatomic) NSString* _Nonnull name;
@property (copy, nonatomic) NSDecimalNumber* _Nonnull price;
@property (copy, nonatomic) NSString* _Nonnull currency;
@property (strong, nonatomic) UIImage* _Nullable image;
@property (copy, nonatomic) NSString* _Nonnull itemID; //should only include alphanumeric
@property (copy, nonatomic) NSString* _Nonnull userID; //should only include alphanumeric

-(NSDictionary * _Nonnull)toDict;

@end
