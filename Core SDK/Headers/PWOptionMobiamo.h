//
//  PWOptionMobilamo.h
//  PWCoreSDK
//
//  Created by Tien Nhat Vu on 1/18/18.
//  Copyright © 2018 Paymentwall. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface PWOptionMobiamo : NSObject

@property(nonatomic, copy) NSString* overrideProjectKey;

/**
 Set to true to use default price for the current country
 */
@property(nonatomic, assign) BOOL useNoPrice;

@end

NS_ASSUME_NONNULL_END
