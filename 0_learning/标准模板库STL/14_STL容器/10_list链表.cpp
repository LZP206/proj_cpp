#include <iostream>
using namespace std;

#include <list>
#include <algorithm>



template<typename T>
void printList(const list<T>& _list_input) 
{
	for (auto it = _list_input.begin(); it != _list_input.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}



// --------------------------- 1.list构造函数 ---------------------------
// 函数原型：

// list<T> lst;                       //list采用采用模板类实现,对象的默认构造形式：
// list(beg,end);                     //构造函数将[beg, end)区间中的元素拷贝给本身。
// list(n,elem);                      //构造函数将n个elem拷贝给本身。
// list(const list &lst);             //拷贝构造函数。

void test01()
{
	list<int> L1;
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);
	printList(L1);

	list<int> L2(L1.begin(),L1.end());
	printList(L2);

	list<int> L3(L2);
	printList(L3);

	list<int> L4(10, 1000);
	printList(L4);
}


// --------------------------- 2.list赋值和交换 ---------------------------
// 函数原型：

// assign(beg, end);                   //将[beg, end)区间中的数据拷贝赋值给本身。
// assign(n, elem);                    //将n个elem拷贝赋值给本身。
// list& operator=(const list &lst);   //重载等号操作符
// swap(lst);                          //将lst与本身的元素互换。

void test02()
{
    list<int>L1;
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);
	printList(L1);

	// 赋值--三种方式
	list<int>L2;
	L2 = L1;
	printList(L2);

	list<int>L3;
	L3.assign(L2.begin(), L2.end());
	printList(L3);

	list<int>L4;
	L4.assign(10, 100);
	printList(L4);

    cout << "---------------------" << endl;

    cout << "交换前： " << endl;
	printList(L1);
	printList(L4);

    L1.swap(L4);
    cout << "交换后： " << endl;
	printList(L1);
	printList(L4);
}




// --------------------------- 3.list大小操作 ---------------------------
// 函数原型：

// size();          		//返回容器中元素的个数
// empty();        		    //判断容器是否为空
// resize(num);     		//重新指定容器的长度为num，若容器变长，则以默认值(0)填充新位置。
//   				 		//如果容器变短，则末尾超出容器长度的元素被删除。
// resize(num, elem);       //重新指定容器的长度为num，若容器变长，则以elem值填充新位置。
//    						//如果容器变短，则末尾超出容器长度的元素被删除。

void test03()
{
	list<int>L1;
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);

	if (L1.empty())
	{
		cout << "L1为空" << endl;
	}
	else
	{
		cout << "L1不为空" << endl;
		cout << "L1的大小为： " << L1.size() << endl;
	}

	//重新指定大小
	L1.resize(10);
	printList(L1);

	L1.resize(2);
	printList(L1);

	L1.resize(10, 30);
	printList(L1);
}




// --------------------------- 4.list插入和删除 ---------------------------
// 函数原型：

// push_back(elem);        //在容器尾部加入一个元素
// pop_back();             //删除容器中最后一个元素
// push_front(elem);       //在容器开头插入一个元素
// pop_front();            //从容器开头移除第一个元素
// insert(pos,elem);       //在pos位置插elem元素的拷贝，返回新数据的位置。
// insert(pos,n,elem);     //在pos位置插入n个elem数据，无返回值。
// insert(pos,beg,end);    //在pos位置插入[beg,end)区间的数据，无返回值。
// clear();                //移除容器的所有数据
// erase(beg,end);         //删除[beg,end)区间的数据，返回下一个数据的位置。
// erase(pos);             //删除pos位置的数据，返回下一个数据的位置。
// remove(elem);           //删除容器中所有与elem值匹配的元素。

void test04()
{
	list<int> L;
	//尾插
	L.push_back(10);
	L.push_back(20);
	L.push_back(30);
	//头插
	L.push_front(100);
	L.push_front(200);
	L.push_front(300);

	printList(L);

	//尾删
	L.pop_back();
	printList(L);

	//头删
	L.pop_front();
	printList(L);

	//插入
	list<int>::iterator it = L.begin();
	L.insert(++it, 1000);
	printList(L);

	//删除
	it = L.begin();
	L.erase(++it);
	printList(L);

	//移除
	L.push_back(10000);
	L.push_back(10000);
	L.push_back(10000);
	printList(L);
	L.remove(10000);
	printList(L);
    
    //清空
	L.clear();
	printList(L);
}








