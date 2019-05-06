//
//  main.cpp
//  29-拷贝赋值运算符
//
//  Created by wangfh on 2019/5/6.
//  Copyright © 2019 Ne. All rights reserved.
//

#include <iostream>
using namespace std;

class Student {
public:
    //普通的构造函数
    Student(const char * pszName,int age):m_pszName(NULL),m_nAge(age) {
        m_pszName = new char[strlen(pszName)+1];
        strcpy(m_pszName, pszName);
    }
    ~Student(void) {
        delete[] m_pszName;
    }
    //拷贝构造函数
    Student(const Student& student) : m_pszName(NULL), m_nAge(student.m_nAge) {
        m_pszName = new char[strlen(student.m_pszName)+1];
        strcpy(m_pszName, student.m_pszName);
    }
    
    Student& operator= (const Student& student) {
        if (&student != this) {
            delete[] m_pszName;
            m_pszName = new char(strlen(student.m_pszName)+1);
            strcpy(m_pszName, student.m_pszName);
            m_nAge = student.m_nAge;
        }
        return *this;
    }
    
    void Print(void) {
        cout << m_pszName << m_nAge << endl;
    }
private:
    char* m_pszName;
    int m_nAge;
};

int main(int argc, const char * argv[]) {
    Student s1("张飞",18);
    s1.Print();
    
    Student s2(s1);
    s2.Print();
    
    Student s3("关羽",28);
    //拷贝构造只能解决构造对象副本时的深拷贝问题，缺省方式的拷贝赋值依然是按字节复制，这种情况下就需要提供一个自定义的拷贝复制运算服函数，以获取真正意义上的对象副本
//    s3 = s2; //没有拷贝赋值运算符,就会崩溃,还是浅拷贝,重复释放的原因  编译器的理解方式是s3.operator=(s2);
    s3.Print();
    
    Student s4("马超",11);
    (s4 = s3) = s1;
    s4.Print();
    
    return 0;
}
