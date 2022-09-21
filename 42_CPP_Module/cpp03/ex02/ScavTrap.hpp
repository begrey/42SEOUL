#ifndef _SCAVTRAP_HPP
#define _SCAVTRAP_HPP
#include "ClapTrap.hpp"     

class ScavTrap : public ClapTrap{

    public :
        ScavTrap();
        void attack(std::string const & target);
        ~ScavTrap();
        ScavTrap(const ScavTrap& origin);
        ScavTrap& operator=(const ScavTrap& origin);
        ScavTrap(std::string Name);
        void guardGate();
};
#endif