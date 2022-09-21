#include "Dog.hpp"
Dog::Dog() : Animal("Dog"){
    std::cout << "<Dog> [Constructor] default called" << std::endl;
    this->type = "Dog";
}
Dog::Dog(std::string type) {
    std::cout << "<Dog> [Constructor] type parameter called" << std::endl;
    this->type = type;
}
Dog::Dog(const Dog& origin){
    std::cout << "<Dog> [Constructor] Copy Called" << std::endl;
    this->type = origin.type;
}
Dog &Dog::operator=(const Dog& origin){
    std::cout << "<Dog> [Constructor] Operator Overloading Called" << std::endl;
    this->type = origin.type;
    return (*this);
}

Dog::~Dog(){
    std::cout << "<Dog> [Destructor] called" << std::endl;
}
void Dog::makeSound() const{
    std::cout << "Bow!! Bow!!XD" <<std::endl;
}