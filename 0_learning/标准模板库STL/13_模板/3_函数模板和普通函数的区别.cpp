#include <iostream>
using namespace std;


// **普通函数与函数模板区别：**

// * 普通函数调用时可以发生自动类型转换（隐式类型转换）
// * 函数模板调用时，如果利用自动类型推导，不会发生隐式类型转换
// * 如果利用显示指定类型的方式，可以发生隐式类型转换

int myAdd01(int a, int b)
{
    return a+b;
}
template<typename T>
T myAdd02(T a, T b)
{
    return a+b;
}

void test01()
{
    int a = 10;
    int b = 20;
    char c = 'c';
    cout << myAdd01(a,c) << endl; //正确，将char类型的'c'隐式转换为int类型  'c' 对应 ASCII码 99
    // cout << myAdd02(a,c) << endl; 报错，使用自动类型推导时，不会发生隐式类型转换
    cout << myAdd02<int>(a,c) << endl;//正确，如果用显示指定类型，可以发生隐式类型转换
}



// -------------------------------------------------------------------


// 普通函数与函数模板的调用规则如下：

// 1. 如果函数模板和普通函数都可以实现，优先调用普通函数
// 2. 可以通过空模板参数列表来强制调用函数模板
// 3. 函数模板也可以发生重载
// 4. 如果函数模板可以产生更好的匹配,优先调用函数模板

void myPrint(int a , int b)
{
    cout << "普通函数的调用" << endl;
}

template<typename T>
void myPrint (T a , T b)
{
    cout << "函数模板的的调用" << endl;
}

template<typename T>
void myPrint(T a , T b , T c)
{
    cout << "函数模板重载的调用" << endl;
}

void test02()
{
    //1、如果函数模板和普通函数都可以实现，优先调用普通函数
	// 注意 如果告诉编译器  普通函数是有的，但只是声明没有实现，或者不在当前文件内实现，就会报错找不到
    int a = 10;
    int b = 20;
    myPrint(a, b);  // 调用普通函数


    //2、可以通过空模板参数列表来强制调用函数模板
    myPrint<>(a, b); // 调用函数模板


    //3、函数模板也可以发生重载
    int c = 30;
    myPrint(a, b, c);  // 调用重载的函数模板


    //4、 如果函数模板可以产生更好的匹配,优先调用函数模板
    char c1 = 'a';
    char c2 = 'b';
    myPrint(c1, c2);  // 调用函数模板
}









int main()
{
    test02();
    return 0;
}
