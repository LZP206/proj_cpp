#include <iostream>
using namespace std;

// 注意事项：
// 1.两种方式：自动类型推导、显示指定类型；
// 2.自动类型推导，必须推导出一致的数据类型T,才可以使用；
// 3.模板必须要确定出T的数据类型，才可以使用；



template<typename T>     // typename = class
void myswap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

void test01()
{
    int a = 10;
    int b = 20;
    char c = 'c';
    myswap(a,b);  // 可推导出T = int
    // myswap(a,c);  报错

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
}



template<class T>
void func()
{
    cout << "func调用" << endl;
}



void test02()
{
    // func(); 报错：没有与参数列表匹配的 函数模板 "func" 实例
    func<int>();
}






int main()
{
    int a = 10;
    int b = 20;
    myswap<int>(a,b);    // 使用模板时必须确定出通用数据类型T，并且能够推导出一致的类型, 也可以指定<>

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    test02();
    return 0;
}