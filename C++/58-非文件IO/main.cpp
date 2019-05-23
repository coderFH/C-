//
//  main.cpp
//  58-非文件IO
//
//  Created by wangfh on 2019/5/23.
//  Copyright © 2019 Ne. All rights reserved.
//

#include <fstream>
#include <iostream>
using namespace std;
int main (void) {
    ofstream ofs ("putget.txt");
    for (char c = ' '; c <= '~'; c++)
        ofs.put (c);
    ofs.close ();
    
    ifstream ifs ("putget.txt");
    char c;
    while ((c = ifs.get ()) != EOF)
        cout << c;
    cout << endl;
    
    if (! ifs.eof ()) {
        cout << "读取文件失败！" << endl;
        return -1;
    }
    ifs.close ();
    return 0;
}

