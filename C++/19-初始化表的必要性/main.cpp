//
//  main.cpp
//  19-初始化表的必要性
//
//  Created by Ne on 2019/5/1.
//  Copyright © 2019 Ne. All rights reserved.
//

#include <iostream>
using namespace std;

class User {
public:
    //为什么不能使用构造函数那种赋值方式,而必须使用初始化表
    //因为通过构造函数的方式,相当于我们先创建了一个对象之后,再初始化
    //由于成员表示是const和引用类型,需要在创建一个对象的同时就去赋值,所以使用初始化表的方式去告诉编译器我的两个值是赋值给谁的
    User(int nID,int nAge) : m_nID(nID),m_nAge(nAge) {}
    void Print(void) {
        cout << m_nID << m_nAge << endl;
    }
private:
    const int m_nID;
    int& m_nAge;
};

int main(int argc, const char * argv[]) {
    //类中包含常量和引用型常量。必须通过构造函数和初始化列表 显式对其进行初始化
    User user(1001,18);
    user.Print();
    return 0;
}
