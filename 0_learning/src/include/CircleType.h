#pragma once
#include <iostream>
using namespace std;

#include "PointType.h"


// 需保留所有成员的声明
class CircleType
{
private:
    double m_R;
    PointType m_Center;
public:
    // 设置半径
    void setR(double r);
    // 获取半径
    double getR();
    // 设置圆心
    void setCenter(PointType center);
    // 获取圆心
    PointType getCenter();
};
