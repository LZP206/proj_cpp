#include <iostream>
using namespace std;
#include <string>


/*
设计一个英雄的结构体，包括成员姓名，年龄，性别;
创建结构体数组，数组中存放5名英雄。
通过冒泡排序的算法，将数组中的英雄按照年龄进行升序排序，最终打印排序后的结果
*/

//英雄结构体
struct hero
{
    string name;
    int age;
    string sex;
};
void printHero(struct hero *h_arr, int len)
{
    for (int i = 0; i < len; i++) {
        cout << "姓名：" << h_arr[i].name << "\t年龄：" << h_arr[i].age
             << "\t性别：" << h_arr[i].sex << endl;
    }
}

void bubbleSort_age(struct hero *h_arr, int len)
{
    for (int i = 0; i < len-1; i++) {
        for (int j = 0; j < len-1-i; j++) {
            if (h_arr[j].age > h_arr[j+1].age)
            {
                struct hero temp = h_arr[j];
                h_arr[j] = h_arr[j+1];
                h_arr[j+1] = temp;
            }
        }
    }
}



int main(){
    struct hero h_arr[5] =
            {
                    {"刘备",23,"男"},
                    {"关羽",22,"男"},
                    {"张飞",20,"男"},
                    {"赵云",21,"男"},
                    {"貂蝉",19,"女"},
            };
    int len = sizeof(h_arr)/sizeof(h_arr[0]);
    printHero(h_arr,len);
    cout << endl;

    cout << "对数组按年龄大小进行冒泡升序排序:" << endl;
    bubbleSort_age(h_arr,len);
    printHero(h_arr,len);

    return 0;
}
