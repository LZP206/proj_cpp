#include <iostream>
using namespace std;


class Person
{
public:

  Person(int age)
  {
    //用途1:当形参和成员变量同名时，可用this指针来区分
    this->age = age;
    //this指针指向被调用的成员函数所属的对象（这里p1在调用构造函数，this就指向p1）
  }

  Person& PersonAddPerson(Person p)
  {
    this->age += p.age;
    //用途2：返回对象本身（用引用接收，如果不用引用而是以值得方式返回，则会赋值给新的变量）
    return *this;
  }

  int age;
};

void test01()
{
  Person p1(10);
  cout << "p1.age = " << p1.age << endl;

  Person p2(20);
  //链式编程思想 20+10+10+10
  p2.PersonAddPerson(p1).PersonAddPerson(p1).PersonAddPerson(p1);
  cout << "p2.age = " << p2.age << endl;
}

int main() {

  test01();

  return 0;
}
