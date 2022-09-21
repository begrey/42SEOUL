#include "convert.hpp"

convert::convert() {

}

convert::~convert() {

}

void convert::parsing(std::string arg){
    // 끝에 f는 stringstram 파싱이 안되니 제거
    bool decimal_point = false;
    bool nan_inf_flag = false;
    std::string last = arg.substr(arg.length() - 1, arg.length());
    if (last == "f" && arg != "-inf" && arg != "+inf")
        arg = arg.substr(0, arg.length() - 1);
    last = arg.substr(arg.length() - 1, arg.length());
    if (arg.find(".") != std::string::npos && last != "0")
        decimal_point = true;
    if (arg == "-inf" || arg == "+inf" || arg == "nan")
        nan_inf_flag = true;
    std::stringstream doub(arg);
    double double_arg;
    doub >> double_arg;
    print(arg, double_arg, decimal_point, nan_inf_flag);
}

void convert::print(std::string arg, double double_arg, bool decimal_flag, bool nan_inf_flag) {
    to_char(arg, double_arg);
    to_int(arg, double_arg);
    to_float(arg, double_arg, decimal_flag, nan_inf_flag);
    to_double(arg, double_arg, decimal_flag, nan_inf_flag);
}

void convert::to_char(std::string arg, double double_arg){
    char c;
    std::cout << "char: ";
    if (arg.length() == 1 && double_arg == 0 && arg != "0")
        std::cout << arg << std::endl;
    else if (double_arg > 31 && double_arg < 127) {
        c = static_cast<char>(double_arg);
        std::cout << c << std::endl;
    }
    else if ((double_arg >= 1 && double_arg <= 31) || arg == "0" || arg == "0.0") //nan
        std::cout << "Non displayable" << std::endl;
    else 
        std::cout << "impossible" << std::endl;
}
void convert::to_int(std::string arg, double double_arg){
    int i;
    std::cout << "int: ";
    if ((double_arg == 0 && (arg == "0" || arg == "0.0")) || double_arg != 0) {
        if (double_arg >= -2147483648 && double_arg <= 2147483647) {
            i = static_cast<int>(double_arg);
            std::cout << i << std::endl;
        }
        else 
            std::cout << "impossible" << std::endl;
    }
    else 
        std::cout << "impossible" << std::endl;
}
void convert::to_float(std::string arg, double double_arg, bool decimal_flag, bool nan_inf_flag){
    float f = static_cast<float>(double_arg);
    std::cout << "float: ";
    std::string inf_str = std::to_string(f);
    if (inf_str == "inf" || inf_str == "-inf") {
        std::cout << f;
        nan_inf_flag = true;
    }
    else if (arg == "+inf" || arg == "-inf" || arg == "nan") 
        std::cout << arg;
    else if (arg == "0" || double_arg != 0)
        std::cout << f;
    else if (arg == "0.0")
        std::cout << "0";
    else {
        std::cout << "impossible" << std::endl;
        return;
    }
    if (nan_inf_flag == false && (decimal_flag == false || arg == "0.0"))
        std::cout << ".0";
    std::cout << "f" << std::endl;
}
void convert::to_double(std::string arg, double double_arg, bool decimal_flag, bool nan_inf_flag){
    std::cout << "double: ";
    if (arg == "0" || double_arg != 0 || arg == "0.0")
        std::cout << double_arg;
    else { 
        std::cout << "impossible" << std::endl;
        return;
    }
    if (nan_inf_flag == false && (decimal_flag == false || arg == "0.0"))
        std::cout << ".0";
    std::cout << std::endl;
} 