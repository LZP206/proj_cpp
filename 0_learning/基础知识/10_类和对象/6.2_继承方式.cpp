#include <iostream>
using namespace std;

//公共继承
class Base1
{
public:
    int m_A;

protected:
    int m_B;

private:
    int m_C;
};


//1.公共继承
class Son1 : public Base1
{
public:
    void func()
    {
        m_A = 10; //父类中的公共权限成员在子类中依然是==公共权限==
        m_B = 10; //父类中的保护权限成员在子类中依然是==保护权限==

        //m_C = 10; //报错：成员 "Base1::m_C" (已声明 所在行数:14) 不可访问
    }
};

void test01()
{
    Son1 s1;
    s1.func();
    cout << s1.m_A << endl;
    s1.m_A = 100;
    cout << s1.m_A << endl;   


    //s1.m_B = 100;  //报错：成员 "Base1::m_B" (已声明 所在行数:11) 不可访问
    //因为在Son1类中成员m_A是==public==,而成员m_B是==protected==，保护权限成员类外不可访问
}


//2.保护继承
class Son2 : protected Base1
{
public:
    void func()
    {
        m_A = 10; //父类中的公共权限成员在子类中变为==保护权限==
        m_B = 10; //父类中的保护权限成员在子类中依然是==保护权限==

        //m_C = 10; //报错：成员 "Base1::m_C" (已声明 所在行数:14) 不可访问
    }
};

void test02()
{
    Son2 s2;
    s2.func();
    //cout << s2.m_A << endl;
    //s2.m_A = 100;
    //s1.m_B = 100;  //报错：成员 "Base1::m_B" (已声明 所在行数:11) 不可访问
    //因为在Son2类中成员m_A和m_B都是==protected==，保护权限成员类外不可访问
}


//3.私有继承
class Son3 : private Base1
{
public:
    void func()
    {
        m_A = 10; //父类中的公共权限成员在子类中变为==私有权限==
        m_B = 10; //父类中的保护权限成员在子类中变为==私有权限==

        //m_C = 10; //报错：成员 "Base1::m_C" (已声明 所在行数:14) 不可访问
    }
};

void test03()
{
    Son3 s3;
    s3.func();
    // cout << s3.m_A << endl;
    // s3.m_A = 100;
    //s1.m_B = 100;  //报错：成员 "Base1::m_B" (已声明 所在行数:11) 不可访问
    //因为在Son2类中成员m_A和m_B都是==private==，私有权限成员类外不可访问
}


class Grandson3 : public Son3
{
public:
    void func()
    {
        // m_A = 1000;
        // m_B = 1000;
        //报错：成员 "Base1::m_A" (已声明 所在行数:8) 不可访问C/C++(265)
        //原因：成员m_A和m_B在Son3类中已经是==private==，Granson3类用公共继承的方式也无法访问（无法继承私有成员）
    }
};






int main()
{
    test01();
    test02();
    test03();

    return 0;
}