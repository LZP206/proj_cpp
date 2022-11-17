#include <iostream>
using namespace std;


// 由程序员分配释放,若程序员不释放,程序结束时由操作系统回收
// 在C++中主要利用new在堆区开辟内存

int * func()
{
    // 在堆区开辟数据：new int(10)返回一个地址， 用指针接收
    int* a = new int; // 10这个数据人为开辟在堆区，指针a存放数据10的地址，指针a为局部变量存放在栈区
    *a =10;
    return a;
}


int main(){
    int *p = func();  // p记录数据10在堆区的地址

    cout << *p << endl;

    cout << *p << endl;

    //利用delete释放堆区数据
    delete p;

    //cout << *p << endl; //此时报错，释放的空间不可访问
    //局部变量 'p' may point to deallocated memory




    //堆区开辟数组
    int* arr = new int[10];  // 注意是中括号，表示一维数组10个元素

    for (int i = 0; i < 10; i++)
    {
        arr[i] = i + 100;
    }

    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << endl;
    }
    //释放数组 delete 后加 []
    delete[] arr;




    return 0;
}

