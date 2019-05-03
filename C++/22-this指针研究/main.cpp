//
//  main.cpp
//  22-this指针研究
//
//  Created by Ne on 2019/5/1.
//  Copyright © 2019 Ne. All rights reserved.
//

#include <iostream>
using namespace std;

#pragma mark --this 指针可以返回自引用的场合
class Counter {
public:
    Counter(int cn = 0) : m_cn(cn) {}
    Counter& Inc() {
        m_cn++;
        return *this;
    }
    Counter& Dec() {
        m_cn--;
        return *this;
    }
    void Print() {
        cout << m_cn << endl;
    }
private:
    int m_cn;
};

#pragma mark --this this 指针可以作为函数的参数实现对象交互
class Student;
class Teacher {
public:
    void educate(Student * pStudent);
    void replay(const string strAnswer) {
        m_strAnswer = strAnswer;
    }
private:
    string m_strAnswer;
};

class Student {
public:
    void ask(const string& strQuestion,Teacher *pTeacher) {
        cout << strQuestion << endl;
        pTeacher -> replay("this指针就是指向 调用对象的指针");
    }
};

void Teacher::educate(Student *pStudent) {
    pStudent -> ask("什么是this指针",this);
    cout << m_strAnswer << endl;
}

int main(int argc, const char * argv[]) {
    Counter counter;
//    counter.Inc();
//    counter.Inc();
//    counter.Inc();
//    counter.Dec();
//    counter.Print();
    //我不想像上边一样去写,我想写到一行
    counter.Inc().Inc().Inc().Dec();
    counter.Print();
    
    Teacher t;
    Student s;
    t.educate(&s);
    return 0;
}
