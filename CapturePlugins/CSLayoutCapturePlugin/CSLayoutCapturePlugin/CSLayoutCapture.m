//
//  CSLayoutCapture.m
//  CSLayoutCapturePlugin
//
//  Created by Zakk on 8/11/17.
//  Copyright © 2017 Zakk. All rights reserved.
//

#import "CSLayoutCapture.h"
#import "CSPluginServices.h"
#import "CSIOSurfaceLayer.h"




@implementation CSLayoutCapture

+(NSString *)label
{
    return @"Layout";
}

-(NSArray *)availableVideoDevices
{
    NSObject *controller = [[CSPluginServices sharedPluginServices] captureController];
    NSMutableArray *ret = [NSMutableArray array];
    NSArray *layouts = [controller valueForKey:@"sourceLayouts"];
    for (NSObject *layout in layouts)
    {
        NSString *layoutName = [layout valueForKey:@"name"];
        
        CSAbstractCaptureDevice *dev = [[CSAbstractCaptureDevice alloc] initWithName:layoutName device:layout uniqueID:layoutName];
        [ret addObject:dev];
    }
    
    return ret;
}

-(void)setActiveVideoDevice:(CSAbstractCaptureDevice *)activeVideoDevice
{
    Class renderClass = NSClassFromString(@"LayoutRenderer");
    
    [super setActiveVideoDevice:activeVideoDevice];
    self.captureName = activeVideoDevice.captureName;
    NSObject *capDev = activeVideoDevice.captureDevice;
    SEL restoreSEL = NSSelectorFromString(@"restoreSourceList:");
    [capDev performSelector:restoreSEL withObject:nil];
    _current_renderer = [[renderClass alloc] init];
    [_current_renderer setValue:capDev forKey:@"layout"];
}

-(NSSize)captureSize
{
    if (self.activeVideoDevice)
    {
        SourceLayoutHack *capDev = self.activeVideoDevice.captureDevice;
        return NSMakeSize(capDev.canvas_width, capDev.canvas_height);
    }
    return NSZeroSize;
}

-(CALayer *)createNewLayer
{
    return [CALayer layer];
}

-(void)frameTick
{
    if (_current_renderer)
    {
        CVImageBufferRef pb = [_current_renderer currentImg];
        
        [self updateLayersWithFramedataBlock:^(CALayer *layer) {
            layer.contents = (__bridge id _Nullable)(pb);
            
        } withPreuseBlock:^{
            CFRetain(pb);
        } withPostuseBlock:^{
            CFRelease(pb);
        }];

    }
}

@end
