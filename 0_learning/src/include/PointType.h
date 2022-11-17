#pragma  once
#include <iostream>
using namespace std;


// 需保留所有成员的声明

class PointType
{
private:
    double m_x;
    double m_y;
public:
    // 设置x坐标
    void setX(double x);
    // 获取x坐标
    double getX();

    // 设置y坐标
    void setY(double y);
    // 获取y坐标
    double getY();
};