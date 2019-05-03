//
//  main.cpp
//  20-自定义类型转换的构造函数
//
//  Created by Ne on 2019/5/1.
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
private:
    int m_x;
    int m_y;
    friend class Point3D;//友元,知道Point3D是我的好朋友,他可以访问我的私有成员
};

Point3D::Point3D(const Point2D& pt2) : m_x(pt2.m_x),m_y(pt2.m_y),m_z(0) {}

int main(int argc, const char * argv[]) {
    Point3D pt3(10,20,30);
    pt3.Print();
    
    Point2D pt2(100,200);
    pt2.Print();
    
    pt3 = pt2;//如果不实现 Point3D(const Point2D& pt2); 是不能这么转换的
    pt3.Print();
   
    //pt3 = 1000;//为什么不加explicit关键字的时候,一个整数可以赋值给一个对象呢,就是由于有隐士转换的原因
    pt3 =static_cast<Point3D>(1000); //所以加上explicit,如果你就想把一个整数转换成对象,就去自己做显示的转换
    
    
    
    pt3.Print();
    
    return 0;
}
