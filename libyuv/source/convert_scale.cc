/*
 *  Copyright 2011 The LibYuv Project Authors. All rights reserved.
 *
 *  Use of this source code is governed by a BSD-style license
 *  that can be found in the LICENSE file in the root of the source
 *  tree. An additional intellectual property rights grant can be found
 *  in the file PATENTS. All contributing project authors may
 *  be found in the AUTHORS file in the root of the source tree.
 */

#include "libyuv/convert_scale.h"
#include "libyuv/convert.h"
#include "libyuv/basic_types.h"
#include "libyuv/cpu_id.h"
#include "libyuv/planar_functions.h"
#include "libyuv/rotate.h"
#include "libyuv/row.h"
#include <vector>
#include "libyuv/scale.h"     // For ScalePlane()
#include "libyuv/scale_uv.h"  // For UVScale()

#ifdef __cplusplus
namespace libyuv {
extern "C" {
#endif

void NV12ToI420Scaler::NV12ToI420Scale(const uint8_t* src_y,
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
                                       int dst_height) {
  if (src_width == dst_width && src_height == dst_height) {
    // No scaling.
    tmp_uv_planes_.clear();
    tmp_uv_planes_.shrink_to_fit();
      
    libyuv::NV12ToI420(src_y, src_stride_y, src_uv, src_stride_uv, dst_y,
                       dst_stride_y, dst_u, dst_stride_u, dst_v, dst_stride_v,
                       src_width, src_height);
    return;
  }

  // Scaling.
  // Allocate temporary memory for spitting UV planes.
  const int src_uv_width = (src_width + 1) / 2;
  const int src_uv_height = (src_height + 1) / 2;
  tmp_uv_planes_.resize(src_uv_width * src_uv_height * 2);
  tmp_uv_planes_.shrink_to_fit();

  // Split source UV plane into separate U and V plane using the temporary data.
  uint8_t* const src_u = tmp_uv_planes_.data();
  uint8_t* const src_v = tmp_uv_planes_.data() + src_uv_width * src_uv_height;
  libyuv::SplitUVPlane(src_uv, src_stride_uv, src_u, src_uv_width, src_v,
                       src_uv_width, src_uv_width, src_uv_height);

  // Scale the planes into the destination.
  libyuv::I420Scale(src_y, src_stride_y, src_u, src_uv_width, src_v,
                    src_uv_width, src_width, src_height, dst_y, dst_stride_y,
                    dst_u, dst_stride_u, dst_v, dst_stride_v, dst_width,
                    dst_height, libyuv::kFilterBox);
}

#ifdef __cplusplus
}  // extern "C"
}  // namespace libyuv
#endif
