//
//  AppDelegate.h
//  H264Streamer
//
//  Created by Zakk on 9/2/12.
//  Copyright (c) 2012 Zakk. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import "CaptureController.h"
#import "CSUserNotificationController.h"


@interface AppDelegate : NSObject <NSApplicationDelegate>
{
    CSUserNotificationController *_notificationController;
    
}
@property (unsafe_unretained) IBOutlet CaptureController *captureController;

@property (unsafe_unretained) IBOutlet NSWindow *window;

@property (weak) IBOutlet NSButton *layoutSequenceButton;


-(void)changeAppearance;

@end
