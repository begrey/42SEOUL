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

        int getRawBits(void) const;

        void setRawBits(int const raw);

        float toFloat(void) const;

        int toInt(void) const;

        ~Fixed();
};

// ? std::ostream&'은 출력 연산자의 return 자료형
// ? 고정 소수값의 실수형 표현을 위해 cout에 해당 출력을 따로 지정해준다
std::ostream &operator<<(std::ostream &out, Fixed const &value);

#endif