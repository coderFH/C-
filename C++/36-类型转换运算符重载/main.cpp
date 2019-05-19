//
//  main.cpp
//  36-类型转换运算符重载
//
//  Created by Ne on 2019/5/18.
//  Copyright © 2019 Ne. All rights reserved.
//

#include <iostream>
using namespace std;

class Point2D;
class Point3D {
public:
    //explicit`关键字可以指示该构造函数只能用于显式类型转换，以防潜在错误。
    explicit Point3D(int x,int y = 0,int z = 0) : m_x(x),m_y(y),m_z(z) {}
    Point3D(const Point2D& pt2);
    void Print() {
        cout << m_x << "," << m_y << "," << m_z << endl;
    }
private:
    int m_x;
    int m_y;
    int m_z;
};

class Point2D {
public:
    Point2D(int x,int y) : m_x(x),m_y(y) {}
    void Print() {
        cout << m_x << "," << m_y << endl;
    }
    operator Point3D(void) {
        return Point3D(m_x,m_y,1000);
    }
private:
    int m_x;
    int m_y;
    friend class Point3D;//友元,知道Point3D是我的好朋友,他可以访问我的私有成员
};


int main(int argc, const char * argv[]) {
    Point3D pt3(10,20,30);
    pt3.Print();
    
    Point2D pt2(100,200);
    pt2.Print();
    
    pt3 = pt2;
    pt3.Print();
    
    return 0;
}
