#include "HumanB.hpp"

HumanB::HumanB(std::string name){
    this->name = name;
    std::cout << this->name + " Btype Born!" << std::endl;
}

HumanB::~HumanB() {
    std::cout << this->name + " Btype Dead..." << std::endl;
}

    //getter setter
void HumanB::setWeapon(Weapon &weapon){
    this->W = &weapon;
}

void HumanB::attack() {
    std::cout << name << " attacks with his " << this->W->getType() << std::endl;
}