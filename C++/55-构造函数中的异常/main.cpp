//
//  main.cpp
//  55-构造函数中的异常
//
//  Created by wangfh on 2019/5/22.
//  Copyright © 2019 Ne. All rights reserved.
//

#include <iostream>
#include <memory>
using namespace std;

class A {
public:
    A (void) {
        cout << "A构造" << endl;
    }
    ~A (void) {
        cout << "A析构" << endl;
    }
};

class B {
public:
    B (void) : m_pa (new A) {
        cout << "B构造" << endl;
//        delete m_pa; //如果在抛出异常之前动态分配的对象，应该在throw之前将其释放
        throw -1;
    }
    ~B (void) {
        cout << "B析构" << endl;
//        throw -3;
//                delete m_pa;
    }
    void foo (void) {
        throw -2;
    }
    auto_ptr<A> m_pa; //如果使用智能指针,就可以throw前,不用delete
};

int main (void) {
    try {
        B b;
        b.foo ();
    }
    catch (int ex) {
        cout << "异常：" << ex << endl;
    }
    return 0;
}
