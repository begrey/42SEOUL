#include "Cat.hpp"
Cat::Cat() : Animal("Cat"){
    std::cout << "<Cat> [Constructor] default called" << std::endl;
    this->type = "Cat";
}
Cat::Cat(std::string type){
    std::cout << "<Cat> [Constructor] type parameter called" << std::endl;
    this->type = type;
}
Cat::Cat(const Cat& origin){
    std::cout << "<Cat> [Constructor] Copy Called" << std::endl;
    this->type = origin.type;
}
Cat &Cat::operator=(const Cat& origin){
    std::cout << "<Cat> [Constructor] Operator Overloading Called" << std::endl;
    this->type = origin.type;
    return (*this);
}

Cat::~Cat(){
    std::cout << "<Cat> [Destructor] called" << std::endl;
}
void Cat::makeSound() const{
    std::cout << "Meow~~~~:3" <<std::endl;
}