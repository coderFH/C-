//
//  main.cpp
//  13-引用与函数
//
//  Created by Ne on 2019/4/28.
//  Copyright © 2019 Ne. All rights reserved.
//

#include <iostream>
using namespace std;

struct S {
    int arr[5];
};

void foo(int arr[],int size) {
    for (int i = 0; i<size; i++) {
        cout << arr[i] <<endl;
    }
    cout << endl;
}

//首先,如果不是用引用,就是普通的值传递,相当于把结构体拷贝一个副本出来,在bar()函数中操作,如果数组很大,很浪费时间
//所有使用引用,保证了操作的是同一个结构体,而不会是产生一个副本,很影响效率
//加const,保证了我们在整个函数中,不能去随意的修改数据
void bar(const S& s) {
//    s.arr[0] = 100;//不能修改结构体的值,因为有const修饰
}


//引用型的返回值
int& foo1(void) {
    int n = 100;
    return n;
}

int main(int argc, const char * argv[]) {
    int arr[] = {1,2,3,4,5,6};
    foo(arr,sizeof(arr) / sizeof(arr[0]));
    
    S s;
    bar(s);
    
//    int *psz = foo1();
//    cout << psz << endl;
    
    return 0;
}
