//
//  main.cpp
//  63-const
//
//  Created by wangfh on 2019/5/28.
//  Copyright © 2019 Ne. All rights reserved.
//

#include <iostream>
using namespace std;

struct Student {
    int age;
};

int main(int argc, const char * argv[]) {
    const int age = 20;
    //    age = 30; //不能改
    
    const Student stu = {20};
    Student stu2 = {40};
    //    stu = stu2; //不能改
    
    
    const Student *pStu = &stu2;
    //    pStu->age = 50;  //不能改
    cout << stu2.age << endl;
    
    //记住一个结论:const修饰它右边的内容
    int test = 20;
    int height = 10;
    const int *p0 = &height; //const修饰的是*p0 所有它指向的值不能改,但是可以更改指向  *p0是常量,p0不是常量
    //    *p0 = 20;  //报错
    p0 = &test;
    
    int const *p1 = &height;//和上边的一样
    //    *p1 = 20;  //报错
    p1 = &test;
    
    int * const p2 = &height; //*p2不是是常量,p2是常量  不能更改指向
    *p2 = 20;
    //    p2 = &test;//报错
    
    const int * const p3 = &height; //p3 *p2 都是常量
    //    *p3 = 30;//报错
    //    p3 = &test;//报错
    
    int const * const p4 = &height;//同p3
    
    //常引用
    int age2 = 10;
    //不能通过指针修改所指向的内容,即age2的值我不能随便改
    int const *pAge1 = &age2;
    //不能修改指针的指向,但是可以通过指针修改所指向的内容
    int * const pAge2 = &age2;
    
    //引用的本质就是指针
    //    int & const tAge = age2;
    //    tAge = 30;
    
    //不能通过引用修改所指向的内容
    int const &ttAge = age2;
    //    ttAge = 30;
    
    return 0;
}

