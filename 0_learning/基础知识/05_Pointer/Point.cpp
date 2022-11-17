#include <iostream>
using namespace std;

#include "sort_print_Array.h"
#include "swap_new.h"



int main()
{
    // 7.8 指针、数组、函数
    // 案例描述：封装一个函数，利用冒泡排序，实现对整型数组的升序排序
    int arr[10] = { 4,3,6,9,1,2,10,8,7,5 };
    int len = sizeof(arr) / sizeof(arr[0]);
    bubbleSort(arr, len);
    printArray(arr, len);



    // 7.7 指针和函数  (值传递和地址传递)
    int a = 10;
    int b = 20;
    swap1(a, b); // 值传递不会改变实参
    cout << "值传递:" << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    swap2(&a, &b); //地址传递会改变实参
    cout << "地址传递:" << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;






/*
    // 7.6 指针和数组: 利用指针访问数组中元素
    int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
    cout << "第一个元素： " << arr[0] << endl;
    int * p = arr;  //指向数组的指针  arr就是数组的首地址
    cout << "指针访问第一个元素： " << *p << endl;
    cout << endl;
    for (int i = 0; i < 10; i++)
    {
        //利用指针遍历数组
        cout << "指针访问第" << i+1 << "个元素： " << *p << endl;
        p++;  // 让指针向后偏移 4个字节 = sizeof(int)
    }
*/




/*
    // 7.5 const修饰指针: 三种情况
    // 技巧：看const右侧紧跟着的是指针还是常量, 是指针就是常量指针，是常量就是指针常量
    int a = 10;
    int b = 10;

    // 常量指针：const修饰指针，指针指向可以改，指针指向的值不可以更改
    const int * p1 = &a;
    p1 = &b;       //正确
    // *p1 = 100;  //报错

    // 指针常量：const修饰常量，指针指向不可以改，指针指向的值可以更改
    int * const p2 = &a;
    //p2 = &b; //错误
    *p2 = 100; //正确

    // const既修饰指针又修饰常量
    const int * const p3 = &a;
    //p3 = &b;    //错误
    // *p3 = 100; //错误

*/



/*
    // 7.4 空指针和野指针
    // 空指针：指针变量指向内存中编号为0的空间
    int * p = nullptr;   // 用途：初始化指针变量
    cout << *p << endl;  // 访问空指针报错, 注意：空指针指向的内存是不可以访问的

    // 野指针：指针变量指向非法的内存空间
    int * p2 = (int *)0x1100;  // 自己只能内存，没有事先定义
    cout << *p2 << endl;  // 访问野指针报错
*/


/*
    // 7.3 指针所占内存空间 : 32位操作系统下4byte；64位操作系统下8byte
    int a = 10;
    int * p = &a;
    cout << "*p = " << *p << endl; // * 解引用
    cout << "sizeof(p) = " << sizeof(p) << endl;
    cout << "sizeof(char *) = " << sizeof(char *) << endl;  // 不同数据类型的指针大小一样
    cout << "sizeof(float *) = " << sizeof(float *) << endl;
    cout << "sizeof(double *) = " << sizeof(double *) << endl;
*/


/*
    // 7.2 指针变量的定义和使用
    int a = 10;
    int * p = &a;// 定义语法： 数据类型 * 变量名
    //p = &a; // 建立关系：让指针记录变量a的地址  取址符&
    cout << "&a = "<< &a << endl; //打印数据a的地址
    cout << "p = " << p << endl;  //打印指针变量p  两者相同！

    // 可以通过"解引用"的方式 对该地址内存进行读和写的操作
    cout << "*p = " << *p << endl;
    cout << "a = " << a << endl;
*/

    return 0;
}
