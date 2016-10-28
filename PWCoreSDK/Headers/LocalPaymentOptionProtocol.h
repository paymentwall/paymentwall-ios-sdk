//
//  LocalPaymentOptionProtocol.h
//  PWCoreSDK
//
//  Created by Tien Nhat Vu on 10/14/16.
//  Copyright © 2016 Paymentwall. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol LocalPaymentOptionProtocol <NSObject>

-(void)makePayment;
-(NSString *)getPSName;
-(UIImage *)getLogoImage;
-(NSString *)getPSID;

@end
