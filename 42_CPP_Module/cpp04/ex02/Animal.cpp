#include "Animal.hpp"
Animal::Animal(){
    std::cout << "[Constructor] default called" << std::endl;
    this->type = "default";
}
Animal::Animal(std::string type){
    std::cout << "[Constructor] type parameter called" << std::endl;
    this->type = type;
}
Animal::Animal(const Animal& origin){
    this->type = origin.type;
}
Animal &Animal::operator=(const Animal& origin){
    this->type = origin.type;
    return (*this);
}
Animal::~Animal(){
    std::cout << "[Destructor] called" << std::endl;
}
std::string Animal::getType() const{
    return this->type;
}
void Animal::setType(std::string type){
    this->type = type;
}