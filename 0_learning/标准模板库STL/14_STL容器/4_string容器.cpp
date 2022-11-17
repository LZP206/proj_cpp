#include <iostream>
using namespace std;

#include <string>



// ----------------------1.string构造函数----------------------

// string();        			//创建一个空的字符串 例如: string str;
// string(const char* s);          //使用字符串s初始化
// string(const string& str);      //使用一个string对象初始化另一个string对象
// string(int n, char c);          //使用n个字符c初始化 

void test01()
{
	string s1; //创建空字符串，调用无参构造函数
	cout << "str1 = " << s1 << endl;

	const char * str = "hello world";
	string s2(str); //把c_string转换成了string
	cout << "str2 = " << s2 << endl;

	string s3(s2); //调用拷贝构造函数
	cout << "str3 = " << s3 << endl;

	string s4(10, 'a');
	cout << "str4 = " << s4 << endl;
}




// ----------------------2.string赋值操作----------------------

// 赋值的函数原型：

// string& operator=(const char* s);          //char*类型字符串 赋值给当前的字符串
// string& operator=(const string &s);        //把字符串s赋给当前的字符串
// string& operator=(char c);                 //字符赋值给当前的字符串
// string& assign(const char *s);             //把字符串s赋给当前的字符串
// string& assign(const char *s, int n);      //把字符串s的前n个字符赋给当前的字符串
// string& assign(const string &s);           //把字符串s赋给当前字符串
// string& assign(int n, char c);             //用n个字符c赋给当前字符串

void test02()
{
    string str1;
	str1 = "hello world";
	cout << "str1 = " << str1 << endl;

	string str2;
	str2 = str1;
	cout << "str2 = " << str2 << endl;

	string str3;
	str3 = 'a';
	cout << "str3 = " << str3 << endl;

	string str4;
	str4.assign("hello c++");
	cout << "str4 = " << str4 << endl;

    string str5;
    str5.assign("hello c++",5);
	cout << "str5 = " << str5 << endl;

    string str6;
    str6.assign(str5);
	cout << "str6 = " << str6 << endl;

	string str7;
	str7.assign(5, 'x');
	cout << "str7 = " << str7 << endl;
}




// ----------------------3.string字符串拼接----------------------

// 函数原型：

// string& operator+=(const char* str);                 //重载+=操作符
// string& operator+=(const char c);                    //重载+=操作符
// string& operator+=(const string& str);               //重载+=操作符
// string& append(const char *s);                       //把字符串s连接到当前字符串结尾
// string& append(const char *s, int n);                //把字符串s的前n个字符连接到当前字符串结尾
// string& append(const string &s);                     //同operator+=(const string& str)
// string& append(const string &s, int pos, int n);     //字符串s中从pos开始的n个字符连接到字符串结尾

void test03()
{
	string str1 = "我";

    str1 += "爱玩游戏";

    cout << "str1 = " << str1 << endl;

    str1 += ':';

    cout << "str1 = " << str1 << endl;

    string str2 = "LOL DNF";

    str1 += str2;

    cout << "str1 = " << str1 << endl;

    string str3 = "I";
    str3.append(" love ");
    str3.append("game abcde", 4);
    str3.append(str2, 4, 3); // 从下标4位置开始 ，截取3个字符，拼接到字符串末尾
	// str3.append("LOL DNF",4,3);  // 也OK
    cout << "str3 = " << str3 << endl;
}





// ----------------------4.string查找和替换----------------------

// 函数原型：

// int find(const string& str, int pos = 0) const;      //查找str第一次出现位置,从pos开始查找
// int find(const char* s, int pos = 0) const;          //查找s第一次出现位置,从pos开始查找
// int find(const char* s, int pos, int n) const;       //从pos位置查找s的前n个字符第一次位置
// int find(const char c, int pos = 0) const;           //查找字符c第一次出现位置
// int rfind(const string& str, int pos = npos) const;  //查找str最后一次位置,从pos开始查找
// int rfind(const char* s, int pos = npos) const;      //查找s最后一次出现位置,从pos开始查找
// int rfind(const char* s, int pos, int n) const;      //从pos查找s的前n个字符最后一次位置
// int rfind(const char c, int pos = 0) const;          //查找字符c最后一次出现位置
// string& replace(int pos, int n, const string& str);  //替换从pos开始n个字符为字符串str
// string& replace(int pos, int n,const char* s);       //替换从pos开始的n个字符为字符串s

void test04()
{
	//------------------查找------------------
    string str1 = "abcdefgde";
    int pos = str1.find("de");  // pos = 3
    if (pos == -1){
        cout << "未找到" << endl;
    }
    else{
        cout << "pos = " << pos << endl;
    }
    pos = str1.rfind("de");     // pos = 7
    cout << "pos = " << pos << endl;

	// ------------------替换------------------
    str1.replace(1, 3, "1111");
    cout << "str1 = " << str1 << endl;
}





// ----------------------5.string字符串比较----------------------

// 函数原型：

// int compare(const string &s) const; //与字符串s比较
// int compare(const char *s) const;   //与字符串s比较

void test05()
{
	string s1 = "hello";
    string s2 = "aello";

    int ret = s1.compare(s2);

    if (ret == 0) {
        cout << "s1 等于 s2" << endl;
    }
    else if (ret > 0){
        cout << "s1 大于 s2" << endl;
    }
    else{
        cout << "s1 小于 s2" << endl;
    }
}







// ----------------------6.string字符存取----------------------

// 函数原型：

// char& operator[](int n);  //通过[]方式取字符
// char& at(int n);          //通过at方法获取字符

void test06()
{
	string str = "hello world";
    for (int i = 0; i < str.size(); i++)
    {
        cout << str[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < str.size(); i++)
    {
        cout << str.at(i) << " ";
    }
    cout << endl;

    //字符修改
    str[0] = 'x';
    str.at(1) = 'x';
    cout << str << endl;
}





// ----------------------7.string插入和删除----------------------

// 函数原型：

// string& insert(int pos, const char* s);       //插入字符串
// string& insert(int pos, const string& str);   //插入字符串
// string& insert(int pos, int n, char c);       //在指定位置插入n个字符c
// string& erase(int pos, int n = npos);         //删除从Pos开始的n个字符

void test07()
{
	//-------------插入----------------
	string str = "hello";
	string str_temp = "1111111";
	int insert_start= 0;
	int insert_length = 3;
	int pos_start = 1;
    str.insert(pos_start, str_temp,insert_start,insert_length);
    cout << str << endl;
	//-------------删除----------------
	str.erase(pos_start,insert_length);
	cout << str << endl;
}






// ----------------------8.string子串----------------------

// 函数原型：

// string substr(int pos = 0, int n = npos) const; //返回由pos开始的n个字符组成的字符串

void test08()
{
    string str = "abcdefg";
    string subStr = str.substr(1, 3);
    cout << "subStr = " << subStr << endl;

    string email_account = "lizeping@tju.edu.cn";
    int pos_end = email_account.find('@');
    string email_username = email_account.substr(0, pos_end);
    cout << "username: " << email_username << endl;
}




// ----------------------mian()----------------------
int main()
{
    test08();

	// system("pause");
    return 0;
}