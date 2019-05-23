//
//  main.cpp
//  57-文件指针
//
//  Created by wangfh on 2019/5/23.
//  Copyright © 2019 Ne. All rights reserved.
//

#include <fstream>
#include <iostream>
using namespace std;

int main (void) {
    fstream fs ("pos.txt", ios::in|ios::out);
    if (! fs) {
        cout << "打开文件失败！" << endl;
        return -1;
    }
    fs << 1234 << " " << 56.78 << " " << "apples" << '\n';
    cout << fs.tellg () << endl;
    cout << fs.tellp () << endl;
    fs.seekg (0, ios::beg);
    cout << fs.tellg () << endl;
    cout << fs.tellp () << endl;
    fs << 7890;
    fs.seekp (-7, ios::end);
    fs << "APPLES\n";
    fs.close ();
    return 0;
}
