//
//  main.cpp
//  39-下标操作符
//
//  Created by wangfh on 2019/5/21.
//  Copyright © 2019 Ne. All rights reserved.
//

#include <iostream>
using namespace std;

class IntArray {
public:
    IntArray(int size) : m_data(new int[m_size = size]),m_top(0) {}
    ~IntArray(void) {
        delete [] m_data;
    }
    bool Push(int n) {
        if (m_top >= m_size)
            return false;
        m_data[m_top++] = n;
        return true;
    }
    bool Pop(int& n) {
        if (m_top <= 0)
            return false;
        n = m_data[--m_top];
        return true;
    }
    bool Get(int i,int& n) {
        if (i < 0 || m_top <= i)
            return false;
        n = m_data[--m_top];
        return true;
    }
    bool Set(int i,int n) {
        if (i < 0 || m_top <= i)
            return false;
        m_data[i] = n;
        return true;
    }
    void Print(void) {
        for (int i = 0; i < m_top; i++)
            cout << m_data[i] << " ";
        cout << endl;
    }
    //下标运算符重载
    int operator[] (int i) {
        return m_data[i];
    }
private:
    int *m_data;
    int m_size;
    int m_top;
};

int main() {
    IntArray ia(10);
    for (int i = 0; i < 10; i++)
        ia.Push(i);
    ia.Print ();
    cout << "通过[]运算符遍历" << endl;
    for (int i = 0; i < 3; i++) {
        cout << ia[i] << endl;
    }
    
}
