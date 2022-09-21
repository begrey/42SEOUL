#include "AMateria.hpp"

AMateria::AMateria() {
    this->type = "default";
}

AMateria::AMateria(std::string const & type){
    this->type = type;
}
AMateria::AMateria(const AMateria& origin){
    this->type = origin.type;
}
AMateria &AMateria::operator=(const AMateria& origin){
    this->type = origin.type;
    return (*this);
}
AMateria::~AMateria(){
    //소멸자!
}
std::string const & AMateria::getType() const{
    return this->type;
}

void AMateria::use(ICharacter& target){
    //(void)target;
    std::cout << target.getName() << std::endl;
}