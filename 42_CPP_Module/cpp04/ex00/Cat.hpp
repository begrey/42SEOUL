#ifndef _Cat_HPP
#define _Cat_HPP
#include <iostream>
#include <string>
#include "Animal.hpp"

class Cat : public Animal{
    protected :
        std::string type;

    public :
        Cat();
        Cat(std::string type);
        Cat(const Cat& origin);
        Cat &operator=(const Cat& origin);
        virtual ~Cat();
        virtual void makeSound() const;

};
#endif