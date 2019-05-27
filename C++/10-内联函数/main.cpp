//
//  main.cpp
//  10-内联函数
//
//  Created by wangfh on 2019/4/28.
//  Copyright © 2019 Ne. All rights reserved.
//

#include <iostream>
using namespace std;

//inline的功能和宏类似,但是inline在写的时候,会有语法检测
//#define SUM(a,b) ((a)+(b))

#define SQUARE(X) X*X

//内联函数 性能很高,会直接把编译好的二进制代码嵌入到你调用的代码处,不是函数调用了,相当于直接把函数里的代码,直接复制过来
//显示内联函数:通过inline关键字声明的内联函数叫显示内联
//如果函数的代码很多,或者是递归,即使你声明了为inline,但编译器也有可能不会帮你去做转化
inline int square(int X) {
    return X * X;
}

//inline既可以只加到声明,也可以只加到实现,最好两个都加
inline void test();

int main(int argc, const char * argv[]) {
    cout <<  SQUARE(3) << endl;
    cout <<  SQUARE(2+3) << endl; //11 很明显不是想要的结果 这是宏的缺陷 2 + 3 * 2 + 3 = 11
    
    test();
    
    cout << square(2+3) << endl;
    return 0;
}

void test() {
    cout <<"测试inline" <<endl;
}
