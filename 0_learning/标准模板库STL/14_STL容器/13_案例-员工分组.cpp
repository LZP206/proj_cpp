#include <iostream>
using namespace std;
#include <string>
#include <map>
#include <vector>
#include <ctime>
#define CEHUA 0
#define MEISHU 1
#define YANFA 2

/*
- 公司今天招聘了10个员工（ABCDEFGHIJ），10名员工进入公司之后，需要指派员工在那个部门工作
- 员工信息有: 姓名  工资组成；部门分为：策划、美术、研发
- 随机给10名员工分配部门和工资
- 通过multimap进行信息的插入  key(部门编号) value(员工)
- 分部门显示员工信息
*/



// ----------------------------------------------------------------
class Worker2
{
    public:
    string m_Name;
    int m_Salary;
};
// ----------------------------------------------------------------



// 1.创建员工
void createWorker(vector<Worker2> & v_input)
{
    string nameseed = "ABCDEFGHIJ";
    for (int i = 0; i < nameseed.size(); i++)
    {
        Worker2 worker_temp;
        worker_temp.m_Name = "员工";
        worker_temp.m_Name += nameseed[i];
        worker_temp.m_Salary = 10000 + rand()%10000;  // 10000~19999
        v_input.push_back(worker_temp);
    }
}



// 2.员工分组
void setGroup(vector<Worker2> & v_input, multimap<int,Worker2> & m_input)
{
    for (vector<Worker2>::iterator it = v_input.begin(); it != v_input.end(); it++)
    {
        int dept_ID = rand()%3;
        m_input.insert(make_pair(dept_ID, *it));
    }
}



// 3.分组显示员工
void showWorkerByGroup(multimap<int,Worker2> & m_input)
{
    cout << "策划部门：" << endl;
    multimap<int,Worker2>::iterator pos = m_input.find(CEHUA);
    // 在multimap中，同一个键关联的元素必然相邻存放。基于这个事实，就可以将某个键对应的值一一输出
    // 使用find和count函数。count函数求出某个键出现的次数，find函数返回一个迭代器，指向第一个拥有正在查找的键的实例。

    int count = m_input.count(CEHUA); 
    int index = 0;
    for (; pos != m_input.end() && index < count; pos++ , index++)
    {
        cout << "姓名：" << pos->second.m_Name << "\t工资： " << pos->second.m_Salary << endl;
    }

    cout << "----------------------" << endl;

    cout << "美术部门： " << endl;
    pos = m_input.find(MEISHU);
    count = m_input.count(MEISHU); 
    index = 0;
    for (; pos != m_input.end() && index < count; pos++, index++)
    {
        cout << "姓名：" << pos->second.m_Name << "\t工资： " << pos->second.m_Salary << endl;
    }

    cout << "----------------------" << endl;

    cout << "研发部门： " << endl;
    pos = m_input.find(YANFA);
    count = m_input.count(YANFA); 
    index = 0;
    for (; pos != m_input.end() && index < count; pos++, index++)
    {
        cout << "姓名：" << pos->second.m_Name << "\t工资： " << pos->second.m_Salary << endl;
    }
}




// ----------------------------------------------------------------
int main()
{
    srand((unsigned int)time(NULL));
    vector<Worker2> v_worker;
    createWorker(v_worker);

    multimap<int,Worker2> m_worker;
    setGroup(v_worker,m_worker);

    showWorkerByGroup(m_worker);

    return 0;
}