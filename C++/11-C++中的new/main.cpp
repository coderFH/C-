//
//  main.cpp
//  11-C++中的new
//
//  Created by wangfh on 2019/4/28.
//  Copyright © 2019 Ne. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    int *p = (int *)malloc(sizeof(int));
    *p = 100;
    cout << *p <<endl;
    free(p);
    p = NULL;
    
    p = new int(100);
    cout << *p << endl;
    delete p;
    p = NULL;
    
    p = new int[10];
    for (int i = 0; i < 10; i++) {
        p[i] = i;
    }
    cout << p[5] <<endl;
    delete[] p;
    p = NULL;
    
    int (*p1)[4] = new int[3][4];
    delete[] p1;
    
    int (*ppa)[4][5] = new int[3][4][5];
    delete[] ppa;
    
    return 0;
}
