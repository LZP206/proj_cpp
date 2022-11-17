#pragma once
#include <iostream>
using namespace std;

class Gun
{
private:
    int _bullet_count;
    string _type;

public:
    Gun(string type);
    void addBullet(int num);
    bool shoot();
};
