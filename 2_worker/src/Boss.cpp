#include "Boss.h"

Boss::Boss(int ID, string Name, int DeptID)
{
    this->m_ID = ID;
    this->m_Name = Name;
    this->m_DeptID = DeptID;
}

Boss::~Boss()
{
}

void Boss::showInfo()
{
    cout << this->m_ID << "\t"
         << this->m_Name << "\t"
         << this->getDeptName() << "\t"
         << this->getPosName() << "\t" << endl;
}

string Boss::getPosName()
{
    return string("总裁");
}