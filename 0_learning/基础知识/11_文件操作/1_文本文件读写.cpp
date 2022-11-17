#include <iostream>
using namespace std;

#include <fstream>  // 步骤一：包含文件读写头文件


//--------------------写文件----------------------
void test01()
{
    ofstream ofs;                   // 步骤二：创建输出文件流对象
    ofs.open("test.txt", ios::out); // 步骤三：打开文件，文件路径+打开方式
    ofs << "姓名：张三" << endl;      // 步骤四：写入数据
    ofs << "性别：男" << endl;
    ofs << "年龄：18" << endl;
    ofs.close();                    // 步骤五：关闭文件
}

//--------------------读文件----------------------
void test02()
{
    ifstream ifs;                   // 步骤二：创建导入文件流对象
    ifs.open("test.txt", ios::in);  // 步骤三：打开文件，文件路径+打开方式
    // 读取文件前需要判断文件是否打开
    if (!ifs.is_open())
    {
        cout << "文件打开失败" << endl;
        return;
    }

    // 步骤四：读取数据
                      
    // char buf[1024];
    // while (ifs >> buf)                    // 方式1：这种方式每次读取到空格或换行，直到没有数据可读
    // {
    //     cout << buf << endl;
    // }

    // char buf[1024];
    // int num = 0;
    // while (ifs.getline(buf, sizeof(buf))) // 方式2：文件数据按行读取，每次读取sizeof(buf)个字符
    // {
    //     cout << "第" << ++num << "行：" << buf << endl;
    // }

    // string buf;
    // int num = 0;
    // while (getline(ifs, buf))             // 方式3：效果与原理和方式2都相似，这里用全局函数getline(导入文件流,字符串-接收行数据)
    // {
    //     cout << "第" << ++num << "行：" << buf << endl;
    // }

    char c;
    cout << sizeof(char) << endl;
    int num = 0;
    while ((c = ifs.get()) != EOF)  // end of file  方式4：get()按字符读取，效率低，不推荐使用
    {
        cout << ++num << c;
    }
    cout << "共有" << num << "个字符" << endl;
    
    //  空格、数字、换行符占1个字符     UTF-8：汉字和中文标点占三个字符; GBK：汉字和中文标点占两个字符;



    ifs.close();                     // 步骤五：关闭文件
}





int main ()
{
    test01();
    return 0;
}
