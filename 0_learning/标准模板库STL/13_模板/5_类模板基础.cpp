#include <iostream>
using namespace std;



// 类模板基本语法
template<typename NameType, typename AgeType>
class Person01
{
public:
    Person01(NameType name, AgeType age)
    {
        this->m_Name = name;
        this->m_Age = age;
    }
    void showPersonInfo()
    {
        cout << "name: " << this->m_Name << "\t" << "age: " << this->m_Age << endl;
    }

    NameType m_Name;
    AgeType m_Age;
};


void test01()
{
    Person01<string, int> p1("Leon", 24);
    p1.showPersonInfo();
}








// --------------------------------------------------------------

// 类模板和函数模板的区别:
// 1. 类模板没有自动类型推导的使用方式
// 2. 类模板在模板参数列表中可以有默认参数


template<typename NameType, typename AgeType = int>
class Person02
{
public:
    Person02(NameType name, AgeType age)
    {
        this->m_Name = name;
        this->m_Age = age;
    }
    void showPersonInfo()
    {
        cout << "name: " << this->m_Name << "\t" << "age: " << this->m_Age << endl;
    }

    NameType m_Name;
    AgeType m_Age;
};




void test02()
{
    Person02<string> p2("Leon", 24);
    p2.showPersonInfo();    
}








int main()
{
    test01();
    test02();

    system("pause");
    return 0;
}

