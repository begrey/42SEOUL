#include "WrongCat.hpp"
WrongCat::WrongCat() : WrongAnimal("WrongCat"){
    std::cout << "<WrongCat> [Constructor] default called" << std::endl;
    this->type = "WrongCat";
}
WrongCat::WrongCat(std::string type){
    std::cout << "<WrongCat> [Constructor] type parameter called" << std::endl;
    this->type = type;
}
WrongCat::WrongCat(const WrongCat& origin){
    std::cout << "<WrongCat> [Constructor] Copy Called" << std::endl;
    this->type = origin.type;
}
WrongCat &WrongCat::operator=(const WrongCat& origin){
    std::cout << "<WrongCat> [Constructor] Operator Overloading Called" << std::endl;
    this->type = origin.type;
    return (*this);
}

WrongCat::~WrongCat(){
    std::cout << "<WrongCat> [Destructor] called" << std::endl;
}
void WrongCat::makeSound() const{
    std::cout << "Meow~~~~:3" <<std::endl;
}