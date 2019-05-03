//
//  main.cpp
//  23-const对象和const成员函数
//
//  Created by Ne on 2019/5/3.
//  Copyright © 2019 Ne. All rights reserved.
//

#include <iostream>
using namespace std;

class Student {
public:
    Student(string name) : m_StrName(name) {}
    //非常量型成员函数
    void SetName(const string& strName) {
        m_StrName = strName;
    }
    
    //正常情况下,我们使用一个函数去获取该类的一个成员变量
    //我们只想获取,但有的程序员可能就是会不小心把值给改了  比如 strName = "";
    //所以为了防止get方法去修改了值 可以在最后加上const
    //常量型成员函数
    string GetName(void) const {
//        strName = ""; //加上const后,这么写就报错了
        //this -> strName = ""; //上边一行 等价于这一句
        //加上const后  this指针就变成了一个常指针 指针指向的内容是不可以修改的 也就是const Student*
        
        //常量型成员函数去调用非常量型成员函数,照样报错,不可以,比如
//        SetName();
        m_cn++;
        cout << "GetName const 函数" << endl;
        return m_StrName;
    }
    
    //const属性不一样的时候,也可以构成重载关系
    //常量型成员函数与非常量成员函数构成重载关系
    string GetName() {
         cout << "GetName函数" << endl;
        return m_StrName;
    }
    
    
private:
    string m_StrName;
    //被声明为mutable的成员变量可以在常量型成员函数中被修改。
    mutable int m_cn;
};

int main(int argc, const char * argv[]) {
    Student s("张飞");
    //通过常量型的对象，引用，指针只能调用常量型成员函数，而通过非常量型的对象，引用，指针优先调用非常量型成员函数。
    cout << s.GetName() << endl;
    
    const Student& rs = s;
//    rs.SetName("关羽"); //照样报错,理由同下
    cout << rs.GetName() << endl;
    
    const Student *ps = &s;
    //this指针本来是指向调用对象,而调用对象是const Student *,而SetName却不是const型函数
    //说白了就是调用对象是常量,但this指针却不是常量
    //所以通过一个常类型的对象，引用或者指针，只能访问其常量类型的成员函数
//    ps -> SetName("赵云");  //照样报错,因为我ps常量类型的,而调用SetName方法是非常量型函数,this指针是非常类型的,所以报错
    cout << ps->GetName() << endl;
    return 0;
}
