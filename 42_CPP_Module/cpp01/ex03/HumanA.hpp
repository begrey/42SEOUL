#ifndef _HumanA_HPP
#define _HumanA_HPP
#include <iostream>
#include <string>
#include "Weapon.hpp"

class HumanA {
private:
    std::string name;
    Weapon &W;

public:

    HumanA(std::string name, Weapon &weapon);

    ~HumanA();
    
    void attack();

};
#endif