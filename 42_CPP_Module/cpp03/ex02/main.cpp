#include "ClapTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
    FragTrap a;
    FragTrap b("jimkwon");
    FragTrap c(b);
    a = c;

    a.attack("cpp03");
    b.beRepaired(1000);
    c.takeDamage(9999);
    a.highFivesGuys();
    return 0;
}