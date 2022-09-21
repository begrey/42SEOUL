#include "Zombie.hpp"

int main(void)
{
    Zombie *horde = NULL;

    horde = horde->zombieHorde(10, "jimkwon");

    for(int i = 0; i < 10; i++)
        horde[i].announce();
    //delete zombies;
}