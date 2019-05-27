//
//  math.h
//  62-externC
//
//  Created by wangfh on 2019/5/27.
//  Copyright © 2019 Ne. All rights reserved.
//

#ifndef math_h //防止重复包含
#define math_h

#ifdef __cplusplus //条件编译,如果是c++文件调用,才参与编译
extern "C" {
#endif
    int sum(int v1,int v2);
    int delta(int v1,int v2);
    int divide(int v1,int v2);
#ifdef __cplusplus
}
#endif

#endif
