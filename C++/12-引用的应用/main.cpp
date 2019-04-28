//
//  main.cpp
//  12-引用的应用
//
//  Created by wangfh on 2019/4/28.
//  Copyright © 2019 Ne. All rights reserved.
//

#include <iostream>
using namespace std;

void foo(int n) {
    n = 100;
}

void foo1(int *n) {
    *n = 100;
}

void foo2(int &n) {
    n = 200;
}

void foo3(char *psz) {
    psz = "b";
}

void foo4(char **psz) {
    *psz = "c";
}

void foo5(char *&psz) {
    psz = "d";
}

int main(int argc, const char * argv[]) {
    int n = 10;
    foo(n);
    cout << n << endl; //值传递 并不会改变值
    
    foo1(&n);
    cout << n << endl; //指针传递
    
    foo2(n);
    cout << n <<endl; //引用传递
    

    char *psz = "a";
    foo3(psz);
    cout << *psz << endl;
    
    foo4(&psz);
    cout << *psz << endl;
    
    foo5(psz);
    cout << *psz << endl;
    return 0;
}
