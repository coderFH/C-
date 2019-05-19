//
//  main.cpp
//  33-双目运算符重载
//
//  Created by wangfh on 2019/5/15.
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
    Complex operator+ (const Complex& c) const {//const表示调用对象不可变,这里就是c1
        return Complex(m_r + c.m_r,m_i + c.m_i);
    }
    Complex& operator+= (const Complex& c) {
//        return *this = *this + c; //等价于下面的写法
        m_r += c.m_r;
        m_i += c.m_r;
        return *this;
    }
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
    
    //双目运算符重载
    Complex c3 = c1 + c2;//  编译器其实会理解为c3 = c1.operator+(c2);
    cout << c1 << "+" <<c2 << "=" << c3 <<endl;
    
    //仿写类似于 int a = 10, b = 20; (a+=b)+=b;
    Complex c4 = c1;
    (c4 += c2)+=c2;
    cout << "+=" << c4 <<  endl;
}
