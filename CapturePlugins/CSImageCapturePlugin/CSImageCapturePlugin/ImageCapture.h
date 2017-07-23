//
//  ImageCapture.h
//  CocoaSplit
//
//  Created by Zakk on 12/27/13.
//  Copyright (c) 2013 Zakk. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CSCaptureBase.h"


@interface ImageCapture : CSCaptureBase <CSCaptureSourceProtocol>
{
    
    NSArray *_sourceList;
    NSMutableArray *_delayList;
    CGImageSourceRef _imageSource;
    size_t _totalFrames;
    int _frameNumber;

    NSMutableArray *_imageCache;
    CAKeyframeAnimation *_animation;
    CGImageRef _singleImage;
    NSData *_imageData;
    bool _wasLoadedFromData;
    
    
    
}




@property (assign) double videoCaptureFPS;
@property (assign) int width;
@property (assign) int height;
@property (weak) id videoDelegate;

@property NSString *imagePath;


- (BOOL)needsAdvancedVideo;
-(void)chooseDirectory;




@end
