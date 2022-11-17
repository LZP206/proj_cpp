/*

- copy(iterator beg, iterator end, iterator dest);
    // 按值查找元素，找到返回指定位置迭代器，找不到返回结束迭代器位置
    // beg  开始迭代器
    // end  结束迭代器
    // dest 目标起始迭代器

- replace(iterator beg, iterator end, oldvalue, newvalue);
    // 将区间内旧元素 替换成 新元素
    // beg 开始迭代器
    // end 结束迭代器
    // oldvalue 旧元素
    // newvalue 新元素

- replace_if(iterator beg, iterator end, _pred, newvalue);
    // 按条件替换元素，满足条件的替换成指定元素
    // beg 开始迭代器
    // end 结束迭代器
    // _pred 谓词
    // newvalue 替换的新元素

- swap(container c1, container c2);
    // 互换两个容器的元素
    // c1容器1
    // c2容器2
*/


#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>





//---------------------------------------------------------------------------
// 1.copy

class MyPrint
{
    public:
    void operator()(int val){cout << val << " ";}
};

void test01()
{
    vector<int> VEC_INT01;
    for (int i = 0; i < 10; i++) {VEC_INT01.push_back(i + 1);}
    vector<int> VEC_INT02;
    VEC_INT02.resize(VEC_INT01.size());

    copy(VEC_INT01.begin(), VEC_INT01.end(), VEC_INT02.begin());

    for_each(VEC_INT02.begin(), VEC_INT02.end(), MyPrint());
    cout << endl;
}





//---------------------------------------------------------------------------
// 2.replace

void test02()
{
    vector<int> VEC_INT;
    VEC_INT.push_back(20);
    VEC_INT.push_back(30);
    VEC_INT.push_back(20);
    VEC_INT.push_back(40);
    VEC_INT.push_back(50);
    VEC_INT.push_back(10);
    VEC_INT.push_back(20);

    cout << "替换前：" << endl;
    for_each(VEC_INT.begin(), VEC_INT.end(), MyPrint());
    cout << endl;

    //将容器中的20 替换成 2000
    cout << "替换后：" << endl;
    replace(VEC_INT.begin(), VEC_INT.end(), 20,2000);
    for_each(VEC_INT.begin(), VEC_INT.end(), MyPrint());
    cout << endl;
}





//---------------------------------------------------------------------------
// 3.replace_if

class ReplaceGreater30
{
	public:
	bool operator()(int val){return val >= 30;}
};

void test03()
{
    vector<int> VEC_INT;
    VEC_INT.push_back(20);
    VEC_INT.push_back(30);
    VEC_INT.push_back(20);
    VEC_INT.push_back(40);
    VEC_INT.push_back(50);
    VEC_INT.push_back(10);
    VEC_INT.push_back(20);

    cout << "替换前：" << endl;
    for_each(VEC_INT.begin(), VEC_INT.end(), MyPrint());
    cout << endl;

    //将容器中大于等于的30 替换成 3000
    cout << "替换后：" << endl;
    replace_if(VEC_INT.begin(), VEC_INT.end(), ReplaceGreater30(), 3000);
    for_each(VEC_INT.begin(), VEC_INT.end(), MyPrint());
    cout << endl;
}







//---------------------------------------------------------------------------
// 4.swap

void test04()
{
    vector<int> VEC_INT01;
    vector<int> VEC_INT02;
    for (int i = 0; i < 10; i++) {
        VEC_INT01.push_back(i);
        VEC_INT02.push_back(i+100);
    }

    cout << "交换前： " << endl;
    for_each(VEC_INT01.begin(), VEC_INT01.end(), MyPrint()); cout << endl;
    for_each(VEC_INT02.begin(), VEC_INT02.end(), MyPrint()); cout << endl;

    cout << "----------------------------" << endl;

    cout << "交换后： " << endl;
    swap(VEC_INT01, VEC_INT02);
    for_each(VEC_INT01.begin(), VEC_INT01.end(), MyPrint()); cout << endl;
    for_each(VEC_INT02.begin(), VEC_INT02.end(), MyPrint()); cout << endl;
}





//---------------------------------------------------------------------------
int main()
{
    test04();
    return 0;
}