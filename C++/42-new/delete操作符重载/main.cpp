//
//  main.cpp
//  42-new/delete操作符重载
//
//  Created by wangfh on 2019/5/21.
//  Copyright © 2019 Ne. All rights reserved.
//

#include <iostream>
using namespace std;

void* operator new (size_t sz) {
    void* p = malloc (sz);
    cout << "我自己的new" << sz << "p= " << p << endl;
    return p;
}

void* operator new[] (size_t sz) {
    void* p = malloc (sz);
    cout << "我自己的new[],sz=" << sz << "p=" << p << endl;
    return p;
    }
    void operator delete (void* p) {
        cout << "我自己的delete p=" << p << endl;
        free (p);
    }
    void operator delete[] (void* p) {
        cout << "我自己的delete[] p=" << p << endl;
        free (p);
    }
    
    class A {
    public:
        A (void) {
            cout << "A构造" << endl;
        }
        ~A (void) {
            cout << "A析构" << endl;
        }
        char m_c[32];
    };
    
    class B {
    public:
        B (void) {
            cout << "B构造" << endl;
        }
        ~B (void) {
            cout << "B析构" << endl;
        }
        static void* operator new (size_t sz) {
            void* p = malloc (sz);
            cout << "B的new sz=" << sz << " p=" << p << endl;
            return p;
        }
        static void* operator new[] (size_t sz) {
            void* p = malloc (sz);
            cout << "B的new[] sz=" << sz << " p=" << p << endl;
            return p;
        }
        static void operator delete (void* p) {
            cout << "B的delete p=" << p << endl;
            free (p);
        }
        static void operator delete[] (void* p) {
            cout << "B的delete[] p=" << p << endl;
            free (p);
        }
    };
    int main (void) {
        A* pa = new A;
        delete pa;
        
        A* paa = new A[3];
        delete[] paa;
        
        //B的new,delete加static 只有B类会使用自己new和delete
        B* pb = new B;
        delete pb;
        
        B* pbb = new B[3];
        delete[] pbb;
        
        return 0;
    }
