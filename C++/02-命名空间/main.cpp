//
//  main.cpp
//  02-命名空间
//
//  Created by Ne on 2019/4/27.
//  Copyright © 2019 Ne. All rights reserved.
//

#include <iostream>

//定义一个命名空间
namespace wfh {
    char name[] = "wangfh";
    void show(void) {
        std::cout << name << std::endl;
    }
}

namespace zs {
    char name[] = "zengs";
    void show(void) {
        std::cout << name << std::endl;
        //所以一般会在开始写using namespage std
        //使用的时候就不用加std::了
    }
    int foo(int); //函数声明
}

//命名空间名字如果一致,最后所有的属性和方法相加在一起,而不会覆盖
namespace zs {
    int age;
}

//函数实现
int zs::foo(int n) {
    return ++n;
}

namespace xx {
    const char * psz = "xiangxiang";
}

void show (void) {
    std::cout << "不在任何命名空间里的show()" <<std::endl;
}

int main(int argc, const char * argv[]) {
    wfh::show();
    zs::show();
    using namespace wfh;
    //show(); //如果没有全局的show(),这里直接这么写,就能调用wfh命名空间下的show
    
    //注意:如果上边已经指定了命名空间,这里就不能再这么写,因为对于编译器来说,相当于两个命名空间编译器都能看到了,不知道该调用哪个
    //    using namespace zs;
    //    show();
    zs::show();//只用用这种方式
    
    ::show(); //加上::相当于调用全局的show()函数,否则编译器会不知道调用哪个show
    
    using xx::psz;//名字空间声明
    std::cout << psz << std::endl;
    return 0;
}
