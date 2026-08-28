//
//  PWHTTPTransport.h
//  PWCoreSDK
//
//  Copyright © 2026 Paymentwall. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// Called when a request finishes, on the `NSURLSession` delegate queue — **not** the main thread.
typedef void (^PWHTTPTransportCompletion)(NSData * _Nullable data,
                                          NSURLResponse * _Nullable response,
                                          NSError * _Nullable error);

/// Moves bytes, tracks what is in flight, and can cancel it. Nothing Paymentwall-specific.
///
/// **This is a type rather than a set of class methods so that cancellation scope follows
/// ownership.** A single shared transport would own one global in-flight set, so cancelling
/// everything in flight would also cancel an unrelated plugin's request. Each owner gets its own
/// transport instead, and `-cancelAllInFlightRequests` touches only that owner's requests.
///
/// A payment option implementing `PWPaymentOptionProtocol` is not handed the SDK's HTTP client, so
/// an option that needs to make a request creates one of these and owns it.
@interface PWHTTPTransport : NSObject

/// The session requests are issued on. Requests started by other transports are not visible here.
@property (nonatomic, strong, readonly) NSURLSession *session;

/// Uses `+[NSURLSession sharedSession]`.
-(instancetype)init;

/// Issues requests on `session` instead — the seam for pointing requests at a stub server in a
/// test.
-(instancetype)initWithURLSession:(NSURLSession *)session NS_DESIGNATED_INITIALIZER;

/// Issues `request`, retaining the task until it completes so it can be cancelled.
-(void)executeRequest:(NSURLRequest *)request completion:(PWHTTPTransportCompletion)completion;

/// Cancels everything this transport currently has in flight. Requests owned by another transport are
/// untouched — that separation is the reason this is an instance method.
-(void)cancelAllInFlightRequests;

/// How many requests this transport currently has in flight.
-(NSUInteger)inFlightRequestCount;

@end

NS_ASSUME_NONNULL_END
