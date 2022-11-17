#include <iostream>
using namespace std;

//1. 值传递
void mySwap01(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
}

//2. 地址传递
void mySwap02(int * a, int * b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

//3. 引用传递
void mySwap03(int & a, int & b) {
    int temp = a;
    a = b;
    b = temp;
}



//返回局部变量引用
int & test01() {
    int a = 10; //a为局部变量
    return a;   // a在栈区！
}
//返回静态变量引用
int& test02() {
    static int a = 20;   //a为静态变量 存在全局区
    return a;    // 全局区数据在程序结束后有系统释放
}

//发现是引用，转换为 int* const ref = &a;
void func(int& ref){
    ref = 100; // ref是引用，转换为*ref = 100
}

//引用使用的场景，通常用来修饰形参
void showValue(const int & v) {
    //v += 10;   只读不能修改
    cout << v << endl;
}








int main() {
    // 6.常量引用  主要用来修饰形参，防止误操作
    //int& ref = 10;  引用本身需要一个合法的内存空间，因此这行错误
    //加入const就可以了，编译器优化代码，int temp = 10; const int& ref = temp;
    const int & ref = 10;

    //ref = 100;  //加入const后不可以修改变量，只读
    cout << ref << endl;

    //使用场景：函数中利用常量引用防止误操作修改实参
    int a = 10;
    showValue(a);





/*
    // 5.引用本质  **引用的本质在c++内部实现是一个指针常量
    int a = 10;

    //自动转换为 int* const ref = &a; 指针常量是指针指向不可改，也说明为什么引用不可更改
    int& ref = a;
    ref = 20; //内部发现ref是引用，编译器自动帮我们转换为: *ref = 20;

    cout << "a:" << a << endl;
    cout << "ref:" << ref << endl;
*/







/*
    // 4.引用做函数返回值  注意：不要返回局部变量引用  用法：函数调用作为左值

    //不能返回局部变量的引用
    int & ref = test01();
    cout << "ref = " << ref << endl;
    cout << "ref = " << ref << endl;

    int & ref2 = test02();
    cout << "ref2 = " << ref2 << endl;
    cout << "ref2 = " << ref2 << endl;

    //如果函数做左值，那么必须返回引用
    test02() = 1000;

    cout << "ref2 = " << ref2 << endl;
    cout << "ref2 = " << ref2 << endl;
*/






/*
    // 3.引用做函数参数
    // 作用：函数传参时，可以利用引用的技术让形参修饰实参
    // 优点：简化指针修改实参
    int a = 10;
    int b = 20;

    mySwap01(a, b);
    cout << "a:" << a << " b:" << b << endl;  //a:10 b:20 （不变）
    mySwap02(&a, &b);
    cout << "a:" << a << " b:" << b << endl;  //a:20 b:10 （改变）

    mySwap03(a, b);
    cout << "a:" << a << " b:" << b << endl;  //a:10 b:20 （改变）
*/



/*
    // 2.引用的注意事项  * 引用必须初始化   * 引用在初始化后，不可以改变
    int a = 10;
    int b = 20;
    //int &c; //错误，引用必须初始化
    int &c = a; //一旦初始化后，就不可以更改
    c = b; //这是赋值操作，不是更改引用

    cout << "a = " << a << endl;  // 20
    cout << "b = " << b << endl;  // 20
    cout << "c = " << c << endl;  // 20
*/





/*
    // 1.引用的基本使用    作用：给变量起别名
    int a = 10;
    int &b = a; // 语法：数据类型 &别名 = 原名

    cout << "a = " << a << endl;  // 10
    cout << "b = " << b << endl;  // 10

    b = 100;

    cout << "a = " << a << endl;  // 100
    cout << "b = " << b << endl;  // 100

    cout << long(&a) << endl;   // a和b指向同一块地址
    cout << long(&b) << endl;
*/


    return 0;
}
