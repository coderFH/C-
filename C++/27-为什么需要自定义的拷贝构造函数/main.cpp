//
//  main.cpp
//  27-为什么需要自定义的拷贝构造函数
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
    void Print(void) {
        cout << m_pszName << m_nAge << endl;
    }
private:
    char* m_pszName;
    int m_nAge;
};

int main(int argc, const char * argv[]) {
    Student s1("李明",18);
    s1.Print();
    
    Student s2(s1);
    s2.Print();//这里如果不实现拷贝构造函数,就会崩溃,因为会两次释放同一块内存,其实就是浅拷贝引起的,因为系统提供的g拷贝构造函数,只是字节复制,意思就是拷贝了一个指针,去指向了通一块内存

    Student s3 = s2;
    s3.Print();

    Student* ps = new Student(s3);
    ps->Print();
    delete ps;
    return 0;
}
