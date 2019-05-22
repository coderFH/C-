//
//  main.cpp
//  50-类型转换
//
//  Created by wangfh on 2019/5/22.
//  Copyright © 2019 Ne. All rights reserved.
//

#include <iostream>
using namespace std;

class A {
    virtual void foo (void) {}
};

class B : public A {};
class C : public B {};
class D {};

int main (void) {
    B b;
    A* pa = &b;
    cout << pa << endl;
    
    // pa实际指向B类对象，转换成功
    B* pb = dynamic_cast<B*> (pa);
    cout << pb << endl;
    
    // pa没有指向C类对象，转换失败，安全
    C* pc = dynamic_cast<C*> (pa);
    cout << pc << endl;
    
    // pa没有指向D类对象，转换失败，安全
    D* pd = dynamic_cast<D*> (pa);
    cout << pd << endl;
    
    // B是A的子类，转换成功
    pb = static_cast<B*> (pa);
    cout << pb << endl;
    
    // C是A的子类，转换成功，危险！
    pc = static_cast<C*> (pa);
    cout << pc << endl;
    
    // D不是A的子类，转换失败，安全
//    pd = static_cast<D*> (pa);
//    cout << pd << endl;
    

    // 编译期、运行期都不做检查，十分危险！！
    pb = reinterpret_cast<B*> (pa);
    cout << pb << endl;
    
    pc = reinterpret_cast<C*> (pa);
    cout << pc << endl;
    
    pd = reinterpret_cast<D*> (pa);
    cout <<  pd << endl;
    
    return 0;
}

