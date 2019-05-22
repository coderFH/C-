//
//  main.cpp
//  54-子类的异常说明不能比基类版本抛出更多的异常
//
//  Created by wangfh on 2019/5/22.
//  Copyright © 2019 Ne. All rights reserved.
//

#include <iostream>
using namespace std;
class Shape { // 抽象类
public:
    Shape (int x, int y) : m_x (x), m_y (y) {}
    virtual void Draw (void) throw (int, double) = 0; // 纯虚函数
protected:
    int m_x, m_y;
};
class Rect : public Shape {
public:
    Rect (int x, int y, int w, int h) : Shape (x, y), m_w (w), m_h (h) {}
    void Draw (void) throw (int) {
        cout << "绘制矩形（" << m_x << "," << m_y << "," << m_w << "," << m_h << "）" << endl;
        }
        void Draw (int n) {}
    private:
        int m_w, m_h;
        };
        class Circle : public Shape {
        public:
            Circle (int x, int y, int r) : Shape (x, y), m_r (r) {}
            //子类中覆盖版本的异常说明不能比基类版本抛出更多的异常
            void Draw (void) throw (double, char) { //抛出的异常不能比基类的类型多 去掉char就不报错了
                cout << "绘制圆（" << m_x << "," << m_y << "," << m_r << "）" << endl;
            }
        private:
            int m_r;
        };
        void Render (Shape* shapes[], int n) {
            for (int i = 0; i < n; i++)
                shapes[i] -> Draw ();
        }
        int main (void) {
            Rect r (1, 2, 3, 4);
            r.Draw ();
            Circle c (5, 6, 7);
            c.Draw ();
            Shape* shapes[5];
            shapes[0] = new Rect (1,2,3,4);
            shapes[1] = new Circle (5,6,7);
            shapes[2] = new Circle (7,8,9);
            shapes[3] = new Rect (9,10,11,12);
            shapes[4] = new Circle (11,12,13);
            Render (shapes, 5);
            return 0;
        }

