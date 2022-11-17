/*
- accumulate(iterator beg, iterator end, value);
    // 计算容器元素累计总和
    // beg 开始迭代器
    // end 结束迭代器
    // value 起始值

- fill(iterator beg, iterator end, value);
    // 向容器中填充元素
    // beg 开始迭代器
    // end 结束迭代器
    // value 填充的值
*/


#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <numeric>



//---------------------------------------------------------------------------
// 1.accumulate

void test01()
{
    vector<int> VEC_INT;
    for (int i = 0; i <= 100; i++) {VEC_INT.push_back(i);}

    int total = accumulate(VEC_INT.begin(), VEC_INT.end(), 0);

    cout << "total = " << total << endl;
}




//---------------------------------------------------------------------------
// 2.fill

class MyPrint
{
    public:
    void operator()(int val){cout << val << " ";}
};

void test02()
{

  vector<int> VEC_INT;
  VEC_INT.resize(10); // 开辟空间
  
  fill(VEC_INT.begin(), VEC_INT.end(), 100); // 填充

  for_each(VEC_INT.begin(), VEC_INT.end(), MyPrint());
  cout << endl;
}






//---------------------------------------------------------------------------
int main()
{
    test02();
    return 0;
}