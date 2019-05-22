//
//  main.cpp
//  48-虚函数表
//
//  Created by wangfh on 2019/5/22.
//  Copyright © 2019 Ne. All rights reserved.
//

#include <iostream>
using namespace std;

class A {
private:
//    int m_n;
public:
    virtual void foo(void) {
        cout << "A::foo" << endl;
    }
    virtual void bar(void) {
        cout << "A::bar" << endl;
    }
};

class B : public A {
public:
    void foo(void) {
        cout << "B::foo" << endl;
    }
};

typedef void (*PFUNC) (void);
typedef PFUNC* PVFTBL;

int main(int argc, const char * argv[]) {

//    cout << sizeof(A) << endl;
    
//    B b;
//    A *pa = &b;
//    pa->foo();
//    pa->bar();
    
    A a;
    PVFTBL pVftbl = *(PVFTBL*)&a;
    cout << "A::PVFTBL=" << (void*)pVftbl << endl;
    cout << "A::VFTBL[0]="<<(void*)pVftbl[0]<<endl;
    cout << "A::VFTBL[1]="<<(void*)pVftbl[1]<<endl;
    (pVftbl[0]) ();
    (pVftbl[1]) ();
    B b;
    pVftbl = *(PVFTBL*)&b;
    cout << "B::PVFTBL=" << (void*)pVftbl << endl;
    cout << "B::VFTBL[0]="<<(void*)pVftbl[0]<<endl;
    cout << "B::VFTBL[1]="<<(void*)pVftbl[1]<<endl;
    (pVftbl[0]) ();
    
    a = b;
    a.foo ();
    A& ra = b;
    ra.foo ();
    
    return 0;
}
