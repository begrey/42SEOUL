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

bool Fixed::operator==(const Fixed &ref) const{
    return (this->getRawBits() == ref.getRawBits());
}
bool Fixed::operator!=(const Fixed &ref) const{
    return (this->getRawBits() != ref.getRawBits());
}
bool Fixed::operator>=(const Fixed &ref) const{
    return (this->getRawBits() >= ref.getRawBits());
}
bool Fixed::operator<=(const Fixed &ref) const{
    return (this->getRawBits() <= ref.getRawBits());
}
bool Fixed::operator>(const Fixed &ref) const{
    return (this->getRawBits() > ref.getRawBits());
}
bool Fixed::operator<(const Fixed &ref) const{
    return (this->getRawBits() < ref.getRawBits());
}

Fixed Fixed::operator+(const Fixed &ref){
    Fixed result(*this);

    result.setRawBits(this->getRawBits() + ref.getRawBits());
    return (result);
}
Fixed Fixed::operator-(const Fixed &ref){
    Fixed result(*this);

    result.setRawBits(this->getRawBits() - ref.getRawBits());
    return (result);
}
// ! 곱셈과 나눗셈은 비례확대가 일어나기 때문에 고정 소수점 자리 수 만큼 다시 나눠줘야함
// ? ex 1200 + 0460 = 1660 <- 왼쪽으로 두칸  ==   12.00 + 4.6 = 16.60
// ?    1200 * 0470 = 552000 <- 왼쪽으로 두칸 != 12.00 * 4.6 = 55.20
Fixed Fixed::operator*(const Fixed &ref){
    Fixed result(*this);

    float a, b;
    a = (float)this->getRawBits();
    b = (float)ref.getRawBits();
    result.setRawBits((a * b) / (1 << (this->bit_num)));
    return (result);
}
Fixed Fixed::operator/(const Fixed &ref){
    Fixed result(*this);

    float a, b;
    a = (float)this->getRawBits();
    b = (float)ref.getRawBits();
    result.setRawBits((a / b) / (1 << (this->bit_num)));
    result.setRawBits(this->getRawBits() / ref.getRawBits());
    return (result);
}

Fixed& Fixed::operator++() {
    this->rawBits++;
    return *this;
}
Fixed& Fixed::operator--() {
    this->rawBits--;
    return *this;
}
//? 후위연산자!
Fixed Fixed::operator++(int) {
    Fixed temp(*this);
    this->rawBits++;
    return temp;
}
Fixed Fixed::operator--(int) {
    Fixed temp(*this);
    this->rawBits--;
    return temp;
}

Fixed &Fixed::max(Fixed &A, Fixed &B){
    if (A > B)
        return A;
    return B;
}
Fixed const &Fixed::max(Fixed const &A, const Fixed &B){
    if (A > B)
        return A;
    return B;
}
Fixed &Fixed::min(Fixed &A, Fixed &B){
    if (A > B)
        return A;
    return B;
}
Fixed const &Fixed::min(const Fixed &A, const Fixed &B){
    if (A > B)
        return A;
    return B;
}