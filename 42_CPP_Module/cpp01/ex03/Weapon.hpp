#ifndef _WEAPON_HPP
#define _WEAPON_HPP
#include <iostream>
#include <string>

class Weapon {
public:
    std::string type;

    Weapon();

    Weapon(std::string type);

    ~Weapon();

    void setType(std::string type);
    const std::string& getType();

};
#endif