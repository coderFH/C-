//
//  main.cpp
//  18-练习
//
//  Created by Ne on 2019/5/1.
//  Copyright © 2019 Ne. All rights reserved.
//

#include <iostream>
#include <ctime>

using namespace std;

/* 练习：
* 定义一个类Girl 属性：姓名 年龄 是否有男朋友
* 提供一个无参构造函数 和一个有参构造函数  以及用于显示全部属性的成员函数
*/
class Girl {
private:
    string m_name;
    int m_age;
    bool m_isHaveBoyFriend;
public:
    Girl() {
        m_name = "没名";
        m_age = 0;
        m_isHaveBoyFriend = false;
    }
    Girl(string name,int age,bool isFriend) {
        m_name = name;
        m_age = age;
        m_isHaveBoyFriend = isFriend;
    }
    void show() {
        string haveFriend = m_isHaveBoyFriend ? "有男朋友" : "没有男朋友";
        cout << "我叫" << m_name << ",我今年" << m_age << "岁,我" << haveFriend << endl;
    }
};

/*练习： time();  localtime();
* 定义一个类Clock
* 属性：时  分  秒
* 无参构造函数，用当前的系统时间初始化时分秒属性
* 成员函数Run(),打印当前时间
* Clock clock;
* clock.Run();
 */
class Clock {
public:
    Clock();
    Clock(int hours,int minters,int second);
    void run();
private:
    int m_hours;
    int m_minters;
    int m_second;
    void Tick(void) {
        cout << "时间在这里递增" << endl;
    }
    void show(void) {
        cout << '\r' << m_hours << ":" << m_minters << ":" << m_second << flush; //flush刷新屏幕
    }
};

Clock::Clock() {
    time_t t = time(NULL);
    tm *pt = localtime(&t);
    m_hours = pt ->tm_hour;
    m_minters = pt -> tm_min;
    m_second = pt -> tm_sec;
}
Clock::Clock(int hours,int minters,int second) {
    m_hours =hours;
    m_minters = minters;
    m_second = second;
}

void Clock::run() {
    for (;;) {
        show();
        Tick();
    }
}

int main(int argc, const char * argv[]) {
    Girl girl1;
    girl1.show();
    
    Girl girl2("张韶涵",28,true);
    girl2.show();

    Clock clock;
    clock.run();
    
    Clock clock1;
    clock1.run();
    
    return 0;
}


