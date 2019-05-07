//
//  main.cpp
//  32-练习
//
//  Created by wangfh on 2019/5/7.
//  Copyright © 2019 Ne. All rights reserved.
//

#include <iostream>
using namespace std;

class F {
public:
    F(int n = 0,int d = 1) : m_n(n),m_d(d) {}
private:
    int m_n;
    int m_d;
    friend ostream& operator<<(ostream& os,const F& f) { //这里F要加const 就是为了适应我不管你是不是常类型的调用,都可以调用这个函数 比如34行
        return os <<f.m_n << "/" << f.m_d;
    }
    friend istream& operator>>(istream& is,F& f) {
        return is >> f.m_n >> f.m_d;
    }
};

int main(int argc, const char * argv[]) {
    F f(1,2);
    cout << f << endl;
    
    F f1;
    cin >> f1;
    cout << f1 << endl;
    
    const F f3(50,60);
    cout << f3 << endl;
    return 0;
}
