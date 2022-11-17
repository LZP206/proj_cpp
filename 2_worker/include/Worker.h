#pragma once
#include <iostream>
using namespace std;

// 职工抽象基类
class Worker
{
public:
    Worker();
    virtual ~Worker() = 0;

    virtual void showInfo() = 0;       // 显示个人信息
    virtual string getPosName() = 0;  // 获取岗位名称
    string getDeptName();

    int m_ID;        // 职工编号
    string m_Name;   // 职工姓名
    int m_DeptID;    // 部门编号
};