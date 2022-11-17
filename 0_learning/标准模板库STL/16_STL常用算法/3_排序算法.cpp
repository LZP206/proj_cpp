/*
常用排序算法介绍：
- sort(iterator beg, iterator end, _Pred);
    // 按指定规则排序容器内元素，默认升序
    //  beg    开始迭代器
    //  end    结束迭代器
    //  _Pred  谓词

- random_shuffle(iterator beg, iterator end);
    // 指定范围内的元素随机调整次序
    // beg 开始迭代器
    // end 结束迭代器

- merge(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest);
    // 容器元素合并，并存储到另一容器中
    // 注意: 两个容器必须是**有序的**
    // beg1   容器1开始迭代器
    // end1   容器1结束迭代器
    // beg2   容器2开始迭代器
    // end2   容器2结束迭代器
    // dest    目标容器开始迭代器

- reverse(iterator beg, iterator end);`
    // 反转指定范围的元素
    // beg 开始迭代器
    // end 结束迭代器
*/


#include <iostream>
using namespace std;
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>






//---------------------------------------------------------------------------
// 1.sort

void myPrint_global(int val){cout << val << " ";}

void test01() 
{
    vector<int> VEC_INT;
    VEC_INT.push_back(10);
    VEC_INT.push_back(30);
    VEC_INT.push_back(50);
    VEC_INT.push_back(20);
    VEC_INT.push_back(40);

    //sort默认从小到大排序
    sort(VEC_INT.begin(), VEC_INT.end());
    for_each(VEC_INT.begin(), VEC_INT.end(), myPrint_global);
    cout << endl;

    // 自定义排序方式：从大到小排序
    sort(VEC_INT.begin(), VEC_INT.end(), greater<int>());  // #include <functional.h>
    for_each(VEC_INT.begin(), VEC_INT.end(), myPrint_global);
    cout << endl;
}



//---------------------------------------------------------------------------
// 2.random_shuffle

class MyPrint
{
    public:
    void operator()(int val){cout << val << " ";}
};

void test02()
{
  srand((unsigned int)time(NULL));
  vector<int> VEC_INT;
  for(int i = 0 ; i < 10;i++){VEC_INT.push_back(i);}
  for_each(VEC_INT.begin(), VEC_INT.end(), MyPrint());
  cout << endl;

  //打乱顺序
  random_shuffle(VEC_INT.begin(), VEC_INT.end());
  for_each(VEC_INT.begin(), VEC_INT.end(), MyPrint());
  cout << endl;
}





//---------------------------------------------------------------------------
// 3.merge

void test03()
{
    vector<int> VEC_TEST01;
    vector<int> VEC_TEST02;
    for (int i = 0; i < 10 ; i++){
        VEC_TEST01.push_back(i);
        VEC_TEST02.push_back(i + 1);
    }

    vector<int> VEC_target;
    //目标容器需要提前开辟空间
    VEC_target.resize(VEC_TEST01.size() + VEC_TEST02.size());

    //合并需要两个有序序列
    merge(VEC_TEST01.begin(), VEC_TEST01.end(), VEC_TEST02.begin(), VEC_TEST02.end(), VEC_target.begin());
    for_each(VEC_target.begin(), VEC_target.end(), MyPrint());
    cout << endl;

    //合并 -- 降序
    reverse(VEC_TEST01.begin(),VEC_TEST01.end());
    reverse(VEC_TEST02.begin(),VEC_TEST02.end());
    merge(VEC_TEST01.begin(), VEC_TEST01.end(), VEC_TEST02.begin(), VEC_TEST02.end(), VEC_target.begin(), greater<int>());
    for_each(VEC_target.begin(), VEC_target.end(), MyPrint());
    cout << endl;
}





//---------------------------------------------------------------------------
// 4.reverse

void test04()
{
    vector<int> VEC_INT;
    VEC_INT.push_back(10);
    VEC_INT.push_back(30);
    VEC_INT.push_back(50);
    VEC_INT.push_back(20);
    VEC_INT.push_back(40);

    cout << "反转前： " << endl;
    for_each(VEC_INT.begin(), VEC_INT.end(), MyPrint());
    cout << endl;

    cout << "反转后： " << endl;

    reverse(VEC_INT.begin(), VEC_INT.end());
    for_each(VEC_INT.begin(), VEC_INT.end(),MyPrint());
    cout << endl;
}






//---------------------------------------------------------------------------
int main() 
{
    test02();
    return 0;
}