#include <iostream>
using namespace std;
#include <string>
#define MAX 1000


//联系人结构体
struct Person
{
    string Name;
    int Sex; //男1  女0
    int Age;
    string Phone;
    string Addr;
};
//通讯录结构体
struct addressBooks
{
    Person personArray[MAX];
    int Size;
};


//菜单界面
void showMenu()
{
    cout << "***************************" << endl;
    cout << "*****  1、添加联系人  *****" << endl;
    cout << "*****  2、显示联系人  *****" << endl;
    cout << "*****  3、删除联系人  *****" << endl;
    cout << "*****  4、查找联系人  *****" << endl;
    cout << "*****  5、修改联系人  *****" << endl;
    cout << "*****  6、清空联系人  *****" << endl;
    cout << "*****  0、退出通讯录  *****" << endl;
    cout << "***************************" << endl;
}


//1、添加联系人信息
void addPerson(addressBooks* abs)
{
    if (abs->Size == MAX)
    {
        cout << "通讯录已满，无法添加" << endl;
    }
    else
    {
        //姓名
        string name;
        cout << "请输入姓名：" << endl;
        cin >> name;
        abs->personArray[abs->Size].Name = name;

        //性别
        cout << "请输入性别：" << endl;
        cout << "1 -- 男" << endl;
        cout << "0 -- 女" << endl;
        int sex;
        while (true)
        {
            cin >> sex;
            if (sex == 1 || sex == 0)
            {
                abs->personArray[abs->Size].Sex = sex;
                break;
            }
            cout << "输入有误，请重新输入";
        }

        //年龄
        cout << "请输入年龄：" << endl;
        int age = 0;
        cin >> age;
        abs->personArray[abs->Size].Age = age;

        //联系电话
        cout << "请输入联系电话：" << endl;
        string phone;
        cin >> phone;
        abs->personArray[abs->Size].Phone = phone;

        //家庭住址
        cout << "请输入家庭住址：" << endl;
        string address;
        cin >> address;
        abs->personArray[abs->Size].Addr = address;

        //更新通讯录人数
        abs->Size++;
        cout << "添加成功" << endl;
    }

    cout << "按任意键后回车继续...";
    cin.ignore(1024, '\n'); cin.get();
    system("clear");
}


//2、显示所有联系人信息
void showPerson(addressBooks* abs)
{
    if (abs->Size == 0)
    {
        cout << "当前记录为空" << endl;
    }
    else
    {
        for (int i = 0; i < abs->Size; i++)
        {
            cout << "姓名：" << abs->personArray[i].Name << "\t";
            cout << "性别：" << (abs->personArray[i].Sex == 1 ? "男" : "女") << "\t";
            cout << "年龄：" << abs->personArray[i].Age << "\t";
            cout << "电话：" << abs->personArray[i].Phone << "\t";
            cout << "住址：" << abs->personArray[i].Addr << endl;
        }
    }

    cout << "按任意键后回车继续...";
    cin.ignore(1024, '\n'); cin.get();
    system("clear");
}


// 按姓名判断联系人是否存在
int ifExist(addressBooks* abs, const string& name)
{
    for (int i = 0; i < abs->Size; i++)
    {
        if (abs->personArray[i].Name == name)
        {
            return i;
        }
    }
    return -1;
}


//3、删除指定联系人函数
void deletePerson(addressBooks* abs)
{
    cout << "请输入您要删除的联系人" << endl;
    string name;
    cin >> name;

    int ret = ifExist(abs, name);
    if (ret != -1)
    {
        for (int i = ret; i < abs->Size; i++)
        {
            abs->personArray[i] = abs->personArray[i + 1];
        }
        abs->Size--;
        cout << "删除成功" << endl;
    }
    else
    {
        cout << "查无此人" << endl;
    }

    cout << "按任意键后回车继续...";
    cin.ignore(1024, '\n'); cin.get();
    system("clear");
}


//4、查找指定联系人函数
void findPerson(addressBooks* abs)
{
    cout << "请输入您要查找的联系人" << endl;
    string name;
    cin >> name;

    int ret = ifExist(abs, name);
    if (ret != -1)
    {
        cout << "姓名：" << abs->personArray[ret].Name << "\t";
        cout << "性别：" << (abs->personArray[ret].Sex == 1 ? "男" : "女") << "\t";
        cout << "年龄：" << abs->personArray[ret].Age << "\t";
        cout << "电话：" << abs->personArray[ret].Phone << "\t";
        cout << "住址：" << abs->personArray[ret].Addr << "\t" << endl;
    }
    else
    {
        cout << "查无此人" << endl;
    }

    cout << "按任意键后回车继续...";
    cin.ignore(1024, '\n'); cin.get();
    system("clear");
}


//5、修改指定联系人信息  （此函数可以改进，修改单个属性如Phone）
void modifyPerson(addressBooks* abs)
{
    cout << "请输入您要修改的联系人" << endl;
    string name;
    cin >> name;

    int ret = ifExist(abs, name);
    if (ret != -1)
    {
        //姓名
        cout << "请输入姓名：" << endl;
        cin >> name;
        abs->personArray[ret].Name = name;

        //性别
        cout << "请输入性别：" << endl;
        cout << "1 -- 男" << endl;
        cout << "0 -- 女" << endl;
        int sex;
        while (true)
        {
            cin >> sex;
            if (sex == 1 || sex == 2)
            {
                abs->personArray[ret].Sex = sex;
                break;
            }
            cout << "输入有误，请重新输入";
        }

        //年龄
        cout << "请输入年龄：" << endl;
        int age;
        cin >> age;
        abs->personArray[ret].Age = age;

        //联系电话
        cout << "请输入联系电话：" << endl;
        string phone;
        cin >> phone;
        abs->personArray[ret].Phone = phone;

        //家庭住址
        cout << "请输入家庭住址：" << endl;
        string address;
        cin >> address;
        abs->personArray[ret].Addr = address;

        cout << "修改成功" << endl;
    }
    else
    {
        cout << "查无此人" << endl;
    }

    cout << "按任意键后回车继续...";
    cin.ignore(1024, '\n'); cin.get();
    system("clear");
}


//6、清空所有联系人
void cleanPerson(addressBooks* abs)
{
    abs->Size = 0;
    cout << "通讯录已清空" << endl;
    cout << "按任意键后回车继续...";
    cin.ignore(1024, '\n'); cin.get();
    system("clear");
}




int main() {
    addressBooks abs;
    abs.Size = 0;

    int select;

    while (true)
    {
        showMenu();
        cin >> select;

        switch (select)
        {
        case 1:  //添加联系人
            addPerson(&abs);
            break;
        case 2:  //显示联系人
            showPerson(&abs);
            break;
        case 3:  //删除联系人
            deletePerson(&abs);
            break;
        case 4:  //查找联系人
            findPerson(&abs);
            break;
        case 5:  //修改联系人
            modifyPerson(&abs);
            break;
        case 6:  //清空联系人
            cleanPerson(&abs);
            break;
        case 0:  //退出通讯录
            cout << "欢迎下次使用" << endl;
            return 0; // 跳出死循环
        default:
            break;
        }

    }

    system("pause");
    return 0;

}
