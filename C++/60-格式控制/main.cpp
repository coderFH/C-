//
//  main.cpp
//  60-格式控制
//
//  Created by wangfh on 2019/5/23.
//  Copyright © 2019 Ne. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include <math.h>
#include <fstream>
using namespace std;

int main (void) {
    cout.precision (10); // 调用流成员函数,设置精度
    cout << sqrt (2) << endl;
    
    cout << setprecision (8) << sqrt (2) << endl;// 插入流控制符
   
    cout << cout.precision () << endl; // 获取当前输出精度
    
    // 四舍五入，<=5舍，>5入
    cout.precision (2);
    cout << 1.24 << " " << 1.25 << " " << 1.26 << endl;
    // 无论是流成员函数还是流控制符，其作用都是可持续的，直到再次改变相应的属性
    cout << 1.23456789 << endl;
    
    cout << setprecision (5) << 1.23456789 << endl;
    
    cout << "显示进制==============" << endl;
    
    // 进制显示
    cout << showbase << oct << 127 << endl;
    cout << showbase << hex << 127 << endl;
    cout << dec << 127 << endl;
    cout << noshowbase << hex << 127 << endl;
    cout << showbase << dec << 127 << endl;
    
    cout << "============seff=============" << endl;
    cout.setf (ios::showbase);  //统一设置showbase
    cout.unsetf (ios::showbase);//统一取消showbase
    cout << hex << 127 << endl;
    cout << dec;
    
    // 宽度和填充字符，setw()只影响随后的一次输出
    cout << setw (10) << 1234 << endl;
    cout << setfill ('#') << setw (10) << 1234 << endl;
    cout << left << setfill ('$') << setw (10) << 1234 << endl;
    cout << setfill ('@') << right << setw (10) << 1234 << endl;
    cout << setprecision (6) << 111111111111112.0 << endl;
    
    cout.precision (4);
    cout << "cout.precision (4)=====" << sqrt (200) << endl;// 对于固定小数记法，精度表示有效数字长度
    cout.setf (ios::scientific);
    cout << sqrt (200) << endl;// 对于科学计数法，精度表示小数部分长度
    cout.setf (ios::fixed);
    cout << "cout.precision (4)=====" << sqrt (200) << endl;
    
    cout << "========ifstream===========" << endl;
    ifstream ifs ("format.txt");
    ifs.unsetf (ios::skipws); // 不掠过空白字符
    char c;
    while (ifs >> c)
        cout << c;
    ifs.setf (ios::skipws); // 掠过空白字符
    ifs.clear (); // 复位流状态标志
    ifs.seekg (ios::beg); // 将文件位置调到文件头
    while (ifs >> c)
        cout << c;
    ifs.close ();
    return 0;
}

