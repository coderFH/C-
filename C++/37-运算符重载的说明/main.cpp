//
//  main.cpp
//  37-运算符重载的说明
//
//  Created by wangfh on 2019/5/20.
//  Copyright © 2019 Ne. All rights reserved.
//

#include <iostream>
using namespace std;

class Mail;
class Sender {
private:
    string m_strTarget;
public:
    Sender(const string& strTarget) : m_strTarget(strTarget){}
    Sender& operator<< (const Mail& mail);
};

class Mail {
private:
    string m_title;
    string m_content;
    friend Sender& Sender::operator<< (const Mail&);
public:
    Mail(const string& title,const string& content) : m_title(title),m_content(content) {}
};

Sender& Sender::operator<< (const Mail& mail) {
    cout << m_strTarget << endl;
    cout << mail.m_title << endl;
    cout << mail.m_content << endl;
    return *this;
}

int main() {
    Sender sender("315999946@qq.com");
    Mail mail("今日会议","下午五点开会,请准时参加");
    //对于左右操作数类型不同的双目运算符函数，通常需要被定义为左操作数类型的成员，同时也是右操作数类型的友元。
    sender << mail; //sender.operator<<(mail);
    return 0;
}
