#include "Fixed.hpp"

Fixed::Fixed() {
    std::cout << "Default constructor called" << std::endl; 
    this->rawBits = 0;
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
// !이 함수 안에서는 어떤 변수도 바꿀 수 없음  >> 뒤에 const(상수화)가 붙어있기 때문
// ? 또한 const가 붙은 함수 내에서는 const가 붙은 다른 함수를 제외한 일반 함수는 호출하지 못한다.
int Fixed::getRawBits(void) const{
    std::cout << "getRawBits member function called" << std::endl; 
    return this->rawBits;
}

void Fixed::setRawBits(int const raw){
    std::cout << "setRawBits member function called" << std::endl; 
    this->rawBits = raw;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl; 
}