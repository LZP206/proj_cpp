// 案例描述
// 分别用普通写法和多态技术，设计实现两个操作数进行运算的计算器类


#include <iostream>
using namespace std;



//----------------------------------------------------------------------
// 普通写法
class Calculator
{
public:
    int getResult(string oper)
    {
        int temp;
        if(oper == "+")
        {
            temp = m_Num1 + m_Num2;
        }
        else if (oper == "-")
        {
            temp = m_Num1 - m_Num2;
        }
        else if (oper == "*")
        {
            temp = m_Num1 * m_Num2;
        }
        // 如果想扩展新的功能，需要修改源码；
        // 在实际开发中提倡开闭原则：即对扩展进行开放，对修改进行关闭

        return temp;
    }
 
    int m_Num1;  //创建两个操作数
    int m_Num2;
};




void test01()
{
    Calculator c;
    c.m_Num1 = 10;
    c.m_Num2 = 10;

    cout << "-------利用普通写法实现计算器-------" << endl;
    cout << c.m_Num1 << "+" << c.m_Num2 << "=" << c.getResult("+") << endl;
    cout << c.m_Num1 << "-" << c.m_Num2 << "=" << c.getResult("-") << endl;
    cout << c.m_Num1 << "*" << c.m_Num2 << "=" << c.getResult("*") << endl;
}



//----------------------------------------------------------------------
// 利用多态实现计算器

// 计算器抽象类（基类）
class AbstractCalculator
{
public:
    virtual int getResult(){ return 0; }

    int m_Num1;   
    int m_Num2;
};



// 加法计算器类
class AddCalculator : public AbstractCalculator
{
public:
    virtual int getResult()
    {
        return m_Num1 + m_Num2; 
    }
};
// 减法计算器类
class SubCalculator : public AbstractCalculator
{
public:
    virtual int getResult()
    {
        return m_Num1 - m_Num2; 
    }
};
// 乘法计算器类
class MulCalculator : public AbstractCalculator
{
public:
    virtual int getResult()
    {
        return m_Num1 * m_Num2; 
    }
};



void test02 ()
{
    cout << "-------利用多态实现计算器-------" << endl;
    // 多态使用条件：父类指针或引用指向是子类对象
    AbstractCalculator *abc = new(AddCalculator); // 实现加法运算
    abc->m_Num1 = 100;
    abc->m_Num2 = 100;
    cout << abc->m_Num1 << "+" << abc->m_Num2 << "=" << abc->getResult() << endl;
    delete abc;  // 手动释放堆区数据


    abc = new(SubCalculator); // 实现减法运算
    cout << abc->m_Num1 << "+" << abc->m_Num2 << "=" << abc->getResult() << endl;
    delete abc;  

    abc = new(MulCalculator); // 实现减法运算
    cout << abc->m_Num1 << "*" << abc->m_Num2 << "=" << abc->getResult() << endl;
    delete abc;  



    cout << "abc->m_Num1 = " << abc->m_Num1 << endl;
    cout << "abc->m_Num2 = " << abc->m_Num2 << endl;
}





int main()
{
    test01();
    test02();

    return 0;
}