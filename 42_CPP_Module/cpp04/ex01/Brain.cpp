#include "Brain.hpp"

Brain::Brain() {
    std::cout << "<Brain> [Constructor] called" << std::endl;
    for (int i = 0; i < 100; i++) {
        this->ideas[i] = i;
    }
}

Brain::~Brain() {
    std::cout << "<Brain> [Destructor] called" << std::endl;
}