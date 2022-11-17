#include <iostream>
using namespace std;

// 父类中私有成员也是被子类继承下去了，只是由编译器给隐藏后访问不到

// 利用开发人员命令提示工具查看对象模型：
// 打开工具窗口后，
// 1. 定位到当前CPP文件的盘符 `D:` 按回车
// 2. 输入`cd {文件路径}`
// 3. 输入`dir`查看路径目录
// 4. 然后输入 `cl /d1 reportSingleClassLayout{查看的类名} {所属文件名}`

class Base
{
public:
    int m_A;

protected:
    int m_B;

private:
    int m_C;

public:
    void writem_C(int c)
    {
        m_C = c;
    }
    int readm_C()
    {
        return m_C;
    }
    void writem_B(int d)
    {
        m_B = d;
    }
    int readm_B()
    {
        return m_B;
    }
};

class Son : public Base
{
public:
    int m_D;

    void func()
    {
        m_A = 10;
        m_B = 10;     //protected直接可以访问
        m_D = 10;
        //m_C = 10; //访问不到报错
        this->writem_C(10); //通过public成员函数访问
    }
};





void test01()
{
    cout << "size of Son = " << sizeof(Son) << endl;
    //结果为==16==，即父类中所有的非静态成员变量都会被子类继承；
    //父类中的私有成员被编译器隐藏，因此访问不到，但会被继承；

    Son s1;
    s1.writem_C(20);
    cout << "m_C = " << s1.readm_C() << endl;
    
    s1.func();
    cout << "m_A = " << s1.m_A << endl;
    cout << "m_B = " << s1.readm_B() << endl;  //protected和private成员类外访问必须通过public成员函数
    cout << "m_C = " << s1.readm_C() << endl;
    cout << "m_D = " << s1.m_D << endl;
}




int main()
{
    test01();

    return 0;
}