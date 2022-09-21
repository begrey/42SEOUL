#include "WrongAnimal.hpp"
WrongAnimal::WrongAnimal(){
    std::cout << "[Constructor] default called" << std::endl;
    this->type = "default";
}
WrongAnimal::WrongAnimal(std::string type){
    std::cout << "[Constructor] type parameter called" << std::endl;
    this->type = type;
}
WrongAnimal::WrongAnimal(const WrongAnimal& origin){
    this->type = origin.type;
}
WrongAnimal &WrongAnimal::operator=(const WrongAnimal& origin){
    this->type = origin.type;
    return (*this);
}
WrongAnimal::~WrongAnimal(){
    std::cout << "[Destructor] called" << std::endl;
}
void WrongAnimal::makeSound() const{
    std::cout << "WrongAnimal make sound!!!!" <<std::endl;
}
std::string WrongAnimal::getType() const{
    return this->type;
}
void WrongAnimal::setType(std::string type){
    this->type = type;
}