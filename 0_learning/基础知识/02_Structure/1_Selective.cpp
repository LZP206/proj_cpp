#include <iostream>
using namespace std;

#include <string> //在写C++风格的字符串时要包含这个头文件（VScode不添加也可）

int main()
{


    // 4.1.3 switch 语句
/*  switch(表达式)
    {
   	case 结果1：执行语句;break;
   	case 结果2：执行语句;break;
 	...
 	default:执行语句;break;
    }
*/

    //案例电影打分 10~9经典，8~7非常好，6~5一般，5以下烂片
    cout << "请给电影打分" << endl;
    int score = 0;
    cin >> score;
    cout << "你给电影的打分为： " << score << endl;
    switch (score)
    {
        case 10:  //switch语句中表达式类型只能是整型或者字符型,因此不能判断区间!!
        case 9:
            cout << "经典电影" << endl;
            break;//退出当分支，不写break会一直向下执行!!
        case 8:
        case 7:
            cout << "电影非常好" << endl;
            break;
        case 6:
        case 5:
            cout << "电影一般" << endl;
            break;
        default:
            cout << "烂片" << endl;
            break;
    }

//与if语句比，对于多条件判断时，switch的结构清晰，执行效率高




/*
    // 4.1.2 三目运算符    表达式1 ? 表达式2 ：表达式3
    // 含义：如果表达式1为真，则执行表达式2；如果表达式1为假，则执行表达式3
    int a = 10, b = 20;
    int c = 0;
    c = (a > b ? a : b);   // 将a与b作比较，将变量大的值赋值给变量c
    cout << "c = " << c << endl;

    //在c++中三目运算符返回的值是 变量 ，可以继续赋值!!
    (a > b ? a : b) = 100;
    cout << "a = " << a << endl;
	cout << "b = " << b << endl;


    //三目运算符可以用于字符、字符串型变量   (用法一致)
    string d = "hi";
    string e = "hello";
    string f = "ok";
    f = ( d == "abc" ? d : e );
    cout << "f = " << f << endl;

    ( d == "abc" ? e : f ) = "helloworld";
    cout << "e = " << e << endl;
*/





/*
    // 4.1.1 if语句：单行格式if语句，多行格式if语句，多条件的if语句

    //05 练习案例： 三只小猪称体重(有三只小猪ABC，请分别输入三只小猪的体重，并且判断哪只小猪最重？)
    // 先判断A和B谁重，在与C作比较
    int num1 = 0, num2 = 0, num3 = 0;
    cout << "请输入小猪A的体重" << endl;
    cin >> num1;
    cout << "请输入小猪B的体重" << endl;
    cin >> num2;
    cout << "请输入小猪C的体重" << endl;
    cin >> num3;
    if (num1 > num2)
    {
        if (num1 > num3)
        {
            cout << "小猪A最重" << endl;
        }
        else
        {
            cout << "小猪C最重" << endl;
        }
    }
    else
    {
        if (num2 > num3)
        {
            cout << "小猪B最重" << endl;
        }
        else
        {
            cout << "小猪C最重" << endl;
        }
    }

    // 04 if语句中嵌套if语句（以达到更精确的条件判断）
    int score = 0;
    cout << "请输入一个分数" << endl;
    cin >> score;
    cout << "你输入的分数为：" << score << endl;
    if (score > 600)
    {
        cout << "考上一本大学了！！！" << endl;
        if (score > 700)
        {
            cout << "恭喜你考上北大！！！" << endl;
        }
        else if (score >660)
        {
            cout << "恭喜你考上清华！！！" << endl;
        }
    }
    else if (score > 500)
    {
        cout << "考上二本大学了！！" << endl;
    }
    else if (score > 400)
    {
        cout << "考上三本大学了！" << endl;
    }
    else
    {
        cout << "没有考上本科" << endl;
    }


    // 03 多条件的if语句：`if(条件1){ 条件1满足执行的语句 }else if(条件2){条件2满足执行的语句}... else{ 都不满足执行的语句}`
    cout << "请输入一个分数" << endl;
    cin >> score;
    cout << "你输入的分数为：" << score << endl;
    if (score > 600)
    {
        cout << "考上一本大学了！！！" << endl;
    }
    else if (score > 500)
    {
        cout << "考上二本大学了！！" << endl;
    }
    else if (score > 400)
    {
        cout << "考上三本大学了！" << endl;
    }
    else
    {
        cout << "没有考上本科" << endl;
    }


    // 02 多行格式if语句 :  if(条件){条件满足执行的语句}else{条件不满足执行的语句}
    cout << "请输入一个分数" << endl;
    cin >> score;
    cout << "你输入的分数为：" << score << endl;
    if  (score > 600)      //注意if行不加分号！！
    {
        cout << "考上一本大学了！！！" << endl;
    }
    else
    {
        cout << "未考上一本大学，继续努力!" << endl;
    }


    // 01 单行格式if语句 :  if(条件){条件满足执行的语句}
    cout << "请输入一个分数" << endl;
    cin >> score;
    cout << "你输入的分数为：" << score << endl;
    if  (score > 600)      //注意if行不加分号！！
    {
        cout << "考上一本大学了！！！" << endl;
    }

*/


    return  0;
}

