//
//  main.cpp
//  26-拷贝构造
//
//  Created by wangfh on 2019/5/6.
//  Copyright © 2019 Ne. All rights reserved.
//

#include <iostream>
using namespace std;

class Student {
public:
    //普通的构造函数
    Student(const string name,int age):m_strName(name),m_nAge(age) {}
    //拷贝构造函数
    Student(const Student& student) : m_strName(student.m_strName), m_nAge(student.m_nAge) {}
    void Print(void) {
        cout << m_strName << m_nAge << endl;
    }
private:
    string m_strName;
    int m_nAge;
};

int main(int argc, const char * argv[]) {
    Student s1("李明",18);
    s1.Print();
    
    //像这种方式,如果没有实现拷贝构造函数,编译器会自动的实现一个拷贝构造函数,当然,我们也可以自己去实现
    Student s2(s1);
    s2.Print();
    
    Student s3 = s2;
    s3.Print();
    
    Student* ps = new Student(s3);
    ps->Print();
    delete ps;
    return 0;
}
