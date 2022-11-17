#include <iostream>
using namespace std;

// 栈区数据由编译器管理开辟和释放（存放函数的参数值,局部变量等）
// 注意事项：不要返回局部变量的地址！！

int * func()
{
    int a = 10;  // 局部变量 存放在栈区，栈区的数据在函数执行完后自动释放
    return &a;   // 返回局部变量的地址 会出现问题
}


int main()
{
    int *p = func();

    cout << *p << endl;  // 输出10 第一次正确是因为编译器做了一次保留

    cout << *p << endl;  // 输出乱码 第二次就不在保留 原先那块地址上不在保留数据10

    return 0;
}
