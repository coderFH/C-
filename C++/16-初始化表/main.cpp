//
//  main.cpp
//  16-初始化表
//
//  Created by Ne on 2019/5/1.
//  Copyright © 2019 Ne. All rights reserved.
//

#include <iostream>
using namespace std;

class Student {
public:
    void Learn(string strLesson) {
        cout << "我是" << m_strName << ",我今年" << m_nAge << "岁,我在学" << strLesson << "." << endl;
    }
    void Play(string strGame);
    
    Student(string name = "没名",int age = 0) : m_strName(name),m_nAge(age) {}
private:
    string m_strName;
    int m_nAge;
};

int main(int argc, const char * argv[]) {
    //隐式构造
    Student student;
    student.Learn("法语");
    student.Play("篮球");
    return 0;
}

void Student::Play(string strGame) {
    cout << "我在玩" << strGame << endl;
}

 
