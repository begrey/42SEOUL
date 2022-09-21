#ifndef _Fixed_HPP
#define _Fixed_HPP
#include <iostream>

class Fixed {
    private :

        int rawBits;
        static const int bit_num = 8;

    public :

        Fixed();

        Fixed(const Fixed& origin);

        Fixed& operator=(const Fixed &ref);

        int getRawBits(void) const;

        void setRawBits(int const raw);

        ~Fixed();
};

#endif