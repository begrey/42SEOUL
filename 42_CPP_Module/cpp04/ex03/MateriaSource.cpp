#include "MateriaSource.hpp"

MateriaSource::MateriaSource(){
    for (int i = 0; i < 4; i++)
        this->temp[i] = NULL;
}
MateriaSource::~MateriaSource(){
    for (int i = 0; i < 4; i++)
		if (this->temp[i] != NULL)
			delete this->temp[i];
}
void MateriaSource::learnMateria(AMateria* m){
    int i;
    for (i = 0; i < 4; i++) {
        if (this->temp[i] == NULL && m != NULL)
            break;
    }
    if (i >= 0 && i < 4)
        this->temp[i] = m;
}
AMateria* MateriaSource::createMateria(std::string const & type){
    for (int i = 0; i < 4; i++)
		if (this->temp[i] != NULL && this->temp[i]->getType() == type)
			return (this->temp[i]->clone());
    return 0;
}