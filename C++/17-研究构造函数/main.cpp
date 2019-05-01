//
//  main.cpp
//  17-研究构造函数
//
//  Created by Ne on 2019/5/1.
//  Copyright © 2019 Ne. All rights reserved.
//

#include <iostream>
using namespace std;

class A {
public:
    A(void) {
        cout << "A被构造了" << endl;
    }
};

class B {
private:
    A m_a;
public:
    B(void) {
         cout << "B被构造了" << endl;
    }
};

int main(int argc, const char * argv[]) {
    //在构造自己的时候,会去构造自己的成员变量,所以A也会被调用
    B b;
    return 0;
}
