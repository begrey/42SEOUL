#ifndef _MateriaSource_HPP
#define _MateriaSource_HPP
#include <iostream>
#include <string>
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
    private:
        AMateria *temp[4];

    public:
        MateriaSource();
        ~MateriaSource();
        virtual void learnMateria(AMateria*);
        virtual AMateria* createMateria(std::string const & type);
};
#endif