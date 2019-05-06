//
//  main.cpp
//  30-成员指针
//
//  Created by wangfh on 2019/5/6.
//  Copyright © 2019 Ne. All rights reserved.
//

#include <iostream>
using namespace std;

class Student {
public:
    string m_strName;
    void SetName(const string& strName) {
        m_strName = strName;
    }
};

int main(int argc, const char * argv[]) {
    //指向成员变量的指针
    string Student::*pstrName = &Student::m_strName;
    Student s1,s2;
    s1.*pstrName = "张飞";
    s2.*pstrName = "刘备";
    cout << s1.m_strName << endl;
    cout << s2.m_strName << endl;
    
    Student *ps = new Student;
    ps->*pstrName = "赵云";
    cout << ps->m_strName << endl;
    
    cout << "--------" << endl;
    //指向成员函数的指针
    void (Student::*pfSetName)(const string&) = &Student::SetName;
    (s1.*pfSetName)("关羽");
    cout << s1.m_strName << endl;
    (ps->*pfSetName)("赵云2");
    cout << ps->m_strName << endl;
    
    return 0;
}
