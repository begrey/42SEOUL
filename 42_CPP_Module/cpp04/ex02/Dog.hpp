#ifndef _Dog_HPP
#define _Dog_HPP
#include <iostream>
#include <string>
#include "Animal.hpp"

class Dog : public Animal{
    protected :
        std::string type;

    public :
        Dog();
        Dog(std::string type);
        Dog(const Dog& origin);
        Dog &operator=(const Dog& origin);
        virtual ~Dog();
        virtual void makeSound() const;

};
#endif