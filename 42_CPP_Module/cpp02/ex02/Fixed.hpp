#ifndef _Fixed_HPP
#define _Fixed_HPP
#include <iostream>
#include <cmath>

class Fixed {
    private :

        int rawBits;
        static const int bit_num = 8;

    public :

        Fixed();

        Fixed(const int rawBits);

        Fixed(const float rawBits);

        Fixed(const Fixed& origin);

        Fixed& operator=(const Fixed &ref);

        bool operator==(const Fixed &ref) const;
        bool operator!=(const Fixed &ref) const;
        bool operator>=(const Fixed &ref) const;
        bool operator<=(const Fixed &ref) const;
        bool operator>(const Fixed &ref) const;
        bool operator<(const Fixed &ref) const;

        Fixed operator+(const Fixed &ref);
        Fixed operator-(const Fixed &ref);
        Fixed operator*(const Fixed &ref);
        Fixed operator/(const Fixed &ref);

        //? 전위
        Fixed& operator++();
        Fixed& operator--();
        //? 후위 : 단순히 구분을 위해 int를 넣는당
        Fixed operator++(int);
        Fixed operator--(int);

        int getRawBits(void) const;

        void setRawBits(int const raw);

        float toFloat(void) const;

        int toInt(void) const;

        // ? static으로 선언하는 이유는, 객체를 통해 접근하지 않고, 단순 클래스 이름으로만 
        // ? 해당 함수를 접근가능!  Fixed aa 후 aa.max가 아닌 Fixed::max 가능
        static Fixed &max(Fixed &A, Fixed &B);
        static Fixed const &max(const Fixed &A, const Fixed &B);
        static Fixed &min(Fixed &A, Fixed &B);
        static Fixed const &min(const Fixed &A, const Fixed &B);

        ~Fixed();
};

// ? std::ostream&'은 출력 연산자의 return 자료형
// ? 고정 소수값의 실수형 표현을 위해 cout에 해당 출력을 따로 지정해준다
std::ostream &operator<<(std::ostream &out, Fixed const &value);

#endif