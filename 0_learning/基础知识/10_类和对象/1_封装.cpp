#include <iostream>
using namespace std;

#include "CircleType.h"
#include "PointType.h"
#include "ifInCircle.h"







const double PI = 3.14;
// 1、封装的意义
// 1)将属性和行为作为一个整体，用来表现生活中的事物  语法：class 类名{   访问权限： 属性  / 行为  };

// 封装一个圆类，求圆的周长
class Circle
{
public:                   //访问权限  公共的权限
    int m_r;              //属性1:半径
    double calculateZC()  //行为(函数):获取到圆的周长
    {
        //获取圆的周长 = 2 * pi  * r
        return  2 * PI * m_r;
    }
};

// 设计一个学生类，属性有姓名和学号，可以给姓名和学号赋值，可以显示学生的姓名和学号
class Student
{
public:
    string m_name;
    int m_ID;

    // 显示学生姓名和学号
    void showStudent()
    {
        cout << "Name:" << m_name << "\t"
             << "ID:" << m_ID << endl;
    }

    // 可以通过行为给属性赋值！！！
    // 给姓名赋值
    void setName(string name) {
        m_name = name;
    }
    // 给学号赋值
    void setID(int id) {
        m_ID = id;
    }
};

// 2)类在设计时，可以把属性和行为放在不同的权限下，加以控制
//公共权限  public     类内可以访问  类外可以访问
//保护权限  protected  类内可以访问  类外不可以访问
//私有权限  private    类内可以访问  类外不可以访问
class Person
{
    //姓名  公共权限
public:
    string m_Name;

    //汽车  保护权限
protected:
    string m_Car;

    //银行卡密码  私有权限
private:
    int m_Password;

public:
    void func()
    {
        m_Name = "张三";  // 三个属性雷内都可以访问
        m_Car = "拖拉机";
        m_Password = 123456;
    }
    void setPassword(int password)
    {
        m_Password = password;
    }
    void showPerson()
    {
        cout << "Name:" << m_Name << "\t"
             << "Password:" << m_Password << endl;
    }

};









// 2.struct和class区别   * struct 默认权限为公共   * class 默认权限为私有
class C1
{
    int  m_A; //默认是私有权限
};

struct C2
{
    int m_A;  //默认是公共权限
};




// 3.成员属性设置为私有
// **优点1：**将所有成员属性设置为私有，可以自己控制读写权限
// **优点2：**对于写权限，我们可以检测数据的有效性
class Person2
{
private:             // 可以自己控制读写权限(优点1)
    string  m_name;  // 姓名   可读可写
    int m_age;       // 年龄   可读可写  但年龄有范围要求
    string  m_lover; // 年龄   只写
public:
    //姓名设置可读可写
    void setName(string name){
        m_name = name;
    }
    string getName(){
        return m_name;
    }

    // 读取年龄
    int getAge() {
        return m_age;
    }
    // 设置年龄
    void setAge(int age) {
        if (age < 0 || age > 150) {   //对于写权限，我们可以检测数据的有效性
            cout << "你个老妖精!" << endl;
            return;
        }
        m_age = age;
    }

    // 只写情人
    void setLover(string lover) {
        m_lover = lover;
    }
};






// 案例1：设计立方体类Cube:
// 求出立方体的面积和体积,分别用全局函数和成员函数判断两个立方体是否相等。
class Cube
{
private:
    double m_L;
    double m_W;
    double m_H;
public:
    void setL(double L) {m_L = L;}// 设置长
    double getL() {return m_L;}//获取长

    void setW(double W) {m_W = W;}// 设置宽
    double getW() {return m_W;}//获取宽

    void setH(double H) {m_H = H;}// 设置高
    double getH()  {return m_H;}//获取高

    // 获取立方体面积
    double calculateS(){
        return 2*(m_H * m_L + m_H * m_W + m_L * m_W);
    }
    // 获取立方体体积
    double calculateV(){
        return m_H * m_L * m_W;
    }

