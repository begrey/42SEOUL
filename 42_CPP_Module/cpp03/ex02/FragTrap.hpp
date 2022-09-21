#ifndef _FRAGTRAP_HPP
#define _FRAGTRAP_HPP
#include "ClapTrap.hpp"     

class FragTrap : public ClapTrap{

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