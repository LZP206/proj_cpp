#pragma once
#include <iostream>
using namespace std;

#include "Worker.h"


class Employee : public Worker
{
public:
    Employee(int ID, string Name, int DeptID);
    ~Employee();
    
    void showInfo();       
    string getPosName();  
};

