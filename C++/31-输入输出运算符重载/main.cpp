//
//  main.cpp
//  31-输入输出运算符重载
//
//  Created by wangfh on 2019/5/7.
//  Copyright © 2019 Ne. All rights reserved.
//

#include <iostream>
using namespace std;

class Complex {
private:
    int m_r; //实部
    int m_i; //虚部
    friend ostream& operator<<(ostream& ,const Complex&);
    friend istream& operator>>(istream&,Complex&);
    
public:
    Complex() {}
    Complex(int r,int i) : m_r(r),m_i(i) {}
};

ostream& operator<<(ostream& os,const Complex& c) {
    return os << "(" << c.m_r << "+" << c.m_i << "i)" << endl;
}

istream& operator>>(istream& is,Complex& c) {
    return is >> c.m_r >> c.m_i;
}

int main(int argc, const char * argv[]) {
    Complex c1(3,4);
    cout << c1 << endl;//不运算符重载的话,会报错 编译器本质回去找这个函数 operator<<(cout,c1); 所以我们实现它就行
    
    Complex c2;
    cin >> c2;
    cout << c2 << endl;
}
