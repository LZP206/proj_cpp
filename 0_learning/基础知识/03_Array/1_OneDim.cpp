#include <iostream>
using namespace std;



int main()
{
    // 5.2.3 冒泡排序算法：最常用的排序算法，对数组内元素进行排序
    // 示例：将数组 { 4,2,8,0,5,7,1,3,9 } 进行升序排序
    int arr[9] = { 4,2,8,0,5,7,1,3,9 };
    cout << "排序前：" << endl;
    for (int i = 0; i < 9; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    int temp;
    for (int i = 0; i < 9-1; i++)  // 排序总轮数=元素个数-1
    {
        for (int j = 0; j < 9-1-i; j++)  // 每轮对比次数= 元素个数-1-排序轮次
        {
            if (arr[j] > arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }

    }

    cout << "升序后：" << endl;
    for (int i = 0; i < 9; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    int start = 0;
    int end = sizeof(arr) / sizeof(arr[0]) - 1;
    while (start < end)
    {
        temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
    cout << "降序后：" << endl;
    for (int i = 0; i < 9; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;





/*
    // 5.2.2 一维数组数组名
    // 用途：1. 可以统计整个数组在内存中的长度;
    int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
    cout << "整个数组所占内存空间为： " << sizeof(arr) << endl;
	cout << "每个元素所占内存空间为： " << sizeof(arr[0]) << endl;
	cout << "数组的元素个数为： " << sizeof(arr) / sizeof(arr[0]) << endl;

    // 用途：2. 可以获取数组在内存中的首地址
    cout << "数组首地址为： " << arr << endl;     // arr为常量，定义好数组后地址就分配完成，无法更改
	cout << "数组中第一个元素地址为： " << &arr[0] << endl;
	cout << "数组中第二个元素地址为： " << &arr[1] << endl;
*/






/*
// 案例 在一个数组中记录了五只小猪的体重，如：int arr[5] = {300,350,200,400,250};找出并打印最重的小猪体重。
    int arr[5] = {300,350,200,400,250};
    int max = 0;
    for (int i = 0; i < 5; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
        else
        {
            max = max;
        }
    }
    cout << max << endl;
*/





/*
// 案例描述 请声明一个5个元素的数组，并且将元素逆置.(如原数组元素为：1,3,2,5,4;逆置后输出结果为:4,5,2,3,1);
int arr[5] = {1,3,2,5,4};
for (int i = 0; i < 5; i++)
{
	cout << arr[i];
}
cout << endl;

int start = 0;
int end = sizeof(arr) / sizeof(arr[0]) - 1;
int temp;
while (start < end)
{
    temp = arr[start];
    arr[start] = arr[end];
    arr[end] = temp;
    start++;
    end--;
}
for (int i = 0; i < 5; i++)
{
	cout << arr[i];
}
cout << endl;
*/





/*
    // 5.2.1 一维数组定义方式 3种
    // 方式一： 数据类型 数组名[元素个数]
    int score[10];
	//利用下标赋值
	score[0] = 100;
	score[1] = 99;
	score[2] = 85;
	//利用下标逐个输出
	cout << score[0] << endl;  // // 对应索引0~9, 下标从0开始索引!!
	cout << score[1] << endl;
	cout << score[2] << endl;


    // 方式二： 数据类型 数组名[元素个数] = {值1，值2，值3...}
    int score2[10] = { 100, 90,80,70,60,50,40,30 }; //如果{}内不足10个数据，剩余数据用0补全
	for (int i = 0; i < 10; i++)//一个一个输出太麻烦，因此可以利用循环进行输出
	{
		cout << score2[i] << endl;
	}


    // 方式三： 数据类型 数组名[] = {值1，值2，值3...}
    int score3[] = { 100,90,80,70,60,50,40,30,20,10 };
	for (int i = 0; i < 10; i++)
	{
		cout << score3[i] << endl;
	}
*/


    return 0;
}


// 特点1：数组中的每个数据元素都是相同的数据类型

// 特点2：数组是由连续的内存位置组成的

// 下标从0开始索引
