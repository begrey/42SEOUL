// ? canonical form 구성요소
// ? [디폴트 생성자] [복사 생성자] [할당 연산자 오버로딩] [소멸자]
#include "Fixed.hpp"
#include <iostream>

int main( void ) {
    Fixed a;
    Fixed b( a );
    Fixed c;
    c = b;
    std::cout << a.getRawBits() << std::endl;
    std::cout << b.getRawBits() << std::endl;
    std::cout << c.getRawBits() << std::endl;
    return 0;
}