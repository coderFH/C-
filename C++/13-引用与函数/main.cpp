//
//  main.cpp
//  13-引用与函数
//
//  Created by Ne on 2019/4/28.
//  Copyright © 2019 Ne. All rights reserved.
//

#include <iostream>
using namespace std;

struct S {
    int arr[5];
};

void foo(int arr[],int size) {
    for (int i = 0; i<size; i++) {
        cout << arr[i] <<endl;
    }
    cout << endl;
}

//首先,如果不是用引用,就是普通的值传递,相当于把结构体拷贝一个副本出来,在bar()函数中操作,如果数组很大,很浪费时间
//所有使用引用,保证了操作的是同一个结构体,而不会是产生一个副本,很影响效率
//加const,保证了我们在整个函数中,不能去随意的修改数据
void bar(const S& s) {
//    s.arr[0] = 100;//不能修改结构体的值,因为有const修饰
}

#pragma mark ---引用型的返回值
int& foo1(void) {
    //任何时候都不要返回局部变量的引用（包括函数参数）
    int n = 100;//n是局部变量,函数销毁后,不保证这个地址还有效
    return n; //所以会报警告
}

int& foo2(void) {
    //可以返回 全局变量 静态变量 动态分配变量 成员变量 实参引用
    static int n = 200;
    return n;
}

int g = 300;
int& foo3(void) {
    return g;
}

int& foo4(void) {
    int* p = new int(100); //new在堆区创建,不会释放
    *p = 400;
    return *p;
}

int& foo5(int &r) {
    return r;
}

struct T {
    int n;
    int& foo(void) {
        return n;
    }
};

int main(int argc, const char * argv[]) {
    int arr[] = {1,2,3,4,5,6};
    foo(arr,sizeof(arr) / sizeof(arr[0]));
    
    S s;
    bar(s);
    
    int n1 = foo1();
    cout << n1 << endl;
    
    int n2 = foo2();
    cout << n2 << endl;
    
    int n3 = foo3();
    cout << n3 << endl;
    
    int n4 = foo4();
    cout << n4 << endl;
    
    int m = 100;
    int& n5 = foo5(m);
    cout << n5 <<endl;
    
    T t = {600};
    int& n = t.foo();
    cout << n << endl;
    
    return 0;
}
