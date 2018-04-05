//
//  PWCustomization.h
//  PWCoreSDK
//
//  Created by Tien Nhat Vu on 3/19/18.
//  Copyright © 2018 Paymentwall. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface PWCustomization : NSObject

#pragma mark - Common Customization
@property (nonatomic, assign) UIBarStyle barStyle;
@property (nonatomic, strong) UIFont *commonTextFont;
@property (nonatomic, strong) UIColor *commonTextColor;
@property (nonatomic, strong) UIColor *commonBackgroundColor;
@property (nonatomic, strong) UIImage *commonBackgroundImage;
@property (nonatomic, assign) UIViewContentMode commonBackgroundImageMode;
@property (nonatomic, strong) UIButton* commonButtonConfig;

#pragma mark - Header Customization
@property (nonatomic, strong) UIFont *infoTextFont;
@property (nonatomic, strong) UIColor *infoTextColor;
@property (nonatomic, strong) UIColor *infoBackgroundColor;
@property (nonatomic, strong) UIImage *infoBackgroundImage;
@property (nonatomic, assign) UIViewContentMode infoBackgroundImageMode;
@property (nonatomic, strong) UIColor *headerBackgroundColor;
@property (nonatomic, strong) UIImage *headerBackgroundImage;
@property (nonatomic, assign) UIViewContentMode headerBackgroundImageMode;

#pragma mark - Cell Customization
@property (nonatomic, strong) UIFont *cellTextFont;
@property (nonatomic, strong) UIColor *cellTextColor;
@property (nonatomic, strong) UIColor *cellHighlightColor;
@property (nonatomic, strong) UIColor *cellBackgroundColor;
@property (nonatomic, strong) UIImage *cellBackgroundImage;
@property (nonatomic, assign) UIViewContentMode cellBackgroundImageMode;

#pragma mark - Loader Customization
@property (nonatomic, strong) UIColor *loaderBackgroundColor;
@property (nonatomic, strong) UIImage *loaderBackgroundImage;
@property (nonatomic, assign) UIViewContentMode loaderBackgroundImageMode;

@property (nonatomic, strong) UIColor *loaderLoadingColor;
@property (nonatomic, strong) UIImage *loaderSuccessImage;
@property (nonatomic, strong) UIImage *loaderFailedImage;

@property (nonatomic, strong) UIFont *loaderTextFont;
@property (nonatomic, strong) UIFont *loaderSubTextFont;
@property (nonatomic, strong) UIColor *loaderSuccessTextColor;
@property (nonatomic, strong) UIColor *loaderFailedTextColor;
@property (nonatomic, strong) UIColor *loaderLoadingTextColor;
@property (nonatomic, strong) UIColor *loaderExtraMessageTextColor;

@end
