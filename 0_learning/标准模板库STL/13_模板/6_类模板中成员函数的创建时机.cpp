#include <iostream>
using namespace std;


// 类模板中成员函数和普通类中成员函数创建时机是有区别的：

// * 普通类中的成员函数一开始就可以创建
// * 类模板中的成员函数在调用时才创建



class Person01
{
public:
    void showPerson01()
    {
        cout << "Person01 show" << endl;
    }
};
class Person02
{
public:
    void showPerson02()
    {
        cout << "Person02 show" << endl;
    }
};



// --------------------------------------------------------

template<typename T>
class MyClass
{
public:
    void func1(){ obj.showPerson01(); }
    void func2(){ obj.showPerson02(); }

    T obj;
};




void test01()
{
    MyClass<Person01> m1;
    m1.func1();
    //m1.fun2();//编译会出错，说明函数调用才会去创建成员函数
}



int main()
{
    test01();

    system("pause");
    return 0;
}