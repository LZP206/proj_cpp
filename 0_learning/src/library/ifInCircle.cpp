#include "ifInCircle.h"


void ifInCircle(CircleType &c, PointType &p){
    // 计算两点之间距离的平方
    double distance =
            ( c.getCenter().getX() - p.getX() ) * ( c.getCenter().getX() - p.getX() ) +
            ( c.getCenter().getY() - p.getY() ) * ( c.getCenter().getY() - p.getY() );
    //计算半径的平方
    double r_distance = c.getR() * c.getR();
    // 判断
    if (distance == r_distance)
    {
        cout << "点在圆上" << endl;
    }
    else if (distance > r_distance)
    {
        cout << "点在圆外" << endl;
    }
    else
    {
        cout << "点在圆内" << endl;
    }
}
