#include <iostream>
using namespace std;


int main()
{


    // 4.3.3 goto语句：无条件跳转语句
    cout << "1" << endl;

	goto FLAG;  // FLAG为标记，一般用一个纯大写的名字

	cout << "2" << endl;
	cout << "3" << endl;
	cout << "4" << endl;

	FLAG:  // 注意是冒号！！！！表示确认标记位置

	cout << "5" << endl;

    //注意：在程序中不建议使用goto语句，以免造成程序流程混乱








/*
    // 4.3.2 continue 作用：跳过本次循环中余下尚未执行的语句，继续执行下一次循环
    for (int i = 0; i < 100; i++)
	{
		if (i % 2 == 0)
		{
			continue;
		}
        cout << i << endl;
	}
*/








/*
    // 4.3.1 break语句
    // 1、（选择结构）switch语句中终止case并跳出switch
    cout << "请选择副本难度" << endl;
    cout << "1、普通" << endl;
    cout << "2、中等" << endl;
    cout << "3、困难" << endl;
    int num = 0;
    cin >> num;
    switch (num)
    {
    case 1:
        cout << "您选择的是普通难度" << endl;
        break;
    case 2:
        cout << "您选择的是中等难度" << endl;
        break;
    case 3:
        cout << "您选择的是困难难度" << endl;
        break;
    }
*/

/*
    // 2、循环语句中
    for (int i = 0; i < 10; i++)
	{
		if (i == 5)
		{
			break; //跳出循环语句
		}
		cout << i << endl;
	}
*/

/*
    // 3、嵌套语句中
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {

            if (i == j)
            {
                break;
            }

            cout << "* ";

        }
        cout << endl;
    }
*/

    return 0;
}