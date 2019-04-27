//
//  main.cpp
//  01-helloworld
//
//  Created by Ne on 2019/4/27.
//  Copyright © 2019 Ne. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    std::cout << "Hello, World!" << std::endl;
    std::cout << "请输入一个整数和一个浮点数" << std::endl;
    int x;
    double y;
    std::cin >> x >> y;
    std::cout << "x=" << x <<",y=" << y << std::endl;
    return 0;
}
