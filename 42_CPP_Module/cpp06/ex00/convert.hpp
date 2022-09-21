#ifndef _CONVERT_HPP
#define _CONVERT_HPP
#include <iostream>
#include <string>
#include <sstream>

class convert {
    public :
        convert();
        ~convert();
        void parsing(std::string arg);
        void print(std::string arg, double double_arg, bool decimal_flag, bool nan_inf_flag);
        void to_char(std::string arg, double double_arg);
        void to_int(std::string arg, double double_arg);
        void to_float(std::string arg, double double_arg, bool decimal_flag, bool nan_inf_flag);
        void to_double(std::string arg, double double_arg, bool decimal_flag, bool nan_inf_flag);
};

#endif