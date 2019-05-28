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

void swap(int &a,int &b) {
    int temp = a;
    a = b ;
    b = temp;
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
    
    cout <<  "====================" << endl;
    
    //指针
    int age = 20;
    int *pAge = &age;
    cout <<*pAge << endl;
    *pAge = 30;
    cout << age <<endl;
    
    cout << "引用" << endl;
    //引用
    int age1 = 20;
    //定义一个引用,相当于变量的别名
    int &rAge = age1;
    rAge = 40;
    cout << rAge <<endl;
    cout << rAge <<endl;
    
    int array[] ={1,2,3};
    int (&arr)[3] = array;
    cout << arr << endl;
    
    int v1 = 10;
    int v2 = 20;
    swap(v1, v2);
    cout << v1 << v2 <<endl;
    
    return 0;
}
