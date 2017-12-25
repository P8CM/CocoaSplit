//
//  CSTransitionAnimationDelegate.h
//  CocoaSplit
//
//  Created by Zakk on 4/16/17.
//  Copyright © 2017 Zakk. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <Quartz/Quartz.h>
#import "SourceLayout.h"

@interface CSTransitionAnimationDelegate : NSObject <CAAnimationDelegate>
@property (strong) NSArray *changedInputs;
@property (strong) NSArray *removedInputs;
@property (strong) NSArray *addedInputs;
@property (strong) NSArray *changeremoveInputs;

@property (strong) CAAnimation *useAnimation;
@property (assign) bool fullScreen;

@property (weak) SourceLayout *forLayout;

-(void)animationDidStart:(CAAnimation *)anim;
-(void)animationDidStop:(CAAnimation *)anim finished:(BOOL)flag;

@end
