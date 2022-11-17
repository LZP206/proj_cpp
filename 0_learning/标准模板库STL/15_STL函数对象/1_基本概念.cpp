#include <iostream>
using namespace std;
#include <string>

/*
特点：
- 函数对象在使用时，可以像普通函数那样调用, 可以有参数，可以有返回值
- 函数对象超出普通函数的概念，函数对象可以有自己的状态
- 函数对象可以作为参数传递
*/




//---------------------------------------------------------------------------
// 1.函数对象在使用时，可以像普通函数那样调用, 可以有参数，可以有返回值
class MyAdd 
{
    public:
    int operator()(int input_A, int input_B)
    {
        return input_A + input_B;
    }
};

void test01()
{
    MyAdd myadd;
    int res = myadd(10,20);        // 第一种
    // int res = MyAdd()(10,20);   // 第二种
    cout << "result = " << res << endl;
}






//---------------------------------------------------------------------------
// 2.函数对象超出普通函数的概念，函数对象可以有自己的状态
class MyPrint
{
    public:
    MyPrint() { m_Counter = 0;}
    
    void operator()(string intput_STR)
    {
        cout << intput_STR << endl;
        m_Counter++;  // 记录调用次数
    }

    int m_Counter;
};

void test02()
{
    MyPrint myprint;
    myprint("hello world");
    myprint("Tom & Jerry");
    myprint("hello C++");
    cout << "m_Counter = " << myprint.m_Counter << endl;
}





//---------------------------------------------------------------------------
// 3.函数对象可以作为参数传递
void doPrint(MyPrint &intput_myprint, string & intput_Str)
{
    intput_myprint(intput_Str);
}

void test03()
{
    MyPrint myprint;
    string str = "hello C++";
    doPrint(myprint, str);
}








//---------------------------------------------------------------------------
int main()
{
    test03();

    return 0;
}