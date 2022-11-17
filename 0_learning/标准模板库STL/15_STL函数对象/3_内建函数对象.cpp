/*
STL内建了一些函数对象

分类:
- 算术仿函数
- 关系仿函数
- 逻辑仿函数

用法：
- 这些仿函数所产生的对象，用法和一般函数完全相同
- 使用内建函数对象，需要引入头文件 `#include<functional>`
*/



#include <iostream>
using namespace std;
#include <functional>
#include <vector>
#include <algorithm>




//---------------------------------------------------------------------------
// 1.算数仿函数

/*
功能描述：
- 实现四则运算
- 其中negate是一元运算，其他都是二元运算

仿函数原型：
- template<class T> T plus<T>           //加法仿函数
- template<class T> T minus<T>          //减法仿函数
- template<class T> T multiplies<T>     //乘法仿函数
- template<class T> T divides<T>        //除法仿函数
- template<class T> T modulus<T>        //取模仿函数
- template<class T> T negate<T>         //取反仿函数
*/

void test01()
{
    // negate<int> Neg;
    // int res = Neg(50);
    cout << "negativity of 50 is " << negate<int>()(50) << endl;

    // plus<int> p;
    // res = p(10,20);
	cout << "10 plus 20 is " << plus<int>()(10, 20) << endl;
}




//---------------------------------------------------------------------------
// 2.关系仿函数

/*
功能描述：
- 实现关系对比

仿函数原型：
- template<class T> bool equal_to<T>              //等于
- template<class T> bool not_equal_to<T>          //不等于
- template<class T> bool greater<T>               //大于
- template<class T> bool greater_equal<T>         //大于等于
- template<class T> bool less<T>                  //小于
- template<class T> bool less_equal<T>            //小于等于
*/

class MyCompare
{
public:
	bool operator()(int val1,int val2)
	{
		return val1 > val2;
	}
};

void test02()
{
    vector<int> VEC_TEST;
    for (int i = 10; i <= 50; i=i+10){VEC_TEST.push_back(i);}
    for (vector<int>::iterator it = VEC_TEST.begin(); it != VEC_TEST.end(); it++) 
    {
		cout << *it << " ";
	}
	cout << endl;

    //自己实现仿函数
	//sort(VEC_TEST.begin(), VEC_TEST.end(), MyCompare());

	//STL内建仿函数  大于仿函数
	sort(VEC_TEST.begin(), VEC_TEST.end(), greater<int>());

	for (vector<int>::iterator it = VEC_TEST.begin(); it != VEC_TEST.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}






//---------------------------------------------------------------------------
// 3.逻辑仿函数

/*
功能描述：
- 实现逻辑运算

函数原型：
- template<class T> bool logical_and<T>       //逻辑与
- template<class T> bool logical_or<T>        //逻辑或
- template<class T> bool logical_not<T>        //逻辑非
*/

void test03()
{
    vector<bool> VEC_TEST;
	VEC_TEST.push_back(true);
	VEC_TEST.push_back(false);
	VEC_TEST.push_back(true);
	VEC_TEST.push_back(false);

	for (vector<bool>::iterator it = VEC_TEST.begin();it!= VEC_TEST.end();it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	//逻辑非  将VEC_TEST容器搬运到VEC_TEST2中，并执行逻辑非运算
	vector<bool> VEC_TEST2;
	VEC_TEST2.resize(VEC_TEST.size());  // 开辟相同大小的空间

	transform(VEC_TEST.begin(), VEC_TEST.end(),  VEC_TEST2.begin(), logical_not<bool>());

	for (vector<bool>::iterator it = VEC_TEST2.begin(); it != VEC_TEST2.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}






//---------------------------------------------------------------------------
int main()
{
    test03();
    return 0;
}