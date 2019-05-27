//
//  main.cpp
//  62-externC
//
//  Created by wangfh on 2019/5/27.
//  Copyright © 2019 Ne. All rights reserved.
//

#include <iostream>
#include "math.h"
#include "other.h"

using namespace std;

/*
 什么时候会用到extern C?
 比如我们使用的第三方框架,或者库,可能是用C语言写的
 */

//但是一般不这么处理,比如我的库有很多方法,那这里都需要声明一遍 ,明显很麻烦
//extern "C" {
//    int sum(int v1,int v2);
//    int delta(int v1,int v2);
//}

int main(int argc, const char * argv[]) {
    cout <<  sum(10, 20) << endl;;
    cout << delta(20, 10) << endl;
    cout << "C语言的调用";
    other();
    return 0;
}
