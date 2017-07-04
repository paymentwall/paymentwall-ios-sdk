//
//  PWMyCardPlugin.h
//  PWMyCardPlugin
//
//  Created by Tien Nhat Vu on 6/6/17.
//  Copyright © 2017 Paymentwall. All rights reserved.
//

#import <Foundation/Foundation.h>

extern NSString * _Nonnull const MYCARD_SIGNATURE_GENERATED;

@interface PWMyCardPlugin : NSObject

///Optional
@property (nonatomic, strong) NSString* _Nullable pwProjectKey; //If nil, use default key from PWCoreSDK
@property (nonatomic, strong) NSString* _Nullable pwSecretKey; //If nil, use default key from PWCoreSDK, if both nil, assign `signString` property below before showing payment dialog

-(NSString * _Nullable)getStringToSign; //Call after you assign all required value AND setup PaymentObject in order to get string to sign. If you use this feature, you have to keep this class instance pointer to assign new signString everytime after new payment object is set
@property (nonatomic, strong) NSString* _Nonnull signString; //Use this property only if you want to calculate sign by your app or server

@end

