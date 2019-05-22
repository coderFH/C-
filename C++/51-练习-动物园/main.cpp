//
//  main.cpp
//  51-练习-动物园
//
//  Created by wangfh on 2019/5/22.
//  Copyright © 2019 Ne. All rights reserved.
//

#include <iostream>
using namespace std;

class Animal {
public:
    Animal(int nID) : m_nID(nID) {}
    virtual ~Animal(void) {
        cout << "自由万岁" << endl;
    }
    virtual string Like(void) const = 0;
    virtual void Eat(const string& strFood) const = 0;
    friend ostream& operator<< (ostream& os,const Animal& animal) {
        return os << "编号" << animal.m_nID;
    }
private:
    int m_nID;
};

class Fish : public Animal {
public:
    Fish(int nID,int nDis) : Animal(nID),m_nDis(nDis) {}
    ~Fish(void) {
        cout << "我可以游回大海了";
    }
    string Like(void) const {
        return "虾米";
    }
    void Eat(const string& strFood) const {
        cout << "我是小鱼,"  << static_cast<const Animal&>(*this) << "，最远游" << m_nDis << "。我爱吃" << strFood << "。" << endl;
    }
    
private:
    int m_nDis;
};

class Bird : public Animal {
public:
    Bird (int nID, int nHeight) : Animal (nID), m_nHeight (nHeight) {}
    ~Bird (void) {
        cout << "我可以飞向天空了。";
    }
    string Like (void) const {
        return "小鱼";
    }
    void Eat (const string& strFood) const {
        cout << "我是小鸟，" << static_cast<const Animal&> (*this) << "，最高飞" << m_nHeight << "。我爱吃" << strFood << "。" << endl;
    }
private:
    int m_nHeight;

};

class Lion : public Animal {
public:
    Lion (int nID, int nSpeed) : Animal (nID), m_nSpeed (nSpeed) {}
    ~Lion (void) {
        cout << "我可以回归森林了";
    }
    string Like (void) const {
        return "小鸟";
    }
    void Eat (const string& strFood) const {
        cout << "我是狮子，" << static_cast<const Animal&> (*this) << "，最快跑" << m_nSpeed << "。我爱吃" << strFood << "。" << endl;
    }
private:
    int m_nSpeed;
};

class Zoo {
public:
    Zoo (void) : m_nAnimals (0) {}
    ~Zoo (void) {
        for (int i = 0; i < m_nAnimals; i++)
            delete m_pAnimals[i];
    }
    void Raise (Animal* pAnimal) {
        if (m_nAnimals < sizeof (m_pAnimals) / sizeof (m_pAnimals[0]))
            m_pAnimals[m_nAnimals++] = pAnimal;
    }
    void Feed (void) {
        for (int i = 0; i < m_nAnimals; i++)
            m_pAnimals[i] -> Eat (m_pAnimals[i] -> Like ());
    }
private:
    Animal* m_pAnimals[10];
    int m_nAnimals;
};

int main(int argc, const char * argv[]) {
    Zoo zoo;
    zoo.Raise (new Fish (1000, 10));
//    zoo.Raise (new Fish (1001, 15));
    zoo.Raise (new Bird (1002, 20));
    zoo.Raise (new Lion (1003, 60));
//    zoo.Raise (new Bird (1004, 18));
//    zoo.Raise (new Lion (1005, 75));
    zoo.Feed ();

    return 0;
}
