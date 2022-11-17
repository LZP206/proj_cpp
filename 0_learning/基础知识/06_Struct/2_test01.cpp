#include <iostream>
using namespace std;
#include <string>
#include <ctime> // 随机数种子: srand((unsigned int)time(NULL));


/*
学校正在做毕设项目，每名老师带领5个学生，总共有3名老师，需求如下
设计学生和老师的结构体，其中在老师的结构体中，有老师姓名和一个存放5名学生的数组作为成员
学生的成员有姓名、考试分数，创建数组存放3名老师，通过函数给每个老师及所带的学生赋值
最终打印出老师数据以及老师所带的学生数据。
*/

struct student
{
    string name;
    int score;
};
struct teacher{
    string name;
    struct student s_arr[5];
};

// 给老师和学生赋值的函数
void allocateSpace(struct teacher *t_arr,int len)
{
    string nameSeed ="ABCDE";
    for (int i = 0; i < len; i++) {
        t_arr[i].name = "Teacher_";
        t_arr[i].name += nameSeed[i];
        // 通过循环给每名学生所带的学生赋值
        for (int j = 0; j < 5; j++) {
            t_arr[i].s_arr[j].name = "Student_";
            t_arr[i].s_arr[j].name += nameSeed[j];

            int random = rand()%61 +40;
            t_arr[i].s_arr[j].score = random;
        }

    }
}
// 打印所有信息的函数
void printInfo(struct teacher *t_arr, int len)
{
    for (int i = 0; i < len; ++i) {
        cout << "老师姓名：" << t_arr[i].name << endl;
        for (int j = 0; j < 5; ++j) {
            cout << "\t学生姓名：" << t_arr[i].s_arr[j].name
            << "\t分数：" << t_arr[i].s_arr[j].score << endl;
        }
    }
}


int main(){
    // 随机数种子
    srand((unsigned int)time(NULL));

    // 创建3名老师的数组
     struct teacher t_arr[3];

    // 通过函数给三名老师的信息赋值，并给老师带的学生的信息赋值
    int len = sizeof(t_arr)/sizeof(t_arr[0]);
    allocateSpace(t_arr,len);

    // 打印所有老师及所带学生的信息
    printInfo(t_arr,len);


    return 0;
}
