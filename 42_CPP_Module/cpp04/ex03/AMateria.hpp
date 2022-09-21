#ifndef _AMateria_HPP
#define _AMateria_HPP
#include <iostream>
#include <string>
#include "ICharacter.hpp"

class ICharacter; // ? 상호참조 할 때 predeclaration 전방선언
class AMateria
{
    protected:
        std::string type;
    public:
        AMateria();
        AMateria(std::string const & type);
        AMateria(const AMateria& origin);
        AMateria &operator=(const AMateria& origin);
        virtual ~AMateria();
        std::string const & getType() const; //Returns the materia type
        virtual AMateria* clone() const = 0;
        virtual void use(ICharacter& target);
};
#endif