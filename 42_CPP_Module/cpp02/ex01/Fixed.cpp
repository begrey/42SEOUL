#include "Fixed.hpp"

Fixed::Fixed() {
    std::cout << "Default constructor called" << std::endl; 
    this->rawBits = 0;
}

Fixed::Fixed(const int rawBits) {
    std::cout << "Int constructor called" << std::endl;
    this->rawBits = rawBits <<(this->bit_num);
}
// ? 반올림 함수의 경우, float는 roundf
Fixed::Fixed(const float rawBits) {
    std::cout << "Float constructor called" << std::endl;
    this->rawBits = roundf(rawBits * (1 << (this->bit_num)));
}

Fixed::Fixed(const Fixed& origin) {
    std::cout << "Copy constructor called" << std::endl; 
    //*this = origin;
    this->rawBits = origin.getRawBits();
}

Fixed& Fixed::operator=(const Fixed &ref) {
    std::cout << "Assignation operator called" << std::endl; 
    this->rawBits = ref.getRawBits();
    return (*this);  
}

int Fixed::getRawBits(void) const{
    //std::cout << "getRawBits member function called" << std::endl; 
    return this->rawBits;
}

void Fixed::setRawBits(int const raw){
    std::cout << "setRawBits member function called" << std::endl; 
    this->rawBits = raw;
}

float Fixed::toFloat(void) const {
    return ((float)this->rawBits / (1 << (this->bit_num)));
}

int Fixed::toInt(void) const {
    return (this->rawBits >> (this->bit_num));
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl; 
}

std::ostream &operator<<(std::ostream &out, Fixed const &value) {
    out << value.toFloat();
    return out;
}