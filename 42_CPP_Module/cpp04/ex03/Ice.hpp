#ifndef _Ice_HPP
#define _Ice_HPP
#include <iostream>
#include <string>
#include "AMateria.hpp"

class Ice : public AMateria
{
    public:
        Ice();
        ~Ice();
        virtual AMateria* clone() const;
        virtual void use(ICharacter& target);
};
#endif