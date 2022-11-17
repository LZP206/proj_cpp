#include <iostream>
using namespace std;
#include <string>

// 结构体属于用户自定义的数据类型，允许用户存储不同的数据类型



// 8.2 结构体定义和使用    定义语：struct 结构体名 { 结构体成员列表 }；
// 创建学生数据类型，包含属性：姓名，年龄，分数
struct student
{
    string name;
    int age;
    int score;
}stu3; // 定义结构体时顺便创建变量


// 8.5 结构体嵌套结构体
struct teacher
{
    int id;
    string name;
    int age;
    struct student stu;   // 结构体中的成员可以是另一个结构体
};


// 8.6 结构体做函数参数   （值传递和地址传递）
//值传递
void printStudent(student stu)
{
    stu.age = 28;
    cout << "子函数中 姓名：" << stu.name << " 年龄： " << stu.age  << " 分数：" << stu.score << endl;
}
//地址传递
void printStudent2(student *stu)
{
    stu->age = 28;
    cout << "子函数中 姓名：" << stu->name << " 年龄： " << stu->age  << " 分数：" << stu->score << endl;
}


// 使用指针可以减少传递的数据量，提高运行效率
// 但会改变主函数中的实参值---------->加const防止函数体中的误操作
void printStudent3(const student *stu)
{
    // stu->age = 28;  // 会报错，因为是常亮指针，只能读不能写
    cout << "子函数中 姓名：" << stu->name << " 年龄： " << stu->age  << " 分数：" << stu->score << endl;
}





int main() {
    // 8.7 结构体中 const使用场景:防止误操作
    struct student s = {"张三",15,70};
    printStudent3(&s);
    cout << "主函数中 姓名：" << s.name << " 年龄：" << s.age << " 分数：" << s.score << endl;




    // 8.6 结构体做函数参数
    struct student stu = { "张三",18,100};
    //值传递
    cout << "值传递：" << endl;
    printStudent(stu);
    cout << "主函数中 姓名：" << stu.name << " 年龄： " << stu.age << " 分数：" << stu.score << endl;

    //地址传递
    cout << "地址传递：" << endl;
    printStudent2(&stu);
    cout << "主函数中 姓名：" << stu.name << " 年龄： " << stu.age  << " 分数：" << stu.score << endl;




    // 8.5 结构体嵌套结构体
    struct teacher t1;
    t1.id = 10000;
    t1.name = "老王";
    t1.age = 40;

    t1.stu.name = "张三";
    t1.stu.age = 18;
    t1.stu.score = 100;

    cout << "教师 职工编号： " << t1.id << " 姓名： " << t1.name << " 年龄： " << t1.age << endl;
    cout << "辅导学员 姓名： " << t1.stu.name << " 年龄：" << t1.stu.age << " 考试分数： " << t1.stu.score << endl;



    // 8.4 结构体指针    作用：通过指针访问结构体中的成员
    // 利用操作符 -> 可以通过结构体指针访问结构体属性
    struct student stu0 = {"张三",18,80};
    struct student * p = &stu0;
    p -> score = 80; //指针通过 -> 操作符可以访问属性
    cout << "姓名：" << p->name << " 年龄：" << p->age << " 分数：" << p->score << endl;




    // 8.3 结构体数组     作用：将自定义的结构体放入到数组中方便维护
    struct student arr[3] =
            {
                    {"张三",18,80},
                    {"李四",19,60 },
                    {"王五",20,70 }
            };
    for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++)
    {
        cout << "姓名：" << arr[i].name << " 年龄：" << arr[i].age << " 分数：" << arr[i].score << endl;
    }





    // 8.2 结构体定义和使用   使用：结构体变量创建方式 3种

    // 方式1：struct 结构体名 变量名
    struct student stu1; //struct 关键字可以省略
    stu1.name = "张三";
    stu1.age = 18;  // 通过==变量名.属性==来访问
    stu1.score = 100;
    cout << "姓名：" << stu1.name << " 年龄：" << stu1.age  << " 分数：" << stu1.score << endl;

    // 方式2：struct 结构体名 变量名 = { 成员1值 ， 成员2值...}
    struct student stu2 = { "李四",19,60 };
    cout << "姓名：" << stu2.name << " 年龄：" << stu2.age  << " 分数：" << stu2.score << endl;

    // 方式3：定义结构体时顺便创建变量
    stu3.name = "王五";
    stu3.age = 18;
    stu3.score = 80;
    cout << "姓名：" << stu3.name << " 年龄：" << stu3.age  << " 分数：" << stu3.score << endl;




    return 0;
}
