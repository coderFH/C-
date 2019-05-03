//
//  main.cpp
//  21-this指针
//
//  Created by Ne on 2019/5/1.
//  Copyright © 2019 Ne. All rights reserved.
//

#include <iostream>
using namespace std;

class Student {
public:
//    Student(const string& m_strName,int m_nAge) : m_strName(m_strName),m_nAge(m_nAge) {
//        cout << "在构造函数中" << this << endl;
//    }
    //构造函数赋值的方式
    //this指针可以用于在构造函数中区分与构造参数名相同的成员变量
    Student(const string& m_strName,int m_nAge) {
        this -> m_strName = m_strName;
        this -> m_nAge = m_nAge;
    }
    void Print() {
        cout << "在Print()函数中" << this << endl;
        cout << m_strName << "," << m_nAge << endl;
    }
private:
    string m_strName;
    int m_nAge;
};

int main(int argc, const char * argv[]) {
    Student s("wangfuh",18);
    cout << "在main()函数中" << &s << endl;
    s.Print();
    return 0;
    
}