// --------------------------- 5.list数据存取 ---------------------------
// 函数原型：

// front();       //返回第一个元素。
// back();        //返回最后一个元素。

void test05()
{
	list<int> L1_temp;
	L1_temp.push_back(10);
	L1_temp.push_back(20);
	L1_temp.push_back(30);
	L1_temp.push_back(40);
	L1_temp.push_back(50);
	L1_temp.push_back(60);
	printList(L1_temp);

	list<int>::iterator it = L1_temp.begin();
	int count = 2;
	for (int i_temp = 1; i_temp < count; i_temp++) { it++;}
	cout << *it << endl;

	cout << L1_temp.front() << " -> " << L1_temp.back() << endl;
}





// --------------------------- 6.list反转和排序 ---------------------------
// 函数原型：

// reverse();     //反转链表
// sort();        //链表排序


bool compare(int val_1, int val_2)
{
	return val_1 > val_2;
}



void test06()
{
	list<int> L1_temp;
	L1_temp.push_back(5);
	L1_temp.push_back(2);
	L1_temp.push_back(3);
	L1_temp.push_back(6);
	L1_temp.push_back(1);
	L1_temp.push_back(4);
	printList(L1_temp);

	L1_temp.reverse();
	printList(L1_temp);

	L1_temp.sort();
	printList(L1_temp);

	L1_temp.sort(compare);
	printList(L1_temp);

}





// --------------------------- 7.list排序案例 ---------------------------
// 排序规则：按照年龄进行升序，如果年龄相同按照身高进行降序

class Person {
public:
	Person(string name, int age , int height) {
		m_Name = name;
		m_Age = age;
		m_Height = height;
	}

public:
	string m_Name;  
	int m_Age;      
	int m_Height;   
};


bool ComparePerson(Person& p1, Person& p2) 
{
	if (p1.m_Age == p2.m_Age) 
	{
		return p1.m_Height > p2.m_Height;
	}
	return  p1.m_Age < p2.m_Age;
}


void test07() 
{
	list<Person> L;
	Person p1("刘备", 35 , 175);
	Person p2("曹操", 45 , 180);
	Person p3("孙权", 40 , 170);
	Person p4("赵云", 25 , 190);
	Person p5("张飞", 35 , 160);
	Person p6("关羽", 35 , 200);
	L.push_back(p1);
	L.push_back(p2);
	L.push_back(p3);
	L.push_back(p4);
	L.push_back(p5);
	L.push_back(p6);


	for (list<Person>::iterator it = L.begin(); it != L.end(); it++) {
		cout << "姓名： " << it->m_Name << " 年龄： " << it->m_Age 
              << " 身高： " << it->m_Height << endl;
	}

	cout << "---------------------------------" << endl;
	L.sort(ComparePerson); //排序

	for (list<Person>::iterator it = L.begin(); it != L.end(); it++) {
		cout << "姓名： " << it->m_Name << " 年龄： " << it->m_Age 
              << " 身高： " << it->m_Height << endl;
	}
}







// --------------------------- 8.list_sort补充 ---------------------------
template <typename T>
void MyprintList(const T it) 
{
	cout << it << endl;
}

// 1.仿函数
class MYsort
{
public:
    bool operator()(int a, int b)
    {
        return a < b;
    }
};

// 2.返回值是bool_谓词
bool mysort(int a, int b)
{
    return a < b;
}

void test08()
{
	list<int> l1;
    l1.push_front(16);
    l1.push_front(28);
    l1.push_front(24);
    l1.push_front(54);
    l1.push_back(35);
    l1.push_back(30);
    l1.push_back(21);
    l1.push_back(39);

    for_each(l1.begin(), l1.end(), MyprintList<int> );
    putchar('\n');


    // l1.sort(mysort);    // 两种方式都可行
    l1.sort(MYsort());
    for_each(l1.begin(), l1.end(), MyprintList<int> );
    putchar('\n');
}











int main()
{
    test08();

    return 0;
}