/*
 *  Copyright 2011 The LibYuv Project Authors. All rights reserved.
 *
 *  Use of this source code is governed by a BSD-style license
 *  that can be found in the LICENSE file in the root of the source
 *  tree. An additional intellectual property rights grant can be found
 *  in the file PATENTS. All contributing project authors may
 *  be found in the AUTHORS file in the root of the source tree.
 */

#ifndef INCLUDE_LIBYUV_CONVERT_H_
#define INCLUDE_LIBYUV_CONVERT_H_

#include "libyuv/basic_types.h"

#include "libyuv/rotate.h"  // For enum RotationMode.
#include "libyuv/convert.h"
// TODO(fbarchard): fix WebRTC source to include following libyuv headers:
#include "libyuv/convert_argb.h"      // For WebRTC I420ToARGB. b/620
#include "libyuv/convert_from.h"      // For WebRTC ConvertFromI420. b/620
#include "libyuv/planar_functions.h"  // For WebRTC I420Rect, CopyPlane. b/618

#ifdef __cplusplus
namespace libyuv {
extern "C" {
#endif

// Helper class for directly converting and scaling NV12 to I420. The Y-plane
// will be scaled directly to the I420 destination, which makes this faster
// than separate NV12->I420 + I420->I420 scaling.
class NV12ToI420Scaler {
 public:
  NV12ToI420Scaler();
  ~NV12ToI420Scaler();
  void NV12ToI420Scale(const uint8_t* src_y,
                       int src_stride_y,
                       const uint8_t* src_uv,
                       int src_stride_uv,
                       int src_width,
                       int src_height,
                       uint8_t* dst_y,
                       int dst_stride_y,
                       uint8_t* dst_u,
                       int dst_stride_u,
                       uint8_t* dst_v,
                       int dst_stride_v,
                       int dst_width,
                       int dst_height);

 private:
  std::vector<uint8_t> tmp_uv_planes_;
};

#ifdef __cplusplus
}  // extern "C"
}  // namespace libyuv
#endif

#endif  // INCLUDE_LIBYUV_CONVERT_H_
