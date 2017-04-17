//
//  PWLocalViewController.h
//  PWLocalSDK
//
//  Created by Cong Tran on 6/12/15.
//  Copyright (c) 2015 Paymentwall. All rights reserved.
//

#import <UIKit/UIKit.h>
@class VirtualCurrency;
@class DigitalGoodsDefautWidget;
@class DigitalGoodsFlexibleWidget;
@class PWLocalResponse;
@class CartDefaultWidget;
@class PWLocalStatusResponse;

typedef enum {
    VIRTUAL_CURRENCY,
    DIGITAL_GOODS,
    CART
} apiType;

typedef void (^PWLocalCompletionBlock)(int status);
typedef void (^PWLocalPaymentStatusCompletionBlock)(PWLocalStatusResponse *response);

@protocol PWLocalSDKDelegate <NSObject>

@optional
-(void) pwLocalResponse:(PWLocalResponse*) response;

@end


@interface PWLocalViewController : UIViewController


// API type, default is VIRTUAL_CURRENCY
@property (nonatomic, assign) int apiType;

// VituralCurrency
@property (nonatomic, strong) VirtualCurrency *virtualCurrency;

// DigitalGoodsDefautWidget
@property (nonatomic, strong) DigitalGoodsDefautWidget *digitalGoodsDefautWidget;

// DigitalGoodsFlexibleWidget
@property (nonatomic, strong) DigitalGoodsFlexibleWidget *digitalGoodsFlexibleWidget;

// CartDefaultWidget
@property (nonatomic, strong) CartDefaultWidget *cartDefaultWidget;

// Secret Key - for calculator signature
@property (nonatomic, strong) NSString *secretKey;

// Custom Request
@property (nonatomic, strong) NSDictionary *customRequestDictionary;

// app download link
@property(nonatomic, strong) NSString *appDownloadURL;

// delegate
@property(nonatomic, weak) id<PWLocalSDKDelegate> delegate;

// method
-(void)showPWLocalWithParentViewController:(UIViewController *)parentViewController completion:(PWLocalCompletionBlock)block;

@end
