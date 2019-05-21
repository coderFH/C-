//
//  main.cpp
//  41-间接操作符
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
    void foo (void) {
        cout << "foo()函数" << endl;
    }
};

class PA {
public:
    PA (A* pa) : m_pa (pa) {};
    ~PA (void) {
        delete m_pa;
    }
    A* operator-> (void) {
        return m_pa;
    }
    A& operator* (void) {
        return *m_pa;
    }
private:
    A* m_pa;
};
int main (void) {
    //正常情况下的使用
    A *pa = new A;
    pa->foo();
    delete pa; //如果我不显式的调用delete,就会造成内存的泄露,所以人们想我能不能想个办法去解决这个问题,就有了如下的pa类
    
    cout << "智能指针" << endl;
    //智能指针的原理,既然我不想去显式的调用delete去释放内存,又要实现内存的释放
    //所以人们想到了基本数据类型,首先基本数据类型是没有构造析构的
    //所以我们定义一个类,把指针传进去,在该类的析构方法里去释放指针
    PA pa1(new A); //该函数结束时,pa会释放,所以会调用该类的析构函数,析构函数内部去释放了A对象
    
    //虽然这种方式省去了我们去调用delete的便利,但是在访问该指针内容的时候,又会很麻烦,所以这里就用到了间接操作符
    pa1 -> foo ();
    (*pa1).foo ();
    
    //智能指针的思想,就是用一个类去包装一个指针,然后用该类去创建一个对象,因为该对象是局部变量,所以对象释放的时候会调用析构函数,从而释放该指针
    return 0;
}
