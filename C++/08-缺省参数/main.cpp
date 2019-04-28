//
//  main.cpp
//  08-缺省参数
//
//  Created by wangfh on 2019/4/28.
//  Copyright © 2019 Ne. All rights reserved.
//

#include <iostream>
using namespace std;

void foo (void) {
    cout << "测试重载" <<endl;
}

//1.如果函数的参数表中某一个形参具有缺省值，那么其右的所有参数都必须有缺省值
void foo(int n = 10,double f = 0.1,char c = 'X') {
    cout << n << ","<< f << "," << c << endl;
}

//3.当函数的定义和声明分开的时候，缺省参数只能出现在函数的声明部分
void foo1(int n = 10,double f = 0.1,char c = 'X');

int main(int argc, const char * argv[]) {
    foo(10, 3.14, 'A');
    foo(20,3.15);
    foo(30);
//    foo(); //报错  2. 注意避免和重载发生冲突
    cout << "-----------" << endl;
    foo1();
    return 0;
}

void foo1(int n,double f,char c) {
     cout << n << ","<< f << "," << c << endl;
}
