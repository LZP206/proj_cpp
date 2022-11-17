#include <iostream>
using namespace std;

class Person {
public:
  Person(){
    mA = 0;
  }

  int mA;   //只有非静态成员变量占对象空间
  static int mB; //静态成员变量不占对象空间

  //函数也不占对象空间，所有函数共享一个函数实例
  void func() {
    cout << "mA:" << this->mA << endl;
  }
  //静态成员函数也不占对象空间
  static void sfunc() {}
};

int main() {

  cout << sizeof(Person) << endl; 
  //空对象占用的内存空间为 1byte , 是为了区分不同空对象占空间的位置

  return 0;
}