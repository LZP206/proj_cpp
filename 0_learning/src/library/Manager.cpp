#include "Manager.h"

Manager::Manager(int ID, string Name, int DeptID)
{
    this->m_ID = ID;
    this->m_Name = Name;
    this->m_DeptID = DeptID;
}

Manager::~Manager()
{
}

void Manager::showInfo()
{
    cout << this->m_ID << "\t"
         << this->m_Name << "\t"
         << this->getDeptName() << "\t"
         << this->getPosName() << "\t" << endl;
}

string Manager::getPosName()
{
    return string("经理");
}