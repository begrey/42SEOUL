#ifndef _WrongCat_HPP
#define _WrongCat_HPP
#include <iostream>
#include <string>
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal{
    protected :
        std::string type;

    public :
        WrongCat();
        WrongCat(std::string type);
        WrongCat(const WrongCat& origin);
        WrongCat &operator=(const WrongCat& origin);
        ~WrongCat();
        void makeSound() const;

};
#endif