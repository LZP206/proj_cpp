#include <iostream>
using namespace std;

#include <deque>
#include <algorithm>

template<typename T>
void printDeque(const deque<T> & d)
{
    for( auto it = d.begin(); it != d.end(); it++ )
    {
        cout << *it << " ";
    }
    cout << endl;
}

//void printDeque(const deque<char> & d)
//{
//    for(auto it = d.begin(); it != d.end(); it++)
//    {
//        cout << *it << " ";
//    }
//    cout << endl;
//}


// ----------------------1.deque构造函数----------------------

// 函数原型：

// deque<T> deqT;                   //默认构造形式
// deque(beg, end);                 //构造函数将[beg, end)区间中的元素拷贝给本身。
// deque(n, elem);                  //构造函数将n个elem拷贝给本身。
// deque(const deque &deq);         //拷贝构造函数

void test01()
{
    deque<int> d1; 
    for (int i = 0; i < 10; i++)
    {
        d1.push_back(i);
    }
    printDeque(d1);

    deque<int> d2(d1.begin(),d1.end());
    printDeque(d2);

    deque<int>d3(10,100);
    printDeque(d3);

    deque<int>d4 = d3;
    printDeque(d4);
}






// ----------------------2.deque赋值操作----------------------

// 函数原型：

// deque& operator=(const deque &deq);   //重载等号操作符
// assign(beg, end);                     //将[beg, end)区间中的数据拷贝赋值给本身。
// assign(n, elem);                      //将n个elem拷贝赋值给本身。

void test02()
{
    deque<int> d1;
    for (int i = 0; i < 10; i++)
    {
        d1.push_back(i);
    }
    printDeque(d1);

    deque<int>d2;
    d2 = d1;
    printDeque(d2);

    deque<int>d3;
    d3.assign(d1.begin(), d1.end());
    printDeque(d3);

    deque<int>d4;
    d4.assign(10, 100);
    printDeque(d4);
}





// ----------------------3.deque大小操作----------------------

// 函数原型：

// deque.empty();            //判断容器是否为空
// deque.size();             //返回容器中元素的个数
// deque.resize(num);        //重新指定容器的长度为num,若容器变长，则以默认值填充新位置。
//                           //如果容器变短，则末尾超出容器长度的元素被删除。
// deque.resize(num, elem);  //重新指定容器的长度为num,若容器变长，则以elem值填充新位置。
//                           //如果容器变短，则末尾超出容器长度的元素被删除。

void test03()
{
    deque<int> d1;
    for (int i = 0; i < 10; i++)
    {
        d1.push_back(i);
    }
    printDeque(d1);

    //判断容器是否为空
    if (d1.empty()) 
    {
        cout << "d1为空!" << endl;
    }
    else 
    {
        cout << "d1不为空!" << endl;
        //统计大小
        cout << "d1的大小为：" << d1.size() << endl;
    }

    //重新指定大小
    d1.resize(15, 1);
    printDeque(d1);

    d1.resize(5);
    printDeque(d1);
}




// ----------------------4.deque插入和删除----------------------

// 函数原型：

// 两端插入操作：
// push_back(elem);         //在容器尾部添加一个数据
// push_front(elem);        //在容器头部插入一个数据
// pop_back();              //删除容器最后一个数据
// pop_front();             //删除容器第一个数据

// 指定位置操作：
// insert(pos,elem);        //在pos位置插入一个elem元素的拷贝，返回新数据的位置。
// insert(pos,n,elem);      //在pos位置插入n个elem数据，无返回值。
// insert(pos,beg,end);     //在pos位置插入[beg,end)区间的数据，无返回值。
// clear();                 //清空容器的所有数据
// erase(beg,end);          //删除[beg,end)区间的数据，返回下一个数据的位置。
// erase(pos);              //删除pos位置的数据，返回下一个数据的位置。

void test04()
{
    //------------------两端操作------------------
    deque<int> d1;
    
    d1.push_back(10);   //尾插
    d1.push_back(20);
    d1.push_front(100); //头插
    d1.push_front(200);

    printDeque(d1);     // 输出：200 100 10 20

    d1.pop_back();  //尾删
    d1.pop_front(); //头删

    printDeque(d1);    // 输出：100 10 
    cout << "-------------------" << endl;



    //------------------插入------------------
    deque<int> d2;
    d2.insert(d2.begin(), 1000);
    printDeque(d2);    // 输出：1000

    d2.insert(d2.begin(), 2,10000);
    printDeque(d2);    // 输出：10000 10000 1000

    deque<int>d3;
    d3.push_back(1);
    d3.push_back(2);
    d3.push_back(3);

    d2.insert(d2.begin(), d3.begin(), d3.end());
    printDeque(d2);    // 输出：1 2 3 10000 10000 1000
    cout << "-------------------" << endl;



    //------------------删除------------------
    deque<int> d4;
    d4.push_back(10);
    d4.push_back(20);
    d4.push_front(100);
    d4.push_front(200);
    printDeque(d4);    // 输出：200 100 10 20 

    d4.erase(d4.begin());
    printDeque(d4);    // 输出：100 10 20

    d4.erase(d4.begin(), d4.end());   
    d4.clear();
    printDeque(d4);    // 输出为空
    cout << "-------------------" << endl;
}






// ----------------------5.deque数据存取----------------------

// 函数原型：

// at(int idx);     //返回索引idx所指的数据
// operator[];      //返回索引idx所指的数据
// front();         //返回容器中第一个数据元素
// back();          //返回容器中最后一个数据元素

void test05()
{
    deque<int> d;
    d.push_back(10);
    d.push_back(20);
    d.push_front(100);
    d.push_front(200);

    for (int i = 0; i < d.size(); i++) 
    {
        cout << d[i] << " ";
    }
    cout << endl;


    for (int i = 0; i < d.size(); i++) 
    {
        cout << d.at(i) << " ";
    }
    cout << endl;

    cout << "第一个数据为" << d.front() << endl;
    cout << "最后一个数据为" << d.back() << endl;
}





// ----------------------6.deque数据排序----------------------

// 函数原型：

// sort(iterator beg, iterator end) //对beg和end区间内元素进行排序

void test06()
{
    deque<char> d;
    d.push_back('a');
    d.push_back('b');
    d.push_front('c');
    d.push_front('d');

    for (int i = 0; i < d.size(); i++)
    {
        cout << d.at(i) << " ";
    }
    cout << endl;

    sort(d.begin(), d.end());

    for (int i = 0; i < d.size(); i++)
    {
        cout << d.at(i) << " ";
    }
    cout << endl;



    printDeque(d);

    // sort(d.begin(), d.end());
    // printDeque(d);

}




// ----------------------main函数----------------------
int main()
{
    test06();
    return 0;
}