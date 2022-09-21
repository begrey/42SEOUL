#ifndef _Cat_HPP
#define _Cat_HPP
#include <iostream>
#include <string>
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal{
    private :
        Brain *brain;

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