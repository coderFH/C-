//
//  main.cpp
//  34-双目运算符重载-练习
//
//  Created by Ne on 2019/5/18.
//  Copyright © 2019 Ne. All rights reserved.
//

#include <iostream>
using namespace std;

class Fenshu {
private:
    int m_n;
    int m_d;
    
    friend ostream& operator<< (ostream& os,const Fenshu& f) {
        return os << f.m_n << "/" << f.m_d << endl;
    }
    
public:
    Fenshu(int n = 1, int d = 1) : m_n(n),m_d(d){}
    Fenshu operator+(const Fenshu& f) const {
        return Fenshu(m_n *f.m_d + m_d * f.m_n,m_d*f.m_d);
    }
    Fenshu& operator+= (const Fenshu& f){
        return *this = *this + f;
    }
    
};
int main(int argc, const char * argv[]) {
    Fenshu f1(1,2);
    Fenshu f2(1,2);
    cout << f1 + f2 << endl;
    
    (f1+=f2)+=f2;
    cout << f1 << endl;
    
    return 0;
}
