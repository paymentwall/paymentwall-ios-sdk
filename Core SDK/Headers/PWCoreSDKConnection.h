//
//  PWCoreSDKConnection.h
//  PWCoreSDK
//
//  Created by Tien Nhat Vu on 10/19/16.
//  Copyright © 2016 Paymentwall. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef void (^PWCoreSDKConnectionCompletionBlock)(NSData *body, NSURLResponse *response, NSError *requestError);

@interface PWCoreSDKConnection : NSObject

- (void)fetchRequest:(NSURLRequest *)request withQueue:(NSOperationQueue *)queue completion:(PWCoreSDKConnectionCompletionBlock)handler;

@end
