#ifndef _WrongAnimal_HPP
#define _WrongAnimal_HPP
#include <iostream>
#include <string>

class WrongAnimal {
    protected :
        std::string type;

    public :
        WrongAnimal();
        WrongAnimal(std::string type);
        WrongAnimal(const WrongAnimal& origin);
        WrongAnimal &operator=(const WrongAnimal& origin);
        ~WrongAnimal();
        void makeSound() const;
        std::string getType() const;
        void setType(std::string type);

};
#endif