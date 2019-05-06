//
//  main.cpp
//  25-练习
//
//  Created by wangfh on 2019/5/6.
//  Copyright © 2019 Ne. All rights reserved.
//

/*
 练习：实现一个整形数组类IntArray
 通过构造函数指定容量，注意析构释放资源
 * push()在数组尾部加入一个元素
 * pop()从数组尾部弹出一个元素
 * get()根据下标获取一个元素值
 * set()根据下标设置一个元素的值
 * print()打印数组
 * 提示：内部维护一个整形数组，动态分配，还要维护一个数组上限的
 */
//内部维护的数组如何创建

#include <iostream>
using namespace std;

class Stack {
public:
    Stack(int size) : m_data(new int[m_size = size]),m_top(0){}
    ~Stack(void) {
         delete[] m_data;
    }
    bool Push(int value) {
        if (m_top >= m_size) {
            return false;
        }
        m_data[m_top++] = value;
        return true;
    }
    
    bool Pop(int &n) {
        if (m_top == 0) {
            return false;
        }
        n = m_data[--m_top];
        return true;
    }
    
    bool Get(int index,int& value ) {
        if (index < 0 || m_top <= index) {
            return false;
        }
        value = m_data[index];
        return true;
    }
    
    bool Set(int index,int value) {
        if (index < 0 || m_top <= index) {
            return false;
        }
        m_data[index] = value;
        return true;
    }
    
    void Print(void) {
        for (int i = 0; i < m_top; i++) {
            cout << m_data[i] << endl;
        }
    }
private:
    int * m_data;
    int m_size;
    int m_top;
};

int main(int argc, const char * argv[]) {
    cout << "===push====" << endl;
    Stack s(5);
    s.Push(1);
    s.Push(2);
    s.Push(3);
    s.Push(4);
    s.Push(5);
    cout << "bool = " << s.Push(6) << endl;
    s.Print();
    cout << "===pop===" << endl;
    int n;
    while (s.Pop(n)) {
        cout << n << endl;
    }
    cout << "bool = " << s.Pop(n) << endl;

    cout << "===Set===" << endl;
    s.Push(100);
    s.Push(200);
    s.Push(300);
    s.Set(0, 101);
    s.Set(1, 201);
    s.Set(2, 301);
    s.Print();
    cout << "bool = " << s.Set(-10, 100)<< endl;
    
    cout << "===get===" << endl;
    int g;
    s.Get(0, g);
    cout << g << endl;
    return 0;
}
