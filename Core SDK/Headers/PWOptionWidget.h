//
//  PWOptionWidget.h
//  PWCoreSDK
//
//  Created by Tien Nhat Vu on 1/18/18.
//  Copyright © 2018 Paymentwall. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PWPaymentObject.h"
#import "PWConstants.h"

#import "PWWidgetCart.h"
#import "PWWidgetVirtualCurrency.h"
#import "PWWidgetDigitalGoodsDefaut.h"
#import "PWWidgetDigitalGoodsFlexible.h"

NS_ASSUME_NONNULL_BEGIN

@interface PWOptionWidget : NSObject

@property(nonatomic, copy) NSString* overrideProjectKey;
@property(nonatomic, copy) NSString* overrideSecretKey;
@property(nonatomic) PWSignatureType overrideSignVersion;

@property(nonatomic, strong) UIImage *widgetCellImage;

@property(nonatomic, strong) id extraParams;

/**
 Create the Widget Payment Option.
 
 @param type Widget type
 @return PWOptionWidget
 */
-(instancetype)initWithType:(PWWidgetType)type;

/**
 Create the Widget Payment Option.

 @param type Widget type
 @param params Can be either Dictionary/PWWidgetDigitalGoodsFlexible/PWWidgetDigitalGoodsDefaut/PWWidgetCart/PWWidgetVirtualCurrency type
 @return PWOptionWidget
 */
-(instancetype)initWithType:(PWWidgetType)type
                extraParams:(id)params;

-(instancetype)init NS_UNAVAILABLE;
+(instancetype)new NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
