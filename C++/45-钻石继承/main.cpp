//
//  main.cpp
//  45-钻石继承
//
//  Created by wangfh on 2019/5/21.
//  Copyright © 2019 Ne. All rights reserved.
//

#include <iostream>
using namespace std;

class A {
public:
    A (int n) : m_n (n) {
        cout << "A构造n=" << n << endl;
    }
    int m_n;
};

//如果后边继承的子类B,C 不加virtual的话 B继承的A和C继承的A,会导致有两个A,所以通过B的set方法改变m_n的值后,通过C的get方法去取,取到的还是旧值
class B : virtual public A {
public:
    B (int n) : A (n) {
        cout << "B构造" << endl;
    }
    void set (int n) {
        m_n = n;
    }
    void foo (void) {
        cout << "B的foo()函数" << endl;
    }
};

class C : virtual public A {
public:
    C (int n) : A (n) {
        cout << "C构造" << endl;
    }
    int get (void) {
        return m_n;
    }
    void foo (char c) {
        cout << "C的foo()函数" << endl;
    }
};

class D : public B, public C {
public:
    D (int n) : B (1000), C (2000), A (n) {
        cout << "D构造" << endl;
    }
    double foo (char c, int n) {
        cout << "D的foo()函数" << endl;
        B::foo ();
        C::foo (c);
        return 0.0;
    }
};

int main (void) {
    D d (100);
    cout << d.get () << endl; // 100
    d.set (200);
    cout << d.get () << endl; // 100 ?
    d.C::foo ('A');
    d.foo ('A', 10);
    return 0;
}

