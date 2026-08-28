//
//  PWLog.h
//  PWCoreSDK
//
//  Created by Eric Vu on 8/20/26.
//  Copyright © 2026 Paymentwall. All rights reserved.
//

#import <Foundation/Foundation.h>

/// How much the SDK reports about its own network activity.
typedef NS_ENUM(NSUInteger, PWLogLevel) {
    /// Nothing is logged. The default, and what a shipped app should stay at.
    PWLogLevelNone = 0,
    /// Failures only.
    PWLogLevelError,
    /// Failures, plus one line per request and per response.
    PWLogLevelInfo
};

NS_ASSUME_NONNULL_BEGIN

/// The SDK's logger, built so that **logging a request body is not possible**, rather than merely
/// discouraged.
///
/// There is no string parameter anywhere in this API. Callers describe an **event** — a URL, a
/// status code, an error — and this class decides what may be printed. The URL has its **query
/// stripped** first, because Paymentwall's GET requests carry parameters and a signed GET carries
/// the signature.
///
/// Set the level through `-[PWCoreSDK setLogLevel:]`, the one public entry point.
@interface PWLog : NSObject

+(void)setLevel:(PWLogLevel)level;
+(PWLogLevel)level;

/// Logs the method and the URL **without its query**.
+(void)logRequestStart:(NSURL *)url method:(NSString *)method;

/// Logs the URL without its query, the status code, and how long it took.
+(void)logResponse:(nullable NSURL *)url statusCode:(NSInteger)statusCode duration:(NSTimeInterval)duration;

/// Logs an error's domain and code. **Not `localizedDescription`** — a server-supplied message can
/// quote back a parameter value, and that is how a body reaches a log by accident.
+(void)logFailure:(NSError *)error forURL:(nullable NSURL *)url;

@end

NS_ASSUME_NONNULL_END
