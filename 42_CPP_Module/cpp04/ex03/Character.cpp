#include "Character.hpp"

Character::Character(std::string Name){
    this->Name = Name;
    for (int i = 0; i < 4; i++) {
        this->inventory[i] = NULL;
    }
}
Character::Character(const Character &origin){
    this->Name = origin.Name;
    for (int i = 0; i < 4; i++) {
        this->inventory[i] = NULL;
    }
}
Character &Character::operator=(const Character &origin){
    this->Name = origin.Name;
    for (int i = 0; i < 4; i++) {
        this->inventory[i] = NULL;
    }
    return (*this);
}
Character::~Character() {
    for (int i = 0; i < 4; i++)
		if (this->inventory[i])
			delete this->inventory[i];
}
std::string const & Character::getName() const{
    return this->Name;
}
void Character::equip(AMateria* m){
    int i;

    for (i = 0; i < 4; i++) {
        if (this->inventory[i] == NULL && m != NULL)
            break ;
    }
    if (i >= 0 && i < 4)
        this->inventory[i] = m;
}
void Character::unequip(int idx){
    if (this->inventory[idx] != NULL && (idx >= 0 && idx < 4))
        this->inventory[idx] = NULL;
}
void Character::use(int idx, ICharacter& target){
    if (this->inventory[idx] != NULL && (idx >= 0 && idx < 4))
        this->inventory[idx]->use(target);
}