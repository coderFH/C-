//
//  main.cpp
//  03-结构体和C的区别
//
//  Created by Ne on 2019/4/27.
//  Copyright © 2019 Ne. All rights reserved.
//

#include <iostream>
using namespace std;

struct Student {
    char name[128];
    int age;
    //C++结构体中可以放函数
    void eat(const char *food) {
        cout << "我是" << name << ",今年" << age << "岁,我在吃" << food << endl;
    }
};

int main(int argc, const char * argv[]) {
    //C++中使用结构体不用再使用struct关键字了
    Student s = {"张飞",27};
    s.eat("KFC");
    
    Student *ps = &s;
    ps -> eat("烧饼");
    return 0;
}
