#include <iostream>
using namespace std;

// 6.2 函数的定义  5个步骤：
// 1、返回值类型 ：一个函数可以返回一个值！！
// 2、函数名
// 3、参数表列
// 4、函数体语句
// 5、return 表达式 ：和返回值类型挂钩，函数执行完后，返回相应的数据！！
/*
**语法：**
返回值类型 函数名 （参数列表）
{

       函数体语句

       return表达式

}
*/
// 定义一个加法函数，实现两个数相加
int add (int num1, int num2)  // num1，num2并没有实际的值，为形参
{
    int sum = num1 + num2;
    return sum;
}



// 定义函数，实现两个数字进行交换
void swap_temp(int num1, int num2) // 如果函数不需要返回值，声明的时候可以写无类型：void
{
    cout << "交换前：" << endl;
    cout << "num1 = " << num1 << endl;
    cout << "num2 = " << num2 << endl;

    int temp = num1;
    num1 = num2;
    num2 = temp;

    cout << "交换后：" << endl;
    cout << "num1 = " << num1 << endl;
    cout << "num2 = " << num2 << endl;

    return; //不需要返回值，可以不写return
}




// 6.5 函数的常见样式4种
// 1. 无参无返
void test01()
{
    //void a = 10; //无类型不可以创建变量,原因无法分配内存
    cout << "this is test01" << endl;
}
//test01(); 函数调用

// 2. 有参无返
void test02(int a)
{
    cout << "this is test02" << endl;
    cout << "a = " << a << endl;
}

// 3. 无参有返
int test03()
{
    cout << "this is test03 " << endl;
    return 10;  // 有返回值！！！
}

// 4. 有参有返
int test04(int a, int b)
{
    cout << "this is test04 " << endl;
    int sum = a + b;
    return sum;
}



// 6.6 函数的声明   (提前告诉编译器函数名称及如何调用函数。函数的实际主体可以单独定义在main主函数后面。)
// 比较函数，实现两个整形数字进行比较，返回较大的值
//声明  （声明可以多次，定义只能一次）
int max(int a, int b);
int max(int a, int b);
//定义
int max(int a, int b)
{
    return (a > b ? a : b);
}




int main()
{
    int a = 100;
    int b = 200;

    cout << max(a, b) << endl;








/*
    // 6.4 值传递(函数调用时实参将数值传入给形参)
    // 值传递时，==如果形参发生，并不会影响实参==!!!!!!!!!!!!!!!!!!
    int a = 10, b = 20;

	swap_temp(a, b);
    cout << "main中的 a = " << a << endl;
	cout << "main中的 b = " << b << endl;
*/





/*
    // 6.3 函数的调用语法：函数名（参数）
    int a = 10, b = 20;

    int c = add(a,b);  // a,b 有实际的值，为实参
    cout << c << endl;  // 当调用函数时，实参的值会传递给形参，return输出的值赋值给c

    a = 100, b = 100;
	c = add(a, b);
	cout << c << endl;
*/

    return 0;
}

