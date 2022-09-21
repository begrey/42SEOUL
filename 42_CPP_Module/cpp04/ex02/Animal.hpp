#ifndef _Animal_HPP
#define _Animal_HPP
#include <iostream>
#include <string>

class Animal {
    protected :
        std::string type;

    public :
        Animal();
        Animal(std::string type);
        Animal(const Animal& origin);
        Animal &operator=(const Animal& origin);
        virtual ~Animal();
        void virtual makeSound() const = 0;
        std::string getType() const;
        void setType(std::string type);

};
#endif