#include "Gun.h"

Gun::Gun(string type)
{
    this->_type = type;
    this->_bullet_count = 0;
}

void Gun::addBullet(int num)
{
    this->_bullet_count += num;
}

bool Gun::shoot()
{
    if (this->_bullet_count <= 0)
    {
        cout << "there is no bullet in the gun" << endl;
        return false;
    }
    this->_bullet_count -= 1;
    cout << "shoot successfully" << endl;
    return true;
}
