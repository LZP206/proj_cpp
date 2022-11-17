#include <iostream>
using namespace std;



class Animal
{
public:
    // 虚函数
    virtual void speak()
    {
        cout << "动物在说话" << endl;
    }
};


class Cat : public Animal
{
public:
    void speak()
    {
        cout << "小猫在说话" << endl;
    }
};

class Dog : public Animal
{
    void speak()
    {
        cout << "小狗在说话" << endl;
    }
};



// 函数地址早绑定，在编译阶段就已经确定函数地址
// 如果想执行让猫说话，那么这个函数地址就不能提前绑定，需要在运行阶段进行绑定，即地址晚绑定
void doSpeak(Animal &animal)   // 多态的使用：父类指针或引用指向子类对象
{
    animal.speak();
}

void test01()
{
    Cat cat;
    doSpeak(cat); //c++会实现父子类自动转换

    Dog dog;
    doSpeak(dog);

    Animal animal;
    doSpeak(animal);
}

void test02()
{
    cout << "sizeof(Animal) = " << sizeof(Animal) <<endl;  
    // 不加virtual结果为1 —— 表示空对象
    // 加virtual结果为4(32位)、8(64位) ）—— 虚函数（表 ）指针

}




int main()
{
    //test01();
    test02();

    return 0;
}