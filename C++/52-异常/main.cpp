//
//  main.cpp
//  52-异常
//
//  Created by wangfh on 2019/5/22.
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
void config (void) {
    A a;
    FILE* fp = fopen ("foo.cfg", "r");
    if (fp == NULL) {
        cout << "在throw之前" << endl;
        throw 100;
        cout << "在throw之后" << endl;
    }
    fclose (fp);
}
void init (void) {
    config ();
}


int main (void) {
    /*
     int n = setjmp (g_env);
     if (n == 100) {
     cout << "初始化失败！" << endl;
     return -1;
     }
     */
    try {
        cout << "调用init()之前" << endl;
        init ();
        cout << "调用init()之后" << endl;
    }
    catch (int ex) {
        if (ex == 100) {
            cout << "初始化失败！" << endl;
            return -1;
        }
    }
    return 0;
}
