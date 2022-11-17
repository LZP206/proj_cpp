#include <iostream>
using namespace std;

class Person {
public:
  Person(){
    m_A = 0;
    m_B = 0;
  }

  //this指针的本质是一个指针常量，指针的指向不可修改
  //如果想让指针指向的值也不可以修改，需要声明常函数
  void ShowPerson() const {
    //this = NULL; //不能修改指针的指向 Person* const this;
    //this->mA = 100; //但是this指针指向的对象的数据是可以修改的

    //const修饰成员函数，表示指针指向的内存空间的数据不能修改，除了mutable修饰的变量
    this->m_B = 100;
  }

  void MyFunc(){
    this->m_A = 100;
  }

public:
  int m_A;
  mutable int m_B; //特殊变量，在常函数（或常对象）中也可修改
};


//const修饰对象  常对象
void test01() {
  const Person p; //创建常对象
  cout << p.m_A << endl;
  //p.m_A = 100; //常对象不能修改成员变量的值,但是可以访问
  
  p.m_B = 100; //但是常对象可以修改mutable修饰成员变量

  //常对象只能访问常函数
  p.ShowPerson();

  //p.MyFunc(); //常对象不能调用普通成员函数，因为普通成员可以修改成员属性，而常对象不能修改，矛盾

}

int main() {

  test01();

  return 0;
}