#include "PointType.h"

// 只需保留成员函数的所有实现
// 但要告诉成员函数的作用域 !!!

    // 设置x坐标
    void PointType::setX(double x){
        m_x = x;
    }
    // 获取x坐标
    double PointType::getX(){
        return m_x;
    }
    // 设置y坐标
    void PointType::setY(double y){
        m_y = y;
    }
    // 获取y坐标
    double PointType::getY(){
        return m_y;
    }

