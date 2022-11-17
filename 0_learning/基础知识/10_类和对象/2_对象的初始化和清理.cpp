#include <iostream>
using namespace std;
// 对象的初始化与清理
// 1、构造函数 进行初始化
class Person{
public:
    int age;

public:
/*
构造函数语法：类名(){}
1. 构造函数，没有返回值也不写void
2. 函数名称与类名相同
3. 构造函数可以有参数，因此可以发生重载
4. 程序在调用对象时候会自动调用构造，无须手动调用,而且只会调用一次
*/
    //无参构造（默认）
    Person() {
        cout << "Person 无参构造函数的调用" << endl;
    }
    //有参构造
    Person(int a) {
        age = a;

        cout << "Person 有参构造函数的调用" << endl;
    }
    //拷贝构造函数
    Person(const Person &p){
        age = p.age;
        cout << "Person 拷贝构造函数的调用" << endl;
    }

/*
析构函数语法：~类名(){}
1. 析构函数，没有返回值也不写void
2. 函数名称与类名相同,在名称前加上符号  ~
3. 析构函数不可以有参数，因此不可以发生重载
4. 程序在对象销毁前会自动调用析构，无须手动调用,而且只会调用一次
*/
    ~Person(){
        cout << "Person 析构函数的调用" << endl;
    }
};




// 1.使用一个已经创建完毕的对象来初始化一个新对象
void test01(){
    Person p1;       //无参（默认）构造函数的调用，栈区上的数据，test01执行完毕后会释放这个对象

    // 括号法
    Person p2(10);
    Person p3(p2);
    cout << "p2的年龄为" << p2.age << endl;
    cout << "p3的年龄为" << p3.age << endl;

    // 显式法
    Person p4 = Person(10);  //Person(10)单独写就是匿名对象  当前行结束之后，马上析构
    Person p5 = Person(p2);

    // 隐式转换法
    Person p6 = 10; // Person p6 = Person(10);
    Person p7 = p4; // Person p7 = Person(p4);

}


// 2.值传递的方式给函数参数传参
void doWork(Person p1){
    // 在进行值传递的时候，形参p1拷贝实参，是一个新的临时变量，相当于Person p1 = p(隐式)
    cout << (int*)&p1 << endl;
}
void test02(){
    Person p;
    cout << (int*)&p << endl;
    doWork(p);
}


// 3.以值方式返回局部对象     
Person doWork2(){
    Person p1;
    cout << (int*)&p1 << endl;
    return p1;
}
void test03(){
    Person p = doWork2();  //相当于Person p = p1(隐式)
    cout << (int*)&p << endl;
}


//调用规则1：如果用户定义有参构造函数，c++不再提供默认无参构造，但是会提供默认拷贝构造
//void test04(){
//    Person p1;
//    //No matching constructor for initialization of 'Person'
//}
void test05(){
    Person p1(18);
    Person p2(p1);   //如果不自己写拷贝构造，编译器会自动添加拷贝构造，并且做浅拷贝操作
    cout << "p2的年龄为： " << p2.age << endl;
}
//调用规则2：如果用户定义拷贝构造函数，c++不会再提供其他构造函数








// 深拷贝与浅拷贝
class Person2
{
public:
    int m_age;
    int *m_height;   //创建身高 为指针变量，利用new存放在堆区
public:
    //无参构造（默认）
    Person2() {
        cout << "Person2 无参构造函数的调用" << endl;
    }
    //有参构造
    Person2(int a, int height) {
        m_age = a;
        m_height = new int;
        *m_height = height;

        cout << "Person2 有参构造函数的调用" << endl;
    }
    //拷贝构造函数
    Person2(const Person2 &p){
        m_age = p.m_age;
        m_height = new int;
        *m_height = *p.m_height;
        cout << "Person2 拷贝构造函数的调用" << endl;
    }
    //析构函数
    ~Person2(){
        //析构函数用途：将堆区的数据释放
        if (m_height != nullptr){
            delete m_height;
            m_height = nullptr;
        }
        cout << "Person2 析构函数的调用" << endl;
    }
};
void test06(){
    Person2 p1(18,160);
    cout << "p1的年龄为： " << p1.m_age << "\tp1的身高为：" << *p1.m_height << endl;
    Person2 p2(p1);
    cout << "p2的年龄为： " << p2.m_age << "\tp2的身高为：" << *p2.m_height << endl;
}







// 类对象作为类成员
class Phone{
public:
    string m_PhoneName;
public:
    Phone(string name): m_PhoneName(name){
        cout << "Phone构造" << endl;
    }
//    Phone(string name){
//        m_PhoneName = name;
//        cout << "Phone构造" << endl;
//    }

    ~Phone(){
        cout << "Phone析构" << endl;
    }
};

class Person3{
public:
    string m_Name;
    Phone m_Phone;
public:
    // 利用初始化列表初始化对象
    Person3(string name, string pName) :m_Name(name), m_Phone(pName){
        cout << "Person3构造" << endl;
    }

    ~Person3(){
        cout << "Person3析构" << endl;
    }

    void playGame() const{
        cout << m_Name << " 使用" << m_Phone.m_PhoneName << " 牌手机! " << endl;
    }
};

void test07(){
    //当类中成员是其他类对象时，我们称该成员为 对象成员
    //构造的顺序是 ：先调用对象成员的构造，再调用本类构造
    //析构顺序与构造相反
    Person3 p("张三" , "苹果X");
    p.playGame();
}








// 静态成员变量
class Person4{
public:
    static int m_A; //静态成员变量
private:
    static int m_B; //静态成员变量也是有访问权限的
};

//类外初始化  注意作用域！！
int Person4::m_A = 10;
int Person4::m_B = 10;

void test08(){
    //静态成员变量 不属于特定的的某个对象 该类所有对象共享同一份数据
    //静态成员变量两种访问方式

    //1、通过对象
    Person4 p1;
    cout << "p1.m_A = " << p1.m_A << endl;

    Person4 p2;
    p2.m_A = 200;
    cout << "p1.m_A = " << p1.m_A << endl; //共享同一份数据
    cout << "p2.m_A = " << p2.m_A << endl;

    //2、通过类名  (类名::成员属性)
    Person4::m_A = 300;
    cout << "m_A = " << Person4::m_A << endl;

    //cout << "m_B = " << Person4::m_B << endl; //私有权限访问不到
}







//静态成员函数
class Person5{
public:
    static void func(){
        cout << "static void func调用" << endl;
        m_A = 100;
        //m_B = 100; //错误，不可以访问非静态成员变量，无法区分是哪个对象的m_B属性
    }

    static int m_A; //静态成员变量
    int m_B;

private:
    //静态成员函数也是有访问权限的
    static void func2(){
        cout << "static void func2调用" << endl;
    }
};

//类外初始化
int Person5::m_A = 10;


void test09(){
    //静态成员变量两种访问方式

    //1、通过对象
    Person5 p1;
    p1.func();

    //2、通过类名
    Person5::func();

    //Person5::func2(); //私有权限访问不到
}






int main(){
//    test01();  // 对象的构造函数、析构函数都会被调用
//    Person p;  // 对象的构造函数会被调用，析构函数不会
    test09();
    
    return 0;
}