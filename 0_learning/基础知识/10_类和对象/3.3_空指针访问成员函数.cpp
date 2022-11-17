#include <iostream>
using namespace std;


class Person {
public:

  void ShowClassName(){
    cout << "this is a Person class" << endl;
  }

  void ShowPersonAge(){

    if (this == NULL) {return;}
    //如果用到this指针，需要加以判断保证代码的健壮性

    cout << "PersonAge = " << this->mAge << endl;
  }

public:
  int mAge;
};

void test01(){
  Person * p = NULL;
  p->ShowClassName(); //空指针，可以调用成员函数
  //p->ShowPerson();  //但如果成员函数中用到this指针，就不可以了
}

int main() {
  test01();
 
  return 0;
}
