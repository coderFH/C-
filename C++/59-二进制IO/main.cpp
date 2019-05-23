//
//  main.cpp
//  59-二进制IO
//
//  Created by wangfh on 2019/5/23.
//  Copyright © 2019 Ne. All rights reserved.
//

#include <fstream>
#include <iostream>
using namespace std;

int main (int argc, char* argv[]) {
    if (argc < 3) {
        cout << "使用：" << argv[0] << " <源文件> <目标文件>" << endl;
        return -1;
    }
    ifstream ifs (argv[1], ios::binary);
    if (! ifs) {
        cout << "打开源文件失败！" << endl;
        return -1;
    }
    ofstream ofs (argv[2], ios::binary);
    if (! ofs) {
        cout << "打开目标文件失败！" << endl;
        return -1;
    }
    char buf[1024];
    while (ifs.read (buf, sizeof (buf)))
        ofs.write (buf, sizeof (buf));
    if (ifs.eof ())
        ofs.write (buf, ifs.gcount ());
    else {
        cout << "写文件失败！" << endl;
        return -1;
    }
    ofs.close ();
    ifs.close ();
    return 0;
}

