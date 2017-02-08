//
//  PWCoreSDKSigning.h
//  PWCoreSDK
//
//  Created by Tien Nhat Vu on 10/19/16.
//  Copyright © 2016 Paymentwall. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface PWCoreSDKSigning : NSObject

/**
 Sign with MD5, sign version = 2

 @param variablesValue sign string
 @param secretKey      secret key

 @return signed string
 */
+(NSString *) signVersion2WithVariables: (NSMutableDictionary*) variablesValue andSecretKey:(NSString*) secretKey;
    
    
/**
 Sign with SHA256, sign version = 3

 @param variablesValue sign string
 @param secretKey      secret key
 
 @return signed string
 */
+(NSString *) signVersion3WithVariables: (NSMutableDictionary*) variablesValue andSecretKey:(NSString*) secretKey;


@end
