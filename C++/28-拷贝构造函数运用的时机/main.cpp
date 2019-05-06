//
//  main.cpp
//  28-拷贝构造函数运用的时机
//
//  Created by wangfh on 2019/5/6.
//  Copyright © 2019 Ne. All rights reserved.
//

#include <iostream>
using namespace std;

class A {
public:
    A(void) {}
    A(const A& a) {
        cout << "A的拷贝构造函数" << endl;
    }
};

//2. 函数调用传递对象型参数
void foo(A a) {
    
}

//3. 函数返回对象（受编译器优化的影响）
A bar(A a) {
    return a;
}

int main(int argc, const char * argv[]) {
    //1. 用同类的对象作初始
    A a1;
//    A a2(a1);
//    A a3 = a2;
//    A *pa = new A(a3);
//    delete pa;
    
//    foo(a1);
  
    bar(a1);
    return 0;
}
