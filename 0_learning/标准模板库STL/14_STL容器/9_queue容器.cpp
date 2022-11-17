#include <iostream>
using namespace std;

#include <queue>

/*
常用接口：

构造函数：
queue<T> que;                       /queue采用模板类实现，queue对象的默认构造形式
queue(const queue &que);            //拷贝构造函数

赋值操作：
queue& operator=(const queue &que);           //重载等号操作符

数据存取：
push(elem);        //往队尾添加元素
pop();             //从队头移除第一个元素
back();            //返回最后一个元素
front();           //返回第一个元素

大小操作：
empty();           //判断堆栈是否为空
size();            //返回栈的大小
*/

class Person
{
public:
    Person(string name, int age)
    {
        this->m_Name = name;
        this->m_Age = age;
    }

    string m_Name;
    int m_Age;
};




void test01()
{
    queue<Person> q;

    Person p1("唐僧", 30);
    Person p2("孙悟空", 1000);
    Person p3("猪八戒", 900);
    Person p4("沙僧", 800);

    q.push(p1);
    q.push(p2);
    q.push(p3);
    q.push(p4);
    cout << "队列大小为：" << q.size() << endl;

    while (!q.empty())
    {
        cout << "队头：" << "姓名-" << q.front().m_Name << "\t年龄-" << q.front().m_Age << endl;
        cout << "队尾：" << "姓名-" << q.back().m_Name << "\t年龄-" << q.back().m_Age << endl;

        q.pop();
        cout << endl;
    }
    cout << "队列大小为：" << q.size() << endl;
}







int main()
{
    test01();
    return 0;
}