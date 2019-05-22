//
//  main.cpp
//  49-typeInfo
//
//  Created by wangfh on 2019/5/22.
//  Copyright © 2019 Ne. All rights reserved.
//

#include <iostream>
#include <typeinfo>
using namespace std;

typedef struct {
    string m_strName;
    int m_nAge;
} STUDENT;

class Student {
};

class A {
    virtual void foo (void) {}
};
class B : public A {};
class C : public A {};

int main (void) {
    cout << typeid (int).name () << endl; //i
    cout << typeid (unsigned int).name () << endl; //j
    cout << typeid (char*).name () << endl; //Pc
    cout << typeid (double**).name () << endl; //PPd
    short sa[10];
    cout << typeid (sa).name () << endl;//A10_s
    
    cout << typeid (STUDENT).name () << endl;
    cout << typeid (Student).name () << endl;
    
    B b;
    A& r = b;
    cout << typeid (r).name () << endl; //1B
    
    A* pa = new C;
    if (typeid (*pa) == typeid (B))
        cout << "pa指向B对象" << endl;
    else if (typeid (*pa) == typeid (C))
        cout << "pa指向C对象" << endl;
    else
        cout << "不知道" << endl;
    return 0;
}

