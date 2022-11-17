/*
常用遍历算法：

- for_each(iterator beg, iterator end, _func);  
    - beg 开始迭代器
    - end 结束迭代器
    - _func 函数或者函数对象

- transform()(iterator beg1, iterator end1, iterator beg2, _func);
    - beg1 源容器开始迭代器
    - end1 源容器结束迭代器
    - beg2 目标容器开始迭代器
    -_func 函数或者函数对象

*/




#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>



//---------------------------------------------------------------------------
// 1.for_each
void Print01(int VAL_INPUT){cout << VAL_INPUT << " ";}
class Print02
{
    public:
    void operator()(int VAL_INPUT){cout << VAL_INPUT << " ";}
};

void test01()
{
    vector<int> VEC_TEST;
    for (int i = 0; i < 10; i++){VEC_TEST.push_back(i);}
    for_each(VEC_TEST.begin(),VEC_TEST.end(),Print01);
    cout << endl;
    for_each(VEC_TEST.begin(),VEC_TEST.end(),Print02());
}





//---------------------------------------------------------------------------
// 2.transform
class Trans01
{
    public:
    int operator()(int VAL_INPUT){return VAL_INPUT;}
};
class Trans02
{
    public:
    bool operator()(int VAL_INPUT1,int VAL_INPUT2){return VAL_INPUT1 == VAL_INPUT2;}
};

void test02()
{
    vector<int> VEC_SOURCE;
    vector<int> VEC_TAGET;
    for (int i = 0; i < 10; i++){VEC_SOURCE.push_back(i);}
    VEC_TAGET.resize(VEC_SOURCE.size());   // 目标容器需要提前开辟空间!!!
    
    // 一元转换
    transform(VEC_SOURCE.begin(),VEC_SOURCE.end(),VEC_TAGET.begin(),Trans01());
    for_each(VEC_TAGET.begin(),VEC_TAGET.end(),Print02());
    cout << "\n" << "----------------------------------" << endl;

    // 二元转换
    vector<bool> VEC_TAGET_OUT(VEC_SOURCE.size());
    transform(VEC_SOURCE.begin(),VEC_SOURCE.end(),VEC_TAGET.begin(),VEC_TAGET_OUT.begin(),Trans02());
    for_each(VEC_TAGET_OUT.begin(),VEC_TAGET_OUT.end(),Print02());
}





//---------------------------------------------------------------------------
int main()
{
    test02();

    return 0;
}