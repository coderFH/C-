//
//  main.cpp
//  14-访问控制
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
    bool SetName(string strName) {
        if (strName.length() == 0)
            return false;
        m_strName = strName;
        return true;
    }
    
    string GetName(void) {
        return m_strName;
    }
    
    bool SetAge(int age) {
        if (age <= 0) {
            return false;
        }
        m_nAge = age;
        return true;
    }
    
    int GetAge(void) {
        return m_nAge;
    }
private:
    string m_strName;
    int m_nAge;
};

int main(int argc, const char * argv[]) {
    Student student;
    
    //private属性  类外不能访问
//    student.m_strName = "zhangfei";
//    student.m_nAge = 18;
    
    if(!student.SetName("wangfuhao")) {
        cout << "设置姓名失败" << endl;
        return -1;
    }
    if (!student.SetAge(25)) {
        cout << "设置年龄失败!" << endl;
        return -1;
    }
    
    cout << student.GetName() << "," << student.GetAge() << endl;
    
    student.Learn("C++");
    
    return 0;
}