    // 利用成员函数判断两个立方体是否相等
    bool ifSameByClass(Cube &c) const{
        if (c.getL()==m_L && c.getH()==m_W && c.getH()==m_H)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

// 利用全局函数判断两个立方体是否相等
bool ifSame(Cube & c1,Cube & c2){
    if (c1.getL()==c2.getL() && c1.getH()==c2.getW() && c1.getH()==c2.getH())
    {
        return true;
    }
    else
    {
        return false;
    }
}








// 案例2：点和圆的关系
// 设计一个圆形类（CircleType），和一个点类（PointType），计算点和圆的关系（点在圆外、上、内）。
//class PointType
//{
//private:
//    double m_x;
//    double m_y;
//public:
//    // 设置x坐标
//    void setX(double x){
//        m_x = x;
//    }
//    // 获取x坐标
//    double getX(){
//        return m_x;
//    }
//
//    // 设置y坐标
//    void setY(double y){
//        m_y = y;
//    }
//    // 获取y坐标
//    double getY(){
//        return m_y;
//    }
//};


//class CircleType
//{
//private:
//    double m_R;
//    PointType m_Center;
//public:
//    // 设置半径
//    void setR(double r){
//        m_R = r;
//    }
//    // 获取半径
//    double getR(){
//        return m_R;
//    }
//    // 设置圆心
//    void setCenter(PointType center){
//        m_Center = center;
//    }
//    // 获取圆心
//    PointType getCenter(){
//        return m_Center;
//    }
//};

//void ifInCircle(CircleType &c, PointType &p){
//    // 计算两点之间距离的平方
//    double distance =
//    ( c.getCenter().getX() - p.getX() ) * ( c.getCenter().getX() - p.getX() ) +
//    ( c.getCenter().getY() - p.getY() ) * ( c.getCenter().getY() - p.getY() );
//    //计算半径的平方
//    double r_distance = c.getR() * c.getR();
//    // 判断
//    if (distance == r_distance)
//    {
//        cout << "点在圆上" << endl;
//    }
//    else if (distance > r_distance)
//    {
//        cout << "点在圆外" << endl;
//    }
//    else
//    {
//        cout << "点在圆内" << endl;
//    }
//}





int main() {
    // 案例2
    // 创建圆
    CircleType c;
    c.setR(10);
    PointType center;
    center.setX(10);
    center.setY(0);
    c.setCenter(center);
    // 创建点
    PointType p1;
    p1.setX(10);
    p1.setY(10);
    ifInCircle(c,p1);
    PointType p2;
    p2.setX(10);
    p2.setY(20);
    ifInCircle(c,p2);






    // 案例1
    Cube cu1;
    cu1.setL(10);
    cu1.setW(10);
    cu1.setH(10);
    cout << "S = " << cu1.calculateS() << endl;
    cout << "V = " << cu1.calculateV() << endl;
    // 创建第二个立方体
    Cube cu2;
    cu2.setL(10);
    cu2.setW(10);
    cu2.setH(10);
    // 利用全局函数判断两个立方体是否相等
    bool ret = ifSame(cu1,cu2);
    cout << "全局函数判断:";
    if (ret) //如果ret为真值
    {
        cout << "cu1和cu2是相等的" << endl;
    }
    else
    {
        cout << "cu1和cu2是不相等的" << endl;
    }
    // 利用成员函数判断两个立方体是否相等
    ret = cu1.ifSameByClass(cu2);
    cout << "成员函数判断:";
    if (ret) //如果ret为真值
        cout << "cu1和cu2是相等的" << endl;
    else
    {
        cout << "cu1和cu2是不相等的" << endl;
    }




    // 3.成员属性设置为私有
    Person2 per2;
    // 写姓名
    per2.setName("张三");
    cout << "姓名： " << per2.getName() << endl; // 读姓名
    // 年龄设置
    per2.setAge(50);
    cout << "年龄： " << per2.getAge() << endl;// 年龄读取

    //情人设置
    per2.setLover("苍井");







    // 2.struct和class区别
    //C1 c21{};
    //c21.m_A = 10; //错误，访问权限是私有 'm_A' is a private member of 'C1'
    C2 c22;
    c22.m_A = 10; //正确，访问权限是公共






    //1.通过圆类，创建具体的圆对象（实例化）
    Circle c1;
    c1.m_r = 10;
    cout << "圆c1的周长为：" << c1.calculateZC() << endl;

    Student s1;
    s1.setName("张三");
    s1.setID(250);
    s1.showStudent();

    Person p;
    p.m_Name = "李四";
    //p.m_Car = "奔驰";  //保护权限类外访问不到
    //p.m_Password = 123; //私有权限类外访问不到
    p.setPassword(255333);
    p.showPerson();

    system("pause");
    return 0;
}
