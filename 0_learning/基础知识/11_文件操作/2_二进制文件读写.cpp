#include <iostream>
using namespace std;
#include <fstream>  // 步骤一：包含文件读写头文件

class Person
{
public:
    char m_Name[64];
    int m_Age;
};



//--------------------写文件----------------------
void test01()
{
    ofstream ofs("person.txt", ios::out | ios::binary);  //可以直接用构造函数指定文件路径和打开方式
    // ofs.open("person.txt", ios::out | ios::binary);

    Person p = {"张三", 18};  // 利用结构体的赋值方式初始化
    ofs.write( (const char *)&p , sizeof(Person));   // write(写入的数据,数据长度)函数写入数据：写入数据为const char *类型    +   写入数据长度（字节）
    ofs.close();
}




//--------------------读文件----------------------
void test02()
{
    ifstream ifs("person.txt", ios::in | ios::binary);
    if (!ifs.is_open())
    {
        cout << "文件打开失败" << endl;
        return;
    }

    Person p;
    ifs.read( (char *)&p , sizeof(p));        // read(用于接收读取数据的变量,数据长度)函数读取数据：读取接收的变量为const char *类型    +   读取数据长度（字节）
    
    cout << "姓名：" << p.m_Name << endl;
    cout << "年龄：" << p.m_Age << endl;

    ifs.close();
}





int main()
{
    test02();
    return 0;
}