// ? canonical form 구성요소
// ? [디폴트 생성자] [복사 생성자] [할당 연산자 오버로딩] [소멸자]
#include "Fixed.hpp"
#include <iostream>
// * [0000 0000] 소수 부
int main( void ) {
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << Fixed::max( a, b ) << std::endl;
    return 0;
}