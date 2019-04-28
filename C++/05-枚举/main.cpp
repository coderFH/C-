//
//  main.cpp
//  05-枚举
//
//  Created by wangfh on 2019/4/28.
//  Copyright © 2019 Ne. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    enum E{a,b,c,d};
//    E e=0;//编译错误，枚举型变量e不能接受int型值
    E e=a;
    cout << e << endl;
    return 0;
}
