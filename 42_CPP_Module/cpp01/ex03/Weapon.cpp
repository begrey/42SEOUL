#include "Weapon.hpp"

Weapon::Weapon() {
    ;
}

Weapon::Weapon(std::string type) {
    this->type = type;
}

Weapon::~Weapon() {
    ;
}

void Weapon::setType(std::string type) {
    this->type = type;
}
const std::string& Weapon::getType(){
    std::string& ref_type = this->type;
    return ref_type;
}