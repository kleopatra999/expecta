// Expecta - EXPExpect.h
// Copyright (c) 2011 Peter Jihoon Kim
// Licensed under the MIT License.

#import <Foundation/Foundation.h>

typedef id (^EXPIdBlock)();
typedef BOOL (^EXPBoolBlock)();
typedef NSString *(^EXPStringBlock)();

@interface EXPExpect : NSObject {
  EXPIdBlock _actualBlock;
  id _testCase;
  int _lineNumber;
  char *_fileName;
  BOOL _negative;
  BOOL _asynchronous;

  EXPBoolBlock _prerequisiteBlock;
  EXPBoolBlock _matchBlock;
  EXPStringBlock _failureMessageForToBlock;
  EXPStringBlock _failureMessageForNotToBlock;

  void (^prerequisite)(EXPBoolBlock block);
  void (^match)(EXPBoolBlock block);
  void (^failureMessageForTo)(EXPStringBlock block);
  void (^failureMessageForNotTo)(EXPStringBlock block);
}

@property(nonatomic, copy) EXPIdBlock actualBlock;
@property(nonatomic, readonly) id actual;
@property(nonatomic, assign) id testCase;
@property(nonatomic) int lineNumber;
@property(nonatomic) char *fileName;
@property(nonatomic) BOOL negative;
@property(nonatomic) BOOL asynchronous;

@property(nonatomic, readonly) EXPExpect *Not;
@property(nonatomic, readonly) EXPExpect *isGoing;
@property(nonatomic, readonly) EXPExpect *isNotGoing;

- (id)initWithActualBlock:(id)actualBlock testCase:(id)testCase lineNumber:(int)lineNumber fileName:(char *)fileName;
+ (EXPExpect *)expectWithActualBlock:(id)actualBlock testCase:(id)testCase lineNumber:(int)lineNumber fileName:(char *)fileName;

- (void)applyMatcher:(NSObject **)actual;

@end