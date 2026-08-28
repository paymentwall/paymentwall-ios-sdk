//
//  PWCardScannerProtocol.h
//  PWCoreSDK
//
//  Created by Tien Nhat Vu on 3/9/18.
//  Copyright © 2018 Paymentwall. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#ifndef PWCardScannerProtocol_h
#define PWCardScannerProtocol_h

#pragma mark - Card scanner
@protocol PWCardScannerDelegate <NSObject>
@optional

- (void)cardScanned:(NSString *)scannedNumber scannedCVV:(NSString *)scannedCVV scannedMonth:(int)scannedMonth scannedYear:(int)scannedYear;

@end

@protocol PWCardScannerProtocol <NSObject>

@property (weak, nonatomic) id <PWCardScannerDelegate> delegate;
-(void)showCardScannerWithVC:(UIViewController *)vc;

@end

#endif /* PWCardScannerProtocol_h */
