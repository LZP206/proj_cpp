#include <iostream>
using namespace std;

// 纯虚函数语法：virtual 返回值类型 函数名(参数列表) = 0;
// 当类中有了纯虚函数，这个类也被称为==抽象类==

// 抽象类特点：
// 1.无法实例化对象
// 2.子类必须重写抽象类中的纯虚函数，否则也属于抽象类
class Base
{
    public:
    // virtual void func() = 0;
    virtual void func()
    {
        cout << "Base-func函数调用" << endl;
    }

    Base()
    {
        cout << "Base构造函数" << endl;
    }
    ~Base()
    {
        cout << "Base析构函数" << endl;
    }

    int m_A;
};


class Son : public Base
{
    public:
    virtual void func() 
    {
        cout << "func函数的调用" << endl;
    }

    Son()
    {
        cout << "Son构造函数" << endl;
    }
    ~Son()
    {
        cout << "Son析构函数" << endl;
    }
};



void test01()
{
    //Base b; 无法创建对象（实例化）
    //new Base;
    //报错：不允许使用抽象类类型 "Base" 的对象: -- 函数 "Base::func" 是纯虚拟函数
    //Son s;  子类必须重写抽象类中的纯虚函数，否则也属于抽象类，无法实例化对象报错

    Base * base = new Son;
    base->func();
    delete base;




    //---------------------------------------

    // Son s1;
    // Base & base1 = s1;
    // base1.func();

     

}





int main()
{
    test01();
    return 0;
}
