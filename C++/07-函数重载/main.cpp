//
//  main.cpp
//  07-函数重载
//
//  Created by wangfh on 2019/4/28.
//  Copyright © 2019 Ne. All rights reserved.
//

#include <iostream>
using namespace std;

int add(int a,int b) {
    return a + b;
}

double add (double a,double b) {
    return a + b;
}

int main(int argc, const char * argv[]) {
    cout << add(10,20) <<endl;
    cout << add(0.1, 0.2) << endl;
//    cout << add(10, 0.1) << endl;直接报错,编译器不知道调用哪个
    
    return 0;
}
