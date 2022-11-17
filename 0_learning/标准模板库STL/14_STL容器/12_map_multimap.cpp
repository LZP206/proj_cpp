#include <iostream>
using namespace std;
#include <map>


void printMap(map<int,int>&m)
{
	for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << "key = " << it->first << " value = " << it->second << endl;
	}
	cout << endl;
}


// --------------------------- 1.map构造和赋值 ---------------------------

// 构造
// map<T1, T2> mp;                 //map默认构造函数: 
// map(const map &mp);             //拷贝构造函数

// 赋值：
// map& operator=(const map &mp);  //重载等号操作符

void test01()
{
    //默认构造
	map<int,int> m; 
	m.insert(pair<int, int>(1, 10));  // 匿名对象
	m.insert(pair<int, int>(2, 20));
	m.insert(pair<int, int>(3, 30));
	printMap(m);

    //拷贝构造
	map<int, int> m2(m); 
	printMap(m2);

    //赋值
	map<int,int> m3;
	m3 = m2; 
	printMap(m3);
}







// --------------------------- 2.map大小和交换 ---------------------------

// size();          //返回容器中元素的数目
// empty();        //判断容器是否为空
// swap(st);      //交换两个集合容器
// 注意map和set一样大小操作没有resize

void test02()
{
	map<int, int> m;
	m.insert(pair<int, int>(1, 10));
	m.insert(pair<int, int>(2, 20));
	m.insert(pair<int, int>(3, 30));

	if (m.empty())
	{
		cout << "m为空" << endl;
	}
	else
	{
		cout << "m不为空" << endl;
		cout << "m的大小为：" << m.size() << endl;
	}
    cout << endl;


    map<int, int> m2;
	m2.insert(pair<int, int>(4, 100));
	m2.insert(pair<int, int>(5, 200));
	m2.insert(pair<int, int>(6, 300));

	cout << "交换前" << endl;
	printMap(m);
	printMap(m2);
    cout << "--------------------------" << endl;
	cout << "交换后" << endl;
	m.swap(m2);
	printMap(m);
	printMap(m2);

}








// --------------------------- 3.map插入和删除 ---------------------------

// insert(elem);           //在容器中插入元素。
// clear();                //清除所有元素
// erase(pos);             //删除pos迭代器所指的元素，返回下一个元素的迭代器。
// erase(beg, end);        //删除区间[beg,end)的所有元素 ，返回下一个元素的迭代器。
// erase(key);             //删除容器中值为key的元素。

void test03()
{
    //插入
	map<int, int> m;
    //----------------------------------------------------------
	m.insert(pair<int, int>(1, 10));	        //第一种插入方式
	m.insert(make_pair(2, 20));	                //第二种插入方式
	m.insert(map<int, int>::value_type(3, 30));	//第三种插入方式
	m[4] = 40; 	                                //第四种插入方式
    //----------------------------------------------------------
	printMap(m);

	//删除
	m.erase(m.begin());
	printMap(m);
	m.erase(3);
	printMap(m);

	//清空
	m.erase(m.begin(),m.end());
	m.clear();
	printMap(m);
}





// --------------------------- 4.map查找和统计 ---------------------------

// 与set容器一致：
// find(key);     //查找key是否存在,若存在，返回该键的元素的迭代器；若不存在，返回map.end();
// count(key);    //统计key的元素个数 （对于map，结果为0或者1）

void test04()
{
    map<int, int>m; 
	m.insert(pair<int, int>(1, 10));
	m.insert(pair<int, int>(2, 20));
	m.insert(pair<int, int>(3, 30));

	//查找
	map<int, int>::iterator pos = m.find(3);
	if (pos != m.end())
	{
		cout << "找到了元素 key = " << (*pos).first << " value = " << pos->second << endl;
	}
	else
	{
		cout << "未找到元素" << endl;
	}

	//统计
	int num = m.count(3);
	cout << "num = " << num << endl;
}







// --------------------------- 5.map容器排序 ---------------------------

// 学习目标：
// map容器默认排序规则为==按照key值进行 从小到大排序==，掌握如何改变排序规则

// 主要技术点：
// 利用仿函数，可以改变排序规则

//------------------------------------------------------
class MyCompare 
{
public:
	bool operator()(const int &v1, const int &v2) const
    {
		return v1 > v2;
	}
};
//------------------------------------------------------
//下面仿函数会报错，必须为==常函数==
// class MyCompare 
// {
// public:
// 	bool operator()(int v1, int v2)
//  {
// 		return v1 > v2;
// 	}
// };



void test05()
{
    //利用仿函数实现从大到小排序
	map<int, int, MyCompare> m;

	m.insert(make_pair(1, 10));
	m.insert(make_pair(2, 20));
	m.insert(make_pair(3, 30));
	m.insert(make_pair(4, 40));
	m.insert(make_pair(5, 50));

	for (map<int, int, MyCompare>::iterator it = m.begin(); it != m.end(); it++) 
    {
		cout << "key:" << it->first << " value:" << it->second << endl;
	}
}























// --------------------------------------------------------
int main()
{
    test05();
    return 0;
}