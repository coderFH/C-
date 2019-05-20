//
//  main.cpp
//  38-运算符重载综合练习
//
//  Created by wangfh on 2019/5/20.
//  Copyright © 2019 Ne. All rights reserved.
//

/*
 实现一个3X3整型矩阵，支持如下运算：
 +、* 、+=、*=、前后缀++、<<
 */

#include <iostream>
#include <iomanip>

using namespace std;

class M33 {
public:
    M33(void) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                m_a[i][j] = 0;
            }
        }
    }
    M33(int a[][3]) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                m_a[i][j] = a[i][j];
            }
        }
    }
    M33 operator+ (const M33& m) const {
        int a[3][3];
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3 ; j++) {
                a[i][j] = m_a[i][j] + m.m_a[i][j];
            }
        }
        return M33(a);
    }

    M33 operator* (const M33& m) const {
        int a[3][3] = {0};
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                for (int k = 0; k < 3; k++)
                    a[i][j]+=m_a[i][k]*m.m_a[k][j];
        return M33 (a);
    }
    
    M33& operator+=(const M33& m) {
        return *this = *this + m;
    }
    
    M33& operator*=(const M33& m) {
        return *this = *this * m;
    }
    
    M33& operator++(void) {
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                m_a[i][j]++;
        return *this;
    }
    
    const M33 operator++(int) {
        M33 m = *this;
        ++(*this);
        return m;
    }
    
    friend ostream& operator<< (ostream& os, const M33& m) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++)
                os << setw (4) << m.m_a[i][j];
            os << endl;
        }
        return os;
    }
private:
    int m_a[3][3];
};

int main() {
    int a1[3][3] = {1,2,3,4,5,6,7,8,9};
    M33 m1(a1);
    int a2[3][3] = {9,8,7,6,5,4,3,2,1};
    M33 m2(a2);
    cout << "m1 + m2" << endl;
    cout << m1 + m2 << endl;

    cout << "m1 * m2" << endl;
    cout << m1 * m2 << endl;

    M33 m3 (m1);
    m3 += m2;
    cout << "m3 += m2" << endl;
    cout << m3 << endl;

    m3 = m1;
    m3 *= m2;
    cout << "m3 *= m2" << endl;
    cout << m3 << endl;

    m3 = m1;
    cout << "前++" << endl;
    cout << m3++ << endl;
    cout << m3 << endl;
    
    m3 = m1;
    cout << "后++" << endl;
    cout << ++m3 << endl;
    cout << m3 << endl;
    
    return 0;
}
