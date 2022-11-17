#include "Employee.h"

Employee::Employee(int ID, string Name, int DeptID)
{
    this->m_ID = ID;
    this->m_Name = Name;
    this->m_DeptID = DeptID;
}

Employee::~Employee()
{
}

void Employee::showInfo()
{
    cout << this->m_ID << "\t"
         << this->m_Name << "\t"
         << this->getDeptName() << "\t"
         << this->getPosName() << "\t" << endl;
}

string Employee::getPosName()
{
    return string("职员");
}