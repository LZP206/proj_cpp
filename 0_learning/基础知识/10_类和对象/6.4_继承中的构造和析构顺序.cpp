#include <iostream>
using namespace std;

class Base
{
public:
    int m_A;

protected:
    int m_B;

private:
    int m_C;

public:

    Base()
    {
        cout << "Base构造函数" <<endl;
    }
    ~Base()
    {
        cout << "Base析构函数" <<endl;
    }

    void writem_C(int c)
    {
        m_C = c;
    }
    int readm_C()
    {
        return m_C;
    }
    void writem_B(int d)
    {
        m_B = d;
    }
    int readm_B()
    {
        return m_B;
    }
};



class Son : public Base
{
public:
    int m_D;

    Son()
    {
        cout << "Son构造函数" <<endl;
    }
    ~Son()
    {
        cout << "Son析构函数" <<endl;
    }

    void func()
    {
        m_A = 10;
        m_B = 10;     //protected直接可以访问
        m_D = 10;
        //m_C = 10; //访问不到报错
        this->writem_C(10); //通过public成员函数访问
    }
};

void test01()
{
    Son s;
    // 输出：
    // Base构造函数
    // Son构造函数
    // Son析构函数
    // Base析构函数
    
}


 


int main()
{
    test01();

    return 0;
}