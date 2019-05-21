//
//  main.cpp
//  47-虚析构函数
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
    ~A (void) {
        cout << "A析构" << endl;
    }
};

class X {
public:
    virtual ~X (void) {}
};

class Y : public X {
private:
    A m_a;
};

int main (void) {
    X* py = new Y;
    delete py;
    return 0;
}
