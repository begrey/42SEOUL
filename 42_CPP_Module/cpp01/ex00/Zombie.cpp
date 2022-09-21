#include "Zombie.hpp"

Zombie::Zombie()
{
    this->name = "default Zombie";
    std::cout << "Grrrrr... Zombie Generated!!!" << std::endl;
}

Zombie::~Zombie()
{
    std::cout << "grrr.... <" + this->name + "> is Dead..." << std::endl;
}

void Zombie::announce(void)
{
    std::cout << "<" + this->name + ">  BraiiiiiiinnnzzzZ..." << std::endl;
}