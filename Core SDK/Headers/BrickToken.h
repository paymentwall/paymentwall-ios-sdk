//
//  BrickToken.h
//  Brick
//
//  Copyright (c) 2014 Paymentwall. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface BrickToken : NSObject

@property (nonatomic, strong) NSString *type;
@property (nonatomic, strong) NSString *token;
@property (nonatomic, assign) int expriesIn;
@property (nonatomic, assign) int active;
@property (nonatomic, strong) NSString *cardType;
@property (nonatomic, strong) NSString *cardLast4Pin;
@property (nonatomic, strong) NSString *cardBin;
@property (nonatomic, strong) NSString *cardExpMonth;
@property (nonatomic, strong) NSString *cardExpYear;
@property (nonatomic, strong) NSString *email;

-(id)initWithAttributeDictionary:(NSDictionary *) dictionary;

@end
