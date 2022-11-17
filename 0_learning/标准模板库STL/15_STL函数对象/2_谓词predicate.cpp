/* 
概念：
- 返回**bool类型**的仿函数称为**谓词**
- 如果operator()接受一个参数，那么叫做一元谓词
- 如果operator()接受两个参数，那么叫做二元谓词

补充：`find_if(起始迭代器, 结束迭代器, 谓词)`

- find_if() 同 find() 一样，为在输入迭代器所定义的范围内查找单个对象的算法，它可以在前两个参数指定的范围内查找可以使第三个参数指定的谓词返回 true 的第一个对象。谓词不能修改传给它的对象。
- find_if() 会返回一个指向被找到对象的迭代器，如果没有找到对象，会返回这个序列的结束迭代器。
*/



#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>



//---------------------------------------------------------------------------
// 1.一元谓词
class is_Greater_than_Five
{
    public:
    bool operator()(int val_input)
    {
        return val_input > 5;
    }
};

void test01()
{
    vector<int> V_TEST;
    for (int i = 0; i < 10; i++) {V_TEST.push_back(i);}
    vector<int>::iterator it = find_if(V_TEST.begin(),V_TEST.end(),is_Greater_than_Five());
    if (it == V_TEST.end())
    {
        cout << "element not found" << endl;
    }
    else
    {
        cout << "elment found: " << *it << endl;
    }
}




//---------------------------------------------------------------------------
// 2.二元谓词
class MyCopare_ofTWO_intVal
{
    public:
    bool operator()(int val_input1, int val_input2)
    {
        return val_input1 > val_input2;
    }
};

void test02()
{
    vector<int> V_TEST;
    for (int i = 10; i <= 50; i = i + 10) {V_TEST.push_back(i);}

    // 默认从小到大
    sort(V_TEST.begin(),V_TEST.end());
    for (vector<int>::iterator it = V_TEST.begin(); it != V_TEST.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
     
    cout << "------------------------------" << endl;

    // 使用函数对象改变算法策略，排序从大到小
    sort(V_TEST.begin(),V_TEST.end(),MyCopare_ofTWO_intVal());
    for (vector<int>::iterator it = V_TEST.begin(); it != V_TEST.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}





//---------------------------------------------------------------------------
int main()
{
    test02();

    return 0;
}