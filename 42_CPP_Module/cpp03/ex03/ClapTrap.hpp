#ifndef _CLAPTRAP_HPP
#define _CLAPTRAP_HPP
#include <iostream>
#include <string>

class ClapTrap {
    private :
        std::string Name;
        int Hitpoints;
        int Energy_points;
        int Attack_damage;

    public :
        void attack(std::string const & target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
        ClapTrap();
        ~ClapTrap();
        ClapTrap(const ClapTrap& origin);
        ClapTrap& operator=(const ClapTrap& origin);
        ClapTrap(std::string Name);
        void setName(std::string Name);
        std::string getName();
        void setHitpoints(int Hitpoints);
        int getHitpoints();
        void setEnergy_points(int Energy_points);
        int getEnergy_points();
        void setAttack_damage(int Attack_damage);
        int getAttack_damage();


};
#endif