//
//  NV12ToI420Scaler.h
//  libyuv
//
//  Created by Anh Le on 28/05/2021.
//  Copyright © 2021 libyuv. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NV12ToI420Scaler : NSObject

- (void)convertNV12toI420Scale:(UInt8*)src_y
                        src_stride_y:(int)src_stride_y
                        src_uv:(UInt8*)src_uv
                        src_stride_uv:(int)src_stride_uv
                        src_width:(int)src_width
                        src_height:(int)src_height
                        dst_y:(UInt8*)dst_y
                        dst_stride_y:(int)dst_stride_y
                        dst_u:(UInt8*)dst_u
                        dst_stride_u:(int)dst_stride_u
                        dst_v:(UInt8*)dst_v
                        dst_stride_v:(int)dst_stride_v
                        dst_width:(int)dst_width
                        dst_height:(int)dst_height;

- (void)test:(UInt8*)ahihi;

@end

NS_ASSUME_NONNULL_END
