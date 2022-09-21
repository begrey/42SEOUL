#ifndef _DiamondTrap_HPP
#define _DiamondTrap_HPP
#include "FragTrap.hpp"     
#include "ScavTrap.hpp"     

class DiamondTrap : public ScavTrap, public FragTrap{
    private :
        std::string Name;
    public :
        DiamondTrap();
        void attack(std::string const & target);
        ~DiamondTrap();
        DiamondTrap(const DiamondTrap& origin);
        DiamondTrap& operator=(const DiamondTrap& origin);
        DiamondTrap(std::string Name);
        void setName(std::string Name);
        std::string getName();
        void whoAmI(void);
};
#endif