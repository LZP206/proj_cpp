#include <iostream>
using namespace std;

template<typename T1, typename T2>
class Person
{
public:
    Person(T1 name, T2 age);
    void showPersonInfo();

    T1 m_Name;
    T2 m_Age;
};

template<typename T1, typename T2>
Person<T1,T2>::Person(T1 name, T2 age)
{
    this->m_Name = name;
    this->m_Age = age;
}

template<typename t1, typename t2>
void Person<t1, t2>::showPersonInfo()
{
    cout << "Name is " << this->m_Name << "\t"
         << "Age is " << this->m_Age << endl;
}




void test01()
{
    Person<string, int> p("Leon", 20);
    p.showPersonInfo();
}






int main()
{
    test01();
    system("pause");
    return 0;
}