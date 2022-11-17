#include <iostream>
using namespace std;

#include <ctime>   // time系统时间头文件
int main()
{
/*
    // 4.2.4 嵌套循环：在循环体中再嵌套一层循环
    // 利用嵌套循环实现星图
    for (int i = 0; i < 10; i++)//打印10行
    {
        for (int j = 0; j < 10; j++)//打印一行星图
        {
        cout << "* ";
        }
        cout << endl;
    }
*/
    // 案例描述：利用嵌套循环，实现九九乘法表
    for (int i = 1; i <= 9; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << i << "x" << j << "=" << i*j << "\t";  // \t前有5个或6个字符， 总共输入一次八个字符
        }
        cout << "\n";
    }






/*
    // 4.2.3 for 循环  语法：for(起始表达式;条件表达式;末尾循环体) { 循环语句; }
    for (int i = 0; i < 10; i++)
    {
        cout << i << endl;
    }

    //案例描述：从1开始数到数字100， 如果数字个位含有7，或者数字十位含有7，或者该数字是7的倍数，我们打印敲桌子，其余数字直接打印输出。
    for (int i = 1; i <= 100; i++)
    {
        if (i % 7 == 0 || i % 10 == 7 || i / 10 == 7)
        {
            cout << "敲桌子" << endl;
        }
        else
        {
            cout << i << endl;
        }

    }
*/





/*
    // 4.2.2 do... while 循环语句  语法：do{ 循环语句 } while(循环条件为true)
    //与while的区别在于 do...while会先执行一次循环语句，再判断循环条件
    //在屏幕中打印0~9 10个数字
    int num = 0;
    do
    {
        cout << "num = " << num++ << endl;
    }
    while (num <= 9); //注意这里有分号


    //案例描述：请利用do...while语句，求出所有3位数(100~999)中的水仙花数 (水仙花数是指一个3位数，它的每个位上的数字的 3次幂之和等于它本身。 例如：1^3 + 5^3+ 3^3 = 153)
    int num = 100;
    int a = 0, b = 0, c = 0 ;
    int i = 0;
    cout << "100~999中" << endl;
    do
    {
        a = num % 10;      // 获取个位
        b = num / 10 % 10; // 获取十位
        c = num / 10 / 10; // 获取百位
        if (a*a*a + b*b*b + c*c*c == num)
        {
            i++;
            cout << "第" << i << "个水仙花数为" << num << endl;
        }
        num++;
    } while (num < 1000);
*/










/*
    // 4.2.1 while 语句  语法：while(循环条件为true){ 循环语句 }
    //在屏幕中打印0~9 10个数字
    int num = 0;
    while (num <= 9)  // 括号为1（真） while就会死循环
    {
        cout << "num = " << num << endl;
        num++;
    }
    //程序必须提供跳出循环的出口，否则出现死循环



    // 案例描述：系统随机生成一个1到100之间的数字，玩家进行猜测，如果猜错，提示玩家数字过大或过小，如果猜对恭喜玩家胜利，并且退出游戏。


    srand((unsigned int)time(NULL));  //添加随机种子，利用当前系统时间生成随机数，防止每次随机数都一样!!
    int num1 = rand()%100;  //生成0~99的整数  伪随机！！

    int i = 0;
    cout <<  "您有5次的机会猜数" << endl;
    num1++;
    int num2 = 101;
    while (1)
    {
        cout <<  "输入你猜的数字" << endl;
        cin >> num2;
        i++;
        if (num2 > num1)
        {
            cout <<  "猜测的数字过大" << endl;
        }
        else if (num2 < num1)
        {
            cout <<  "猜测的数字过小" << endl;
        }
        else
        {
            cout <<  "您只用了" << i << "次机会就猜中了" << endl;
            break;//跳出while循环
        }
        if (i == 5)
        {
            cout <<  "您的5次的机会已用完，挑战失败" << endl;
            break;//跳出while循环
        }
    }
    cout <<  "正确数字为：" << num1 << endl;

*/

    return 0;
}
