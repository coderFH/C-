//
//  main.cpp
//  10-内联函数
//
//  Created by wangfh on 2019/4/28.
//  Copyright © 2019 Ne. All rights reserved.
//

#include <iostream>
using namespace std;

#define SQUARE(X) X*X

//内联函数 性能很高,会直接把编译好的二进制代码嵌入到你调用的代码处,不是函数调用了
//显示内联函数:通过inline关键字声明的内联函数叫显示内联
inline int square(int X) {
    return X * X;
}

int main(int argc, const char * argv[]) {
    cout <<  SQUARE(3) << endl;
    cout <<  SQUARE(2+3) << endl; //11 很明显不是想要的结果 这是宏的缺陷 2 + 3 * 2 + 3 = 11
    
    cout << square(2+3) << endl;
    return 0;
}
