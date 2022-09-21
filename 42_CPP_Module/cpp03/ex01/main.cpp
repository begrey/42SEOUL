#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
    ScavTrap a;
    ScavTrap b("jimkwon");
    ScavTrap c(b);
    a = c;

    a.attack("cpp03");
    b.beRepaired(1000);
    c.takeDamage(9999);
    a.guardGate();
    return 0;
}