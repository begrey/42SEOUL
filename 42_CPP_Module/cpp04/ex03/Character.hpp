#ifndef _Character_HPP
#define _Character_HPP
#include <iostream>
#include <string>
#include "ICharacter.hpp"

class Character : public ICharacter
{
    private:
        std::string Name;
        AMateria *inventory[4];
    public:
        Character(std::string Name);
        Character(const Character &origin);
        Character &operator=(const Character &origin);
        ~Character();
        std::string const & getName() const;
        void equip(AMateria* m);
        void unequip(int idx);
        virtual void use(int idx, ICharacter& target);
};
#endif