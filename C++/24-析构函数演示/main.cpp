//
//  main.cpp
//  24-析构函数演示
//
//  Created by wangfh on 2019/5/5.
//  Copyright © 2019 Ne. All rights reserved.
//

#include <iostream>
using namespace std;

class A {
    
public:
    A(void) {
        cout << "A的构造函数" << endl;
    }
    ~A(void) {
        cout << "A的析构函数" << endl;
    }
};

//定义一个全局变量,观察下程序的输出
//A g_a;
/*
 A的构造函数
 main()函数
 A的析构函数
 */

class B {
private:
    A m_a;
public:
    B(void) {
        cout << "B的构造函数" << endl;
    }
    ~B(void) {
        cout << "B的析构函数" << endl;
    }
};

class C {
private:
    A* m_pa;
public:
    C(void) : m_pa(new A) {
        cout << "C的构造函数" << endl;
    }
    ~C(void) {
        cout << "C的析构函数" << endl;
        delete m_pa;
    }
};

int main(int argc, const char * argv[]) {
    cout << "main()函数开始" << endl;
    //定义一个局部变量,观察下程序的输出
//    for (int i = 0; i< 5; i++) {
//          A a;
//    }
    
//    A *pa = new A[3];
//    cout << "在new和delete之间" << endl;
//    delete[] pa;

    //
//    B b;
    
    //对于动态分配的资源必须通过自己定义的析构函数进行释放
    C c;
    cout << "main()函数返回" << endl;
    
    return 0;
}
