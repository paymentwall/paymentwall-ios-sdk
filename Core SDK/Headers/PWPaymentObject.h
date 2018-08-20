//
//  PWPaymentObject.h
//  PWCoreSDK
//
//  Created by Tien Nhat Vu on 1/18/18.
//  Copyright © 2018 Paymentwall. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface PWPaymentObject : NSObject

@property (copy, nonatomic, readonly) NSString* name;
@property (copy, nonatomic, readonly) NSDecimalNumber* price;
@property (copy, nonatomic, readonly) NSString* currency;
@property (strong, nonatomic, readonly) UIImage* _Nullable image;
@property (copy, nonatomic, readonly) NSString* itemID; //should only include alphanumeric
@property (copy, nonatomic, readonly) NSString* userID; //should only include alphanumeric

-(instancetype)initWithName:(NSString *)name
                      price:(NSDecimalNumber *)price
                     itemID:(NSString *)itemID
                     userID:(NSString *)userID
                   currency:(NSString *)currency
                      image:(UIImage *_Nullable)image;


-(NSDictionary *)toDict;

@end

NS_ASSUME_NONNULL_END
