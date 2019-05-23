//
//  main.cpp
//  56-文本文件的IO
//
//  Created by wangfh on 2019/5/23.
//  Copyright © 2019 Ne. All rights reserved.
//

#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, const char * argv[]) {
    ofstream ofs1("text.txt"); //创建/覆盖
    ofs1 << 1234 << " " << 56.78 << " " << "apples" << '\n';
    ofs1.close();
    
    ofstream ofs2("text.txt",ios::app); // 追加
    ofs2 << "追加" << '\n';
    ofs2.close();
    
    ifstream ifs1("text.txt"); //文件要存在
    if (!ifs1) {
        cout <<  "文件打开失败" << endl;
        return -1;
    }
    int n;
    double f;
    string str1,str2;
    // 缺省情况下根据空白字符（空格、制表符、换行）分割数据
    ifs1 >> n >> f >> str1 >> str2;
    cout << n << endl;
    cout << f << endl;
    cout << str1 << str2 << endl;
    return 0;
}
