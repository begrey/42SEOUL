#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap(){
    std::cout << "[ScavTrap][Constructor] default Called" << std::endl;
    setName("default_ScavTrap");
    setHitpoints(100);
    setEnergy_points(50);
    setAttack_damage(20);
}
ScavTrap::ScavTrap(std::string Name) : ClapTrap(Name){
    std::cout << "[ScavTrap][Constructor] Name Parameter Called" << std::endl;
    setName(Name);
    setHitpoints(100);
    setEnergy_points(50);
    setAttack_damage(20);
}
ScavTrap::~ScavTrap(){
    std::cout << "[ScavTrap][Destructor] Called" << std::endl;
}
ScavTrap::ScavTrap(const ScavTrap& origin) : ClapTrap(origin){
    std::cout << "[ScavTrap][Constructor] Copy Called" << std::endl;
}
ScavTrap& ScavTrap::operator=(const ScavTrap& origin){
    ClapTrap::operator =(origin);
    std::cout << "[ScavTrap][Constructor] Operator Overloading Called" << std::endl;
    return (*this);
}
void ScavTrap::attack(std::string const & target) {
    std::cout << "ScavTrap " + getName() + " attacks " + target + ", causing "  << getAttack_damage() 
    << " points of damage!" << std::endl;
}

void ScavTrap::guardGate() {
    std::cout << "ScavTrap have enterred in Gate keeper mode!" << std::endl;
}