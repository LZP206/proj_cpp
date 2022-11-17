#include <iostream> 
using namespace std;



template<class T1, class T2> class Person;

template<class T1, class T2> void printPerson2(Person<T1, T2> & p);

template<class T1, class T2>
class Person
{
	// 全局函数配合友元-------类内实现
	friend void printPerson(Person<T1, T2> & p)
	{
		cout << "类内实现 ---- 姓名： " << p.m_Name << " 年龄：" << p.m_Age << endl;
	}


	// 全局函数配合友元-------类外实现
	friend void printPerson2<T1, T2>(Person<T1, T2> & p);

public:

	Person(T1 name, T2 age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}

private:
	T1 m_Name;
	T2 m_Age;
};


template<class T1, class T2>
void printPerson2(Person<T1, T2> & p)
{
	cout << "类外实现 ---- 姓名： " << p.m_Name << " 年龄：" << p.m_Age << endl;
}




void test01()
{
    Person<string,int> p("Leon", 22);
    printPerson2<>(p);
}



int main()
{
    test01();

    return 0;
}