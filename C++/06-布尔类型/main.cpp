//
//  main.cpp
//  06-布尔类型
//
//  Created by wangfh on 2019/4/28.
//  Copyright © 2019 Ne. All rights reserved.
//

#include<iostream>

using namespace std;

int main() {
    bool a = true;
    cout << "a = " << a << endl;
     cout << "sizeof(a) = " << sizeof(a)<<endl;
    
    bool b = false;
    cout << "b = " << b << endl;
    cout << "sizeof(b) = " << sizeof(b)<<endl;
    
    //非0全为真
    b = 3.14;
    cout << b <<endl;
    
    b = "hello";
    cout << b <<endl;
    
    b = NULL;
    cout << b <<endl;
    
    return 0;
}
