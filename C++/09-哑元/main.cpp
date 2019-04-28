//
//  main.cpp
//  09-哑元
//
//  Created by wangfh on 2019/4/28.
//  Copyright © 2019 Ne. All rights reserved.
//

#include <iostream>
using namespace std;

//这就是一个哑元
void bar(int) {
    cout <<  "我根本没用到参数" << endl;
}

void bar(void) {
    cout <<  "重载的bar" << endl;
}

int main(int argc, const char * argv[]) {
    bar(100);
    bar();
    return 0;
}
