//
//  main.cpp
//  44-继承中的析构
//
//  Created by wangfh on 2019/5/21.
//  Copyright © 2019 Ne. All rights reserved.
//

#include <iostream>
using namespace std;
class A {
public:
    A (void) {
        cout << "A构造" << endl;
    }
    virtual ~A (void) {
        cout << "A析构" << endl;
    }
    int m_n;
};

class B : public A {
public:
    B (void) {
        cout << "B构造" << endl;
    }
    ~B (void) {
        cout << "B析构" << endl;
    }
};
int main (void) {
    A* pb = new B;
    delete pb;
    return 0;
}
