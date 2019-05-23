//
//  main.cpp
//  61-字符串流
//
//  Created by wangfh on 2019/5/23.
//  Copyright © 2019 Ne. All rights reserved.
//

#include <iostream>
#include <sstream>
#include <math.h>

using namespace std;
int main (void) {
    ostringstream oss;
    oss << 100 << ", " << sqrt (2) << ", " << "hello";
    cout << oss.str () << endl;
    /*
     char s[128];
     sprintf (s, "%d, %lf, %s", 100, sqrt (2), "hello");
     cout << s << endl;
     */
    return 0;
}
