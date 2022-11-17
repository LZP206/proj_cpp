#include <iostream>
using namespace std;



#include <string> //在写C++风格的字符串时要包含这个头文件（VScode不添加也可）
#define day 7

int main()
{
/*
    //3.4逻辑运算符 &&与，||或，！非
    // 逻辑非 ！
    int a5 = 10, b5 = 10;  //在c++中数字除了0都为真
	cout << "a5 = 10 时，!a5  = " << !a5 << endl; // 0
	cout << "a5 = 10 时，!!a5 = " << !!a5 << endl; // 1
    // 逻辑与 &&
    a5 = 10, b5 = 10;
    cout << "a5 = 10 b5 = 10 时, a5 && b5 = " << (a5 && b5) << endl;    //注意需要括号(),不然报错
    a5 = 10, b5 = 0;
    cout << "a5 = 10 b5 = 0  时, a5 && b5 = " << (a5 && b5) << endl;
    a5 = 0, b5 = 0;
    cout << "a5 = 0  b5 = 0  时, a5 && b5 = " << (a5 && b5) << endl;
    // 逻辑非 ||
    a5 = 10, b5 = 10;
    cout << "a5 = 10 b5 = 10 时, a5 || b5 = " << (a5 || b5) << endl;    //注意需要括号(),不然报错
    a5 = 10, b5 = 0;
    cout << "a5 = 10 b5 = 0  时, a5 || b5 = " << (a5 || b5) << endl;
    a5 = 0, b5 = 10;
    cout << "a5 =  0 b5 = 0  时, a5 || b5 = " << (a5|| b5) << endl;
*/



/*
    //3.3比较运算符 ==相等，!=不等，<小于，>大于，<=小于等于，>=大于等于
    int a4 = 10, b4 = 20;
	cout << "a4 == b4 为 " << (a4 == b4) << endl; // 0 假   //注意需要括号(),不然报错
	cout << "a4 != b4 为 " << (a4 != b4) << endl; // 1 真
	cout << "a4 > b4 为 "  << (a4 > b4) << endl;  // 0
	cout << "a4 < b4 为 "  << (a4 < b4) << endl;  // 1
	cout << "a4 >= b4 为 " << (a4 >= b4) << endl; // 0
	cout << "a4 <= b4 为 " << (a4 <= b4) << endl; // 1
*/




/*
    //3.2赋值运算符 =、+=、-=、*=、/=、%=
    // =
    int a3 = 10;
    a3 = 100;
    cout << "=赋值：a3 = " << a3 << endl;
    // +=
    a3 = 10;
    a3 += 2; // a3=a3+2
    cout << "+=赋值：a3 = " << a3 << endl;
    // -=
	a3 = 10;
	a3 -= 2; // a3=a3-2
	cout << "-=赋值：a3 = " << a3 << endl;
	// *=
	a3 = 10;
	a3 *= 2; // a3=a3*2
	cout << "*=赋值：a3 = " << a3 << endl;
	// /=
	a3 = 10;
	a3 /= 2;  // a3=a3/2;
	cout << "/=赋值：a3 = " << a3 << endl;
    // %=
	a3 = 10;
	a3 %= 2;  // a3=a3%2;
	cout << "%=赋值：a3 = " << a3 << endl;
*/




/*
    //3.1算数运算符
    //加减乘除 + - * /
    int a1 = 10, b1 = 3;
    double a2 = 10.5, b2 = 3.33;
    cout << "a1 + b1 = " << a1 + b1 << endl;
    cout << "a1 - b1 = " << a1 - b1 << endl;
    cout << "a1 * b1 = " << a1 * b1 << endl;
    cout << "a1 / b1 = " << a1 / b1 << endl;  //两个整型相除结果依然是整数
    cout << "a2 / b2 = " << a2 / b2 << endl;  //两个小数可以相除且结果依然是小数
    //取余运算 %
    cout << "a1 % b1 = " << a1 % b1 << endl;  //注意：除数不为0；两个小数不可以做取余运算
    //递增递减 ++ --
    ++a1;//前置递增
    cout << "++a1 = " << a1 << endl;
    b1++;//后置递增
    cout << "b1++ = " << b1 << endl;
    //前置后置区别
    a1 = b1 = 10;
    int c1 = 0, c2 = 0;
    c1 = ++a1 *10;
    c2 = b1++ *10;
    cout << "c1 = ++a1 *10 = " << c1 << endl;   // (10+1)*10=100  先做a1=a1+1,再c1=a1*10
    cout << "c2 = b1++ *10 = " << c2 << endl;   //  10+10=100     先做c2=a1*10,再a1=a1+1
*/






/*
    //2.8数据的输入  命令 cin >> 变量  (实现键盘赋值）
    //整型输入
    int a = 0;
    cout << "请给整型变量a赋值：" << endl;
    cin >> a;
    cout << "a = " << a <<endl;
    //浮点型输入
	double d = 0;
	cout << "请给浮点型变量d赋值：" << endl;
	cin >> d;
	cout << "d = " << d << endl;
    //字符型输入
    char ch = 'a';
    cout << "请给字符型变量ch赋值：" << endl;
    cin >> ch;
    cout << "ch = " << ch << endl;
    //字符串型输入
    string str = "abc";
    cout << "请给字符串型变量str赋值：" << endl;
    cin >> str;
    cout << "str = " << str << endl;
    //布尔类型输入
    bool flag = true;
    cout << "请给布尔类型变量flag赋值：" << endl;
    cin >> flag; //输入数字>=1时输出为1，输入数字0或其他时输出为0
    cout << "flag = " << flag << endl;
*/



/*
    //2.7数据类型：布尔bool（只有两个值，代表真1或假0）
    bool flag = true; //定义规则：bool 名 = 初始值（true/false）
    cout << flag << endl;
    flag = false;
    cout << flag << endl;
    cout << "bool sizeof = " << sizeof(flag)<< endl;  //查看bool变量所占内存大小（1byte）

    //2.6数据类型：字符串型（两种风格）
    char str1[] = "Hello world";  // C风格定义规则： char 字符串名[] = “字符串”  （双引）
    string str2 = "Hello world";  // C++风格定义规则：string 字符串名 = “字符串” （包含一个头文件）
    cout << str1 << endl;
    cout << str2 << endl;
    cout << "char[] sizeof = " << sizeof(str1)<< endl;  //查看字符串变量所占内存大小（char12byte）
    cout << "string sizeof = " << sizeof(str2)<< endl;  //查看字符串变量所占内存大小（string24byte）
*/
    //2.5数据类型：转义字符
    cout << "Hello world" << endl;    //换行符 \n
    cout << "Hello world\n";
    cout << "\\" << "\\" << endl;     //输出反斜杠
    cout << "a\tHello world" << endl; //水平制表符 \t （作用：对齐后半部分）
    cout << "aa\tHello world" << endl;
    cout << "aaa\tHello world" << endl;
/*
    //2.4数据类型：字符型
    char ch = 'a';  //定义规则：char 字符名 = ’字符‘（用单引号将字符括起来；单引号内只能有一个字符）
    cout << ch << endl;
    cout << "char sizeof = " << sizeof(ch) << endl;// 查看字符型变量所占内存大小（1byte）
    cout << (int)ch << endl; //查看字符型变量对应的ASCII码值（a对应97，A对应65）

    //2.2，2.3数据类型：实型（浮点型） float（4byte）、double（8byte）
    //默认情况下，输出一个小数最多显示6位有效数字
    float f1 = 3.14f;
    double f2 =  3.14;
    cout << f1 << endl;
    cout << f2 << endl;
    cout << "float sizeof = " << sizeof(f1) << endl;
    cout << "double sizeof = " << sizeof(f2) << endl;
    //科学计数法
	float f3 = 3e2; // 3 * 10 ^ 2
    float f4 = 3e-2;  // 3 * 0.1 ^ 2
	cout << "f3 = " << f3 << endl;
	cout << "f4 = " << f4 << endl;

    //2.1数据类型：整形 short（2byte）、int（4byte）、long(win4,linux8)、 long long（8）
    cout << "short 类型所占内存空间为： " << sizeof(short) << endl;
	cout << "int 类型所占内存空间为： " << sizeof(int) << endl;
	cout << "long 类型所占内存空间为： " << sizeof(long) << endl;
	cout << "long long 类型所占内存空间为： " << sizeof(long long) << endl;
*/









    //定义常量：1.宏常量（#define 常量名 常量值）；2.const修饰的变量（const 数据类型 常量名 = 常量值）
    const int month = 12;
    cout << "一年共有" << month << "个月份" << endl;
    cout << "一周共有" << day << "天" << endl;

    //变量创建的语法：数据类型 变量名 = 变量初始值
    int a = 10;
    cout << "a = " << a << endl;

    //C++书写HelloWorld
    cout << "Hello World" << endl;


    system("pause");
    return 0;
}

//1、单行注释
/*2、多行注释*/

//关键字
//标识符命名规则：1.标识符不能是关键字；2.由字母、数字、下划线组成；3.第一个字符不能是数字；4.字母区分大小写