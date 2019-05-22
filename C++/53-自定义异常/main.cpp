//
//  main.cpp
//  53-自定义异常
//
//  Created by wangfh on 2019/5/22.
//  Copyright © 2019 Ne. All rights reserved.
//

#include <iostream>
using namespace std;

class MyException {
public:
    MyException (const string& strFile, int nLine, const string& strMsg) : m_strFile (strFile), m_nLine (nLine), m_strMsg (strMsg) {}
    friend ostream& operator<< (ostream& os, const MyException& exp) {
        return os << exp.m_strFile << ":" << exp.m_nLine << " - " << exp.m_strMsg;
    }
private:
    string m_strFile;
    int m_nLine;
    string m_strMsg;
};

class FileException : public MyException {
public:
    FileException (const string& strFile, int nLine, const string& strMsg) : MyException (strFile, nLine, strMsg) {}
};

class MemException : public MyException {
public:
    MemException (const string& strFile, int nLine, const string& strMsg) : MyException (strFile, nLine, strMsg) {}
};

class MWException : public exception {
public:
    const char* what (void) const throw () {
        return "我错了！";
    }
};

void config (int n) throw (FileException,MemException,MWException,exception) { //异常说明 如果()内什么都不写,就捕获不到任何异常
    if (n == 10)
        throw FileException(__FILE__, __LINE__, "网络配置文件不存在");
    if (n == 20)
        throw MemException (__FILE__, __LINE__, "内存不够分配");
    if (n == 30)
        throw MWException ();
    throw 100;
}

int main (void) {
    try {
        config (10);
    } catch (FileException& ex) {
        cout << ex << endl;
    } catch (MemException& ex) {
        cout << ex << endl;
    } catch (exception& ex) {
        cout << ex.what () << endl;
    } catch (...) {
        cout << "收到未知异常。" << endl;
    }
    return 0;
}

