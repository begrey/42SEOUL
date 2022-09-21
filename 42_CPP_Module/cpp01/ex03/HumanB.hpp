#ifndef _HumanB_HPP
#define _HumanB_HPP
#include <iostream>
#include <string>
#include "Weapon.hpp"

class HumanB {
private:
    std::string name;
    Weapon *W;

public:


    HumanB(std::string name);

    HumanB(std::string name, Weapon weapon);
    ~HumanB();

    //getter setter
    void setWeapon(Weapon &weapon);

    Weapon getWeapon();

    void attack();

};
#endif