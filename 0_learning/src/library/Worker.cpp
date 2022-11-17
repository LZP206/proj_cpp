#include "Worker.h"

Worker::Worker()
{
}

Worker::~Worker()
{
}

string Worker::getDeptName()
{
    string temp_DeptName;
    switch (this->m_DeptID)
    {
    case 101:
        temp_DeptName = "技术部";
        break;
    case 102:
        temp_DeptName = "销售部";
        break;
    case 103:
        temp_DeptName = "法务部";
        break;
    case 104:
        temp_DeptName = "财务部";
        break;
    case 105:
        temp_DeptName = "人力部";
        break;
    default:
        break;
    }
    return temp_DeptName;
}