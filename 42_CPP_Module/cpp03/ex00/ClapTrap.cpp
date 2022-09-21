#include "ClapTrap.hpp"

void ClapTrap::attack(std::string const & target){
    std::cout << "ClapTrap " + this->Name + " attacks " + target + ", causing "  << this->Attack_damage 
    << " points of damage!" << std::endl;
}
void ClapTrap::takeDamage(unsigned int amount){
    std::cout << "ClapTrap " + this->Name + " take " << amount << " points of damage!" << std::endl;
}
void ClapTrap::beRepaired(unsigned int amount){
    std::cout << "ClapTrap " + this->Name + " is repaired " << amount << " points!" << std::endl;
}
ClapTrap::ClapTrap(){
    std::cout << "[Constructor] default Called" << std::endl;
    this->Name = "42seoul";
    this->Hitpoints = 10;
    this->Energy_points = 10;
    this->Attack_damage = 0;
}
ClapTrap::~ClapTrap() {
    std::cout << "[Destructor] Called" << std::endl;
}

ClapTrap::ClapTrap(std::string Name){
    std::cout << "[Constructor] Name Parameter Called" << std::endl;
    this->Hitpoints = 10;
    this->Energy_points = 10;
    this->Attack_damage = 0;
    this->Name = Name;
}
ClapTrap::ClapTrap(const ClapTrap& origin){
    std::cout << "[Constructor] Copy Called" << std::endl;
    this->Name = origin.Name;
}
ClapTrap& ClapTrap::operator=(const ClapTrap& origin){
    std::cout << "[Constructor] Operator Overloading Called" << std::endl;
    this->Name = origin.Name;
    return (*this);
}