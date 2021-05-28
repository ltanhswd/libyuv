//
//  ViewController.swift
//  ExampleSwift
//
//  Created by caojianhua on 15/9/20.
//  Copyright © 2015年 libyuv. All rights reserved.
//

import UIKit
import libyuv

class ViewController: UIViewController {

  override func viewDidLoad() {
    super.viewDidLoad()
    // Do any additional setup after loading the view, typically from a nib.

    let testNV12 = NV12ToI420Scaler()
//    let ahihi = testNV12.convertNV12(toI420Scale: 8, src_stride_y: 8, src_uv: 8, src_stride_uv: 8, src_width: 8, src_height: 8, dst_y: 8, dst_stride_y: 8, dst_u: 8, dst_stride_u: 8, dst_v: 8, dst_stride_v: 8, dst_width: 8, dst_height: 8)
//    print(ahihi)
    
    
    var aha: UInt8 = 4
    testNV12.test(&aha)
    
    print(aha)
  }

  override func didReceiveMemoryWarning() {
    super.didReceiveMemoryWarning()
    // Dispose of any resources that can be recreated.
  }


}

