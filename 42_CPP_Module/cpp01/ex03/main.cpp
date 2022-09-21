#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"

// * 레퍼런스의 특성 : 선언과 동시에 초기화가 되어야 한다.
// * HumanB의 경우 생성된 후에 Weapon이 나중에 들어오기 때문에 포인터가 적당 
int main(void)
{
    {
    Weapon club = Weapon("crude spiked club");
    HumanA bob("Bob", club);
    bob.attack();
    club.setType("some other type of club");
    bob.attack();
    }
    {
    Weapon club = Weapon("crude spiked club");
    HumanB jim("Jim");
    jim.setWeapon(club);
    jim.attack();
    club.setType("some other type of club");
    jim.attack();
    }

}