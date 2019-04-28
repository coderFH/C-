//
//  main.cpp
//  04-联合的使用
//
//  Created by wangfh on 2019/4/28.
//  Copyright © 2019 Ne. All rights reserved.
//

#include <iostream>
#include <cstdio>
using namespace std;

int main(int argc, const char * argv[]) {
    union {
        int n;
        char c[4];
    }un;
    un.n = 0x12345678;
    printf("%x %x %x %x \n",un.c[0],un.c[1],un.c[2],un.c[3]);
    
    //定义时也可以不需要un
    union {
        int n1;
        char c1[4];
    };
    n1 = 0x12345678;
    printf("%x %x %x %x \n",c1[0],c1[1],c1[2],c1[3]);
    
    return 0;
}
