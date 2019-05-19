//
//  main.cpp
//  35-单目运算符重载
//
//  Created by Ne on 2019/5/18.
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
    Complex(int r = 1,int i = 1) : m_r(r),m_i(i) {}
    Complex operator-(void) {
        return Complex(-m_r,-m_i);
    }
    const Complex operator++(int) { //后++之所以有个参数,就是为了区分前++ ,实际并没有用到,这就是哑元
        Complex c = *this;
        m_r++;
        m_i++;
        return c;
    }
    Complex& operator++(void) {
        m_r++;
        m_i++;
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
    //单目运算符重载 -
//    cout << -c1 << endl;
    
    // ++
    int n = 10;
    cout << n++ << endl;
    cout << n << endl;
    
    int m = 10;
    cout << ++m << endl;
    cout << m << endl;
    cout << ++++m << endl; //前++可以连用,后++不能
    
    cout << c1++ << endl;//c1.operator++(0)
    cout << c1 << endl;
    
    cout << ++c1 << endl;
    cout << c1 << endl;
}
