#include "Cure.hpp"
Cure::Cure(){
    this->type = "cure";
}
Cure::~Cure(){
    
}
AMateria* Cure::clone() const{
    AMateria *clone = new Cure();
    return clone;
}
void Cure::use(ICharacter& target){
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}