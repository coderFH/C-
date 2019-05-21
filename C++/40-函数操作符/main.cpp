//
//  main.cpp
//  40-函数操作符
//
//  Created by wangfh on 2019/5/21.
//  Copyright © 2019 Ne. All rights reserved.
//

#include <iostream>
using namespace std;

class Square {
public:
    int operator() (int n) const {
        return n * n;
    }
    
    double operator() (double f) const {
        return f * f;
    }
};

int main(int argc, const char * argv[]) {
    Square square;
    cout << square(10) << endl;
    cout << square(1.11) << endl;
    return 0;
}
