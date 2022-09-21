#ifndef _Cure_HPP
#define _Cure_HPP
#include <iostream>
#include <string>
#include "AMateria.hpp"

class Cure : public AMateria
{
    public:
        Cure();
        ~Cure();
        virtual AMateria* clone() const;
        virtual void use(ICharacter& target);
};
#endif