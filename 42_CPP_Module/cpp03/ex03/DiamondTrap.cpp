#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(), ScavTrap(), FragTrap() {
    setName("default_DiamondTrap");
    ClapTrap::setName(Name + "_clap_name");
    FragTrap::setHitpoints(100);
    ScavTrap::setEnergy_points(50);
    FragTrap::setAttack_damage(30);
}
DiamondTrap::DiamondTrap(std::string Name) : ClapTrap(Name), ScavTrap(Name), FragTrap(Name)  {
    std::cout << "[DiamondTrap][Constructor] Name Parameter Called" << std::endl;
    DiamondTrap::setName(Name);
    ClapTrap::setName(Name + "_clap_name");
    FragTrap::setHitpoints(100);
    ScavTrap::setEnergy_points(50);
    FragTrap::setAttack_damage(30);
}
void DiamondTrap::attack(std::string const & target) {
    ScavTrap::attack(target);
}
DiamondTrap::~DiamondTrap()  {
    std::cout << "[DiamondTrap][Destructor] Called" << std::endl;
}
DiamondTrap::DiamondTrap(const DiamondTrap& origin) : ClapTrap(origin){
    std::cout << "[DiamondTrap][Constructor] Copy Called" << std::endl;
}
DiamondTrap& DiamondTrap::operator=(const DiamondTrap& origin) {
    ClapTrap::operator =(origin);
    std::cout << "[DiamondTrap][Constructor] Operator Overloading Called" << std::endl;
    return (*this);
}
void DiamondTrap::setName(std::string _Name){
    this->Name = _Name;
}
std::string DiamondTrap::getName(){
    return this->Name;
}
void DiamondTrap::whoAmI(void) {
    std::cout << "Hi! my name is " << DiamondTrap::getName() << "!! and ClapTrap Name: " << ClapTrap::getName() << std::endl;
}