#include "Data.hpp"

int main()
{
    std::cout << "--------------------------------------------" << std::endl;
    std::cout << "size of string : " << sizeof(std::string) << std::endl;
    std::cout << "size of int : " << sizeof(int) << std::endl;

    t_Data data = {"jimkwon", 42, "42seoul"};

    uintptr_t ptr = serialize(&data);
    t_Data *data_ptr = deserialize(ptr);

    std::cout << "----------data origin------------" << std::endl;
    std::cout << "s1 : " << data.s1 << std::endl;
    std::cout << "integer : " << data.integer << std::endl;
    std::cout << "s2 : " << data.s2 << std::endl;
    std::cout << "----------after selialize and deserialize------------" << std::endl;
    std::cout << "s1 : " << data_ptr->s1 << std::endl;
    std::cout << "integer : " << data_ptr->integer << std::endl;
    std::cout << "s2 : " << data_ptr->s2 << std::endl;

}