#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap(){
    std::cout << "[FragTrap][Constructor] default Called" << std::endl;
    setName("default_FragTrap");
    setHitpoints(100);
    setEnergy_points(100);
    setAttack_damage(30);
}
FragTrap::FragTrap(std::string Name) : ClapTrap(Name){
    std::cout << "[FragTrap][Constructor] Name Parameter Called" << std::endl;
    setName(Name);
    setHitpoints(100);
    setEnergy_points(100);
    setAttack_damage(30);
}
FragTrap::~FragTrap(){
    std::cout << "[FragTrap][Destructor] Called" << std::endl;
}
FragTrap::FragTrap(const FragTrap& origin) : ClapTrap(origin){
    std::cout << "[FragTrap][Constructor] Copy Called" << std::endl;
}
FragTrap& FragTrap::operator=(const FragTrap& origin){
    ClapTrap::operator =(origin);
    std::cout << "[FragTrap][Constructor] Operator Overloading Called" << std::endl;
    return (*this);
}
void FragTrap::attack(std::string const & target) {
    std::cout << "FragTrap " + getName() + " attacks " + target + ", causing "  << getAttack_damage() 
    << " points of damage!" << std::endl;
}

void FragTrap::highFivesGuys() {
    std::cout << "FragTrap request positive highFivesGuys!" << std::endl;
}