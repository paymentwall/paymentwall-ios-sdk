//
//  PWCoreSDKDelegate.h
//  PWCoreSDK
//
//  Created by Tien Nhat Vu on 10/6/16.
//  Copyright © 2016 Paymentwall. All rights reserved.
//

#import <Foundation/Foundation.h>
@class PWCoreSDKResponse;

@protocol PWCoreSDKDelegate <NSObject>
@optional

-(void) paymentResponse:(PWCoreSDKResponse*) response;

@end

