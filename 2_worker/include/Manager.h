#pragma once
#include <iostream>
using namespace std;

#include "Worker.h"


class Manager : public Worker
{
public:
    Manager(int ID, string Name, int DeptID);
    ~Manager();
    void showInfo();       
    string getPosName();  
};

