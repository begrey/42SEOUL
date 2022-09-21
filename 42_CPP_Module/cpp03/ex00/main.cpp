#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap a;
    ClapTrap b("jimkwon");
    ClapTrap c(b);
    a = c;

    a.attack("cpp03");
    b.beRepaired(1000);
    c.takeDamage(9999);
    return 0;
}