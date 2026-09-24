//
//  PWBrickCardinal3DSPlugin.h
//  PWBrick3DSPlugin
//
//  Copyright © 2026 Paymentwall. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PWBrick3DSProtocol.h"

NS_ASSUME_NONNULL_BEGIN

/// Native 3-D Secure 2, powered by the Cardinal Commerce mobile SDK.
///
/// ```
/// PWOptionBrick *brick = [[PWOptionBrick alloc] init];
/// [brick set3DSPlugin:[[PWBrickCardinal3DSPlugin alloc] init]];
/// ```
///
/// **Optional.** Without it the SDK shows the issuer's page in a web view, which is a complete
/// 3-D Secure flow — so adding this is an upgrade to a native challenge, not a requirement.
///
/// **Requires `CardinalMobile.xcframework` on your target.** It is a separate product; add both.
@interface PWBrickCardinal3DSPlugin : NSObject <PWBrick3DSProtocol>
@end

NS_ASSUME_NONNULL_END
