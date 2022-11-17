#pragma once
#include <iostream>
using namespace std;
#include "Gun.h"

class Soldier
{
private:
    string _name;
    Gun *_ptr_gun;

public:
    Soldier(string name);
    ~Soldier();
    void addGun(Gun* ptr_gun);
    void addBulletToGun(int num);
    bool fire();
};
