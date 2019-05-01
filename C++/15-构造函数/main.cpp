//
//  main.cpp
//  15-构造函数
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
    //无参的构造函数
    Student(void) {
        m_strName = "没名";
        m_nAge = 0;
    }
    
    Student(string name,int age) {
        m_strName = name;
        m_nAge = age;
    }
private:
    string m_strName;
    int m_nAge;
};

int main(int argc, const char * argv[]) {
    //隐式构造
    Student student("wfh",18);
    student.Learn("C++");
    
    //显示的构造
    Student student2 = Student("wangfh",18);
    student2.Learn("英语");
    //在栈中构造对象数组
    Student students[] = {
        Student("赵云",28),
        Student("曹操",38),
        Student("刘备",18)
    };
    students[0].Learn("骑马");
    students[1].Learn("射 箭");
    students[2].Learn("摔跤");
    
    //在堆中构造对象
    Student *p = new Student("诸葛亮",28);
    p->Learn("星象");
    delete p;
    
    //在堆中构造对象数组
    //创建对象的同时,进行初始化,需要C++2011支持,高版本编译器可以进行初始化
    Student *pStudent = new Student[3] {
        Student("沈腾",28),
        Student("艾伦",39),
        Student("王宁",40)
    };
    pStudent[0].Learn("夏洛特烦恼");
    pStudent[1].Learn("羞羞的铁拳");
    pStudent[2].Learn("废柴兄弟");
    delete[] pStudent;
    
    //先开辟空间,不初始化
    Student *p1 = new Student[3];//这时需要调用类中的无参的构造函数
    //*(p1+0)
    p1[0].Learn("不学无术");
    delete[] p1;
    
    return 0;
}
