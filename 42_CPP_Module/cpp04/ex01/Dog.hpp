#ifndef _Dog_HPP
#define _Dog_HPP
#include <iostream>
#include <string>
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal{
    private :
        Brain *brain;

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