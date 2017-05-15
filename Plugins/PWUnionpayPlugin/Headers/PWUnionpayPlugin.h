//
//  PWUnionpayPlugin.h
//  PaymentwallUnionpaySDK
//
//  Created by Tien Nhat Vu on 10/19/16.
//  Copyright © 2016 Paymentwall. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface PWUnionpayPlugin : NSObject

//Optional
@property (nonatomic, strong) NSString* _Nullable pwProjectKey; //If nil, use default key from PWCoreSDK
@property (nonatomic, strong) NSString* _Nullable pwSecretKey; //If nil, use default key from PWCoreSDK, if both nil, assign `signString` property below before showing payment dialog
@property (nonatomic, assign) int signVersion; // 2 for MD5, 3 for SHA256

//Required
@property (nonatomic, strong) NSString* _Nonnull appScheme; //To redirect back from Unionpay app
@property (nonatomic, weak) UIViewController * _Nullable parentViewController;

-(NSString * _Nonnull)getStringToSign; //Call after you assign all required value to get string to sign
@property (nonatomic, strong) NSString* _Nonnull signString; //Use this property only if you want to calculate sign by your app or server

@end

