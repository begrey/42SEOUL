#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main(void)
{
    DiamondTrap a("jimkwon");

    a.ScavTrap::attack("cpp03");
    std::cout << "Hitpoints : " << a.getHitpoints() << std::endl;
    std::cout << "Energy points : " << a.getEnergy_points() << std::endl;
    std::cout << "Attack damage : " << a.getAttack_damage() << std::endl;
    a.beRepaired(1000);
    a.takeDamage(9999);
    a.highFivesGuys();
    a.guardGate();
    a.whoAmI();
    return 0;
}