#include <iostream>
using namespace std;

//1.函数默认参数 default argument  函数的形参列表中的形参是可以有默认值的
//如果某个位置参数有默认值，那么从这个位置往后，从左向右，必须都要有默认值
int func1(int a, int b = 10, int c = 10) {
    return a + b + c;
}
//如果函数声明有默认值，函数实现的时候就不能有默认参数（函数声明和函数实现只能一个有默认参数，避免二义性）
int func2(int a = 10, int b = 10);
int func2(int a, int b) {
    return a + b;
}


//2.函数占位参数  函数的形参列表里可以有占位参数，用来做占位，调用函数时必须填补该位置
void func3(int a, int)  //占位参数也可以有默认值(int a, int =10)
{
    cout << "this is func" << endl;
}




//  3.函数重载   函数重载满足条件：
//  * 同一个作用域下
//  * 函数名称相同
//  * 函数参数**类型不同**  或者 **个数不同** 或者 **顺序不同**
void func()
{
    cout << "func 的调用！" << endl;
}
void func(int a)
{
    cout << "func (int a) 的调用！" << endl;
}
void func(double a)
{
    cout << "func (double a)的调用！" << endl;
}
void func(int a ,double b)
{
    cout << "func (int a ,double b) 的调用！" << endl;
}
void func(double a ,int b)
{
    cout << "func (double a ,int b)的调用！" << endl;
}
//函数返回值不可以作为函数重载条件
int func(double a, int b, int c)
{
	cout << "func (double a, int b, int c)的调用！" << endl;
}




//函数重载注意事项
//1、引用作为重载条件

void func00(int &a)
{
    cout << "func (int &a) 调用 " << endl;
}
void func00(const int &a)
{
    cout << "func (const int &a) 调用 " << endl;
}

//2、函数重载碰到函数默认参数
void func01(int a, int b = 10)
{
    cout << "func2(int a, int b = 10) 调用" << endl;
}
void func01(int a)
{
    cout << "func2(int a) 调用" << endl;
}


int main()
{
    // 3.函数重载  作用：函数名可以相同，提高复用性
    func();
    func(10);
    func(3.14);
    func(10,3.14);
    func(3.14 , 10);
    func(3.14 , 10, 20);

    //函数重载注意事项
    //1、引用作为重载条件
    int a = 10;
    func00(a); //调用无const  int &a = 10 不合法
    func00(10);//调用有const  const int &a = 10 合法

    //2、函数重载碰到函数默认参数
    //func01(10); //碰到默认参数产生歧义，需要避免








    // 2.函数占位参数
    func3(10,10); //占位参数必须填补



    // 1.函数默认参数 default argument
    cout << "ret = " << func1(20, 20) << endl;
    cout << "ret = " << func1(100) << endl;

    return 0;
}