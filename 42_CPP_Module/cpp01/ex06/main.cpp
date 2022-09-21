#include "Karen.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "FORMAT : ./karenFilter \" level \"";
        exit(1);
    }
    Karen k;
    std::string option = argv[1];
    k.complain(option);
    return 0;
}