#include "CircleType.h"

// 只需保留成员函数的所有实现
// 但要告诉成员函数的作用域 !!!

    // 设置半径
    void CircleType::setR(double r){
        m_R = r;
    }
    // 获取半径
    double CircleType::getR(){
        return m_R;
    }
    // 设置圆心
    void CircleType::setCenter(PointType center){
        m_Center = center;
    }
    // 获取圆心
    PointType CircleType::getCenter(){
        return m_Center;
    }



