//
//  main.cpp
//  43-继承
//
//  Created by wangfh on 2019/5/21.
//  Copyright © 2019 Ne. All rights reserved.
//

#include <iostream>
using namespace std;

class Person {
public:
    Person(void) : m_strName("无名"),m_nAge(-1) {
        cout << "我是" << m_strName << ",今年" << m_nAge << "岁" << endl;
    }
    Person (const string& strName, int nAge) : m_strName (strName), m_nAge (nAge) {
        cout << "我是" << m_strName << "，今年" << m_nAge << "岁。" << endl;
    }
    Person (const Person& person) : m_strName (person.m_strName), m_nAge (person.m_nAge) {
        cout << "我是" << m_strName << "，今年" << m_nAge << "岁。" << endl;
    }
    void Eat(const string& strFood) {
        cout << strFood << "真好吃!" << endl;
    }
protected:
    string GetName(void) {
        PriFunc();
        return m_strName;
    }
private:
    void PriFunc(void) {
        cout << "基类中的私有成员函数" << endl;
    }
    string m_strName;
    int m_nAge;
};

class Student : public Person {
public:
    Student (const string& strName, int nAge, int nNumber) :Person(strName,nAge),m_nNumber (nNumber) {//在子类的构造函数中可以显式地指定其基类子对象的构造方式就是这句Person(strName,nAge)（通过在初始化表中使用“基类(构造参数)”），否则系统就会试图以无参的方式构造其基类子对象
        cout << "我是学生，学号是" << m_nNumber << "。" << endl;
    }
    void Learn (const string& strLesson) {
        cout << "我在学" << strLesson << "。" << endl;
    }
    void foo (void) {
        cout << GetName () << endl;
    }
    int Eat (void) {
        cout << "子类中的Eat()函数" << endl;
        Person::Eat ("巧克力");
        return 100;
    }
private:
    int m_nNumber;
};

class Teacher : public Person {
public:
    Teacher (const string& strName, int nAge, const string& strJob) : Person (strName, nAge), m_strJob (strJob) {
        cout << "我是教师，职务是" << m_strJob << "。" << endl;
    }
    void Teach (const string& strSubject) {
        cout << "我在教" << strSubject << "。" << endl;
    }
    Teacher (const Teacher& t) : Person (t), m_strJob (t.m_strJob) {}
private:
    string m_strJob;
};

int main(int argc, const char * argv[]) {
    Student s1 ("张飞", 28, 1001);
    cout<< s1.Eat () << endl;
    s1.Person::Eat ("面条");
    s1.Learn ("C++");
    s1.foo ();
    
    cout << "===================" << endl;
    Teacher t1 ("赵云", 50, "教授");
    t1.Eat ("包子");
    t1.Teach ("物理");
    Teacher t2 (t1);
    
    return 0;
}
