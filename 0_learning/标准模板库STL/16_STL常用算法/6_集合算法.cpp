/*
- set_intersection(beg1, end1, beg2, end2, dest);
    // 求两个集合的交集  注意:两个集合必须是有序序列
    // beg1 容器1开始迭代器
    // end1 容器1结束迭代器
    // beg2 容器2开始迭代器
    // end2 容器2结束迭代器
    // dest 目标容器开始迭代器

- set_union(beg1, end1, beg2, end2, dest);
    // 求两个集合的并集  注意:两个集合必须是有序序列
    // beg1 容器1开始迭代器
    // end1 容器1结束迭代器
    // beg2 容器2开始迭代器
    // end2 容器2结束迭代器
    // dest 目标容器开始迭代器

- set_difference(beg1, end1, beg2, end2, dest);
    
    // 求两个集合的差集  注意:两个集合必须是有序序列
    // beg1 容器1开始迭代器
    // end1 容器1结束迭代器
    // beg2 容器2开始迭代器
    // end2 容器2结束迭代器
    // dest 目标容器开始迭代器
*/



#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>



//---------------------------------------------------------------------------
// 1.set_intersection

class MyPrint
{
    public:
    void operator()(int val){cout << val << " ";}
};

void test01()
{
    vector<int> VEC_INT01;
    vector<int> VEC_INT02;
    for (int i = 0; i < 10; i++){
        VEC_INT01.push_back(i);
        VEC_INT02.push_back(i+5);
    }

    vector<int> vTarget;
    //取两个里面较小的值给目标容器开辟空间
    vTarget.resize(min(VEC_INT01.size(), VEC_INT02.size()));

    //返回目标容器的最后一个元素的迭代器地址
    vector<int>::iterator itEnd = 
    set_intersection(VEC_INT01.begin(), VEC_INT01.end(), VEC_INT02.begin(), VEC_INT02.end(), vTarget.begin());

    for_each(vTarget.begin(), itEnd, MyPrint());
    cout << endl;
    cout << "size of vTarget is " << vTarget.size() << endl;   // size = 10
}




//---------------------------------------------------------------------------
// 2.set_union

void test02()
{
    vector<int> VEC_INT01;
    vector<int> VEC_INT02;
    for (int i = 0; i < 10; i++) {
        VEC_INT01.push_back(i);
        VEC_INT02.push_back(i+5);
    }

    vector<int> vTarget;
    //取两个容器的和给目标容器开辟空间
    vTarget.resize(VEC_INT01.size() + VEC_INT02.size());

    //返回目标容器的最后一个元素的迭代器地址
    vector<int>::iterator itEnd = 
    set_union(VEC_INT01.begin(), VEC_INT01.end(), VEC_INT02.begin(), VEC_INT02.end(), vTarget.begin());

    for_each(vTarget.begin(), itEnd, MyPrint());
    cout << endl; // 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 
    cout << "size of vTarget is " << vTarget.size() << endl;   // size = 20
}






//---------------------------------------------------------------------------
// 3.set_difference

void test03()
{
    vector<int> VEC_INT01;
    vector<int> VEC_INT02;
    for (int i = 0; i < 10; i++) {
        VEC_INT01.push_back(i);
        VEC_INT02.push_back(i+5);
    }

    vector<int> vTarget;
    //取两个里面较大的值给目标容器开辟空间
    vTarget.resize( max(VEC_INT01.size() , VEC_INT02.size()));

    //返回目标容器的最后一个元素的迭代器地址
    cout << "v1与v2的差集为： " << endl;
    vector<int>::iterator itEnd =
    set_difference(VEC_INT01.begin(), VEC_INT01.end(), VEC_INT02.begin(), VEC_INT02.end(), vTarget.begin());
    for_each(vTarget.begin(), itEnd, MyPrint());
    cout << endl;  // 0 1 2 3 4 

    cout << "v2与v1的差集为： " << endl;
    itEnd = set_difference(VEC_INT02.begin(), VEC_INT02.end(), VEC_INT01.begin(), VEC_INT01.end(), vTarget.begin());
    for_each(vTarget.begin(), itEnd, MyPrint());
    cout << endl; // 10 11 12 13 14 

    cout << "size of vTarget is " << vTarget.size() << endl;   // size = 10
}


int main()
{
    test03();
    return 0;
}