#include <iostream>
using namespace std;


// 子类创建在堆区new:需要手动delete
// 1.如果基类含虚函数（不是纯虚函数），  用delete没有 warning，但会跳过子类的析构函数调用 （如果子类没有在堆区开辟空间则不会有影响）
// 2.如果基类含纯虚函数，这基类为抽象类，用delete会有 warning，delete后面的代码无法实现(mac-clang++下)  ------> 抽象类必须虚析构
// （warning: delete called on 'Animal' that is abstract but has non-virtual destructor）

// win-g++下，基类是否为抽象类不想影响， 都是第一种情况


class Animal
{
    public:
    Animal(){cout << "Animal构造函数调用" << endl;}

    // 虚析构可以解决父类指针释放子类对象不干净的问题
    ~Animal() {cout << "Animal虚析构函数调用" << endl;}

    // virtual ~Animal() = 0; // 函数声明：纯虚析构  

    virtual void speak() {cout << "Animal-speak" << endl;} // 基类含有虚函数
    // virtual void speak() = 0; // 基类含有纯虚函数
};
// Animal::~Animal()  // 纯虚析构需要类内写声明类外写实现
// {
//     cout << "Animal纯虚析构函数调用" << endl;
// }




// 子类含有堆区数据
class Cat : public Animal
{
    public:
    Cat(string name)
    {
        cout << "Cat构造函数调用" << endl;
        m_Name = new string (name);
    }
    ~Cat()
    {
        if (m_Name != NULL)
        {
            cout << "Cat析构函数调用" << endl;
            delete m_Name;
            m_Name = NULL;
        }
    }

    virtual void speak()
    {
        cout << *m_Name << "小猫在说话" << endl;
    }

    string * m_Name;
};




// 子类不含堆区数据
// class Cat : public Animal
// {
//     public:
//     Cat(string name)
//     {
//         cout << "Cat构造函数调用" << endl;
//         m_Name = name;
//     }
//     ~Cat(){cout << "Cat析构函数调用" << endl;}

//     virtual void speak()
//     {
//         cout << m_Name << "小猫在说话" << endl;
//     }

//     string  m_Name;
// };







// 子类创建在堆区new:需要手动delete
void test01()
{
    Animal * animal  = new Cat("Tom");
    animal->speak();
    cout << "test01函数调用" << endl;
    delete animal;
}


// 子类没有创建在堆区:不用delete，基类和派生类的构造和析构函数都会被都调用
void test02()
{
    Cat cat("Tom");
    Animal * animal1 = &cat;
    animal1->speak();
    cout << "test02函数调用" << endl;
}



int main()
{
    test02();
    cout << "main函数调用" << endl;
    return 0;
}