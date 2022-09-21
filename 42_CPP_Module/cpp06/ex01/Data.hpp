#ifndef _DATA_HPP
#define _DATA_HPP
#include <iostream>
#include <string>

typedef struct s_Data
{
	std::string s1;
    int integer;
    std::string s2;
}	t_Data;

uintptr_t serialize(t_Data* ptr) {
    return reinterpret_cast<uintptr_t>(ptr);
}
t_Data* deserialize(uintptr_t raw) {
    return reinterpret_cast<t_Data *>(raw);
}

#endif