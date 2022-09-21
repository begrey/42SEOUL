#ifndef _FRAGTRAP_HPP
#define _FRAGTRAP_HPP
#include "ClapTrap.hpp"     

class FragTrap : virtual public ClapTrap{ // ? 가상상속으로 부모타입의 메모리가 중복되지 않게 상속

    public :
        FragTrap();
        void attack(std::string const & target);
        ~FragTrap();
        FragTrap(const FragTrap& origin);
        FragTrap& operator=(const FragTrap& origin);
        FragTrap(std::string Name);
        void highFivesGuys(void);
};
#endif