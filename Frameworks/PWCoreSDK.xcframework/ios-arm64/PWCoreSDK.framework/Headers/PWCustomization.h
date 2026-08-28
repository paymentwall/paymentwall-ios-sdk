//
//  PWCustomization.h
//  PWCoreSDK
//
//  Created by Tien Nhat Vu on 3/19/18.
//  Copyright © 2018 Paymentwall. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

// EVERY property here is `nullable`: a customization is a set of OVERRIDES, and you set only the
// ones your design needs. The nullability is declared rather than left unspecified so that Swift
// imports these as real optionals - an unannotated pointer imports as an implicitly-unwrapped
// optional, which gives the caller a crash instead of a diagnostic.
NS_ASSUME_NONNULL_BEGIN

@interface PWCustomization : NSObject

#pragma mark - Common Customization
@property (nonatomic, assign) UIBarStyle barStyle;
@property (nonatomic, strong) UIFont * _Nullable commonTextFont;
@property (nonatomic, strong) UIColor * _Nullable commonTextColor;
@property (nonatomic, strong) UIColor * _Nullable commonBackgroundColor;
@property (nonatomic, strong) UIImage * _Nullable commonBackgroundImage;
@property (nonatomic, assign) UIViewContentMode commonBackgroundImageMode;
@property (nonatomic, strong) UIButton* commonButtonConfig;

#pragma mark - Header Customization
@property (nonatomic, strong) UIFont * _Nullable infoTextFont;
@property (nonatomic, strong) UIColor * _Nullable infoTextColor;
@property (nonatomic, strong) UIColor * _Nullable infoBackgroundColor;
@property (nonatomic, strong) UIImage * _Nullable infoBackgroundImage;
@property (nonatomic, assign) UIViewContentMode infoBackgroundImageMode;
@property (nonatomic, strong) UIColor * _Nullable headerBackgroundColor;
@property (nonatomic, strong) UIImage * _Nullable headerBackgroundImage;
@property (nonatomic, assign) UIViewContentMode headerBackgroundImageMode;

#pragma mark - Cell Customization
@property (nonatomic, strong) UIFont * _Nullable cellTextFont;
@property (nonatomic, strong) UIColor * _Nullable cellTextColor;
@property (nonatomic, strong) UIColor * _Nullable cellHighlightColor;
@property (nonatomic, strong) UIColor * _Nullable cellBackgroundColor;
@property (nonatomic, strong) UIImage * _Nullable cellBackgroundImage;
@property (nonatomic, assign) UIViewContentMode cellBackgroundImageMode;

#pragma mark - Loader Customization
@property (nonatomic, strong) UIColor * _Nullable loaderBackgroundColor;
@property (nonatomic, strong) UIImage * _Nullable loaderBackgroundImage;
@property (nonatomic, assign) UIViewContentMode loaderBackgroundImageMode;

@property (nonatomic, strong) UIColor * _Nullable loaderLoadingColor;
@property (nonatomic, strong) UIImage * _Nullable loaderSuccessImage;
@property (nonatomic, strong) UIImage * _Nullable loaderFailedImage;

@property (nonatomic, strong) UIFont * _Nullable loaderTextFont;
@property (nonatomic, strong) UIFont * _Nullable loaderSubTextFont;
@property (nonatomic, strong) UIColor * _Nullable loaderSuccessTextColor;
@property (nonatomic, strong) UIColor * _Nullable loaderFailedTextColor;
@property (nonatomic, strong) UIColor * _Nullable loaderLoadingTextColor;
@property (nonatomic, strong) UIColor * _Nullable loaderExtraMessageTextColor;

@end

NS_ASSUME_NONNULL_END
