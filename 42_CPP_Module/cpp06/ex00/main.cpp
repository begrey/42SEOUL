#include "convert.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Wrong Argument!" << std::endl;
        return 1;
    }
    std::string arg = argv[1];
    convert c;
    c.parsing(arg);
}