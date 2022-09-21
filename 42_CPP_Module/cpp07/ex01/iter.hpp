#ifndef _ITER_HPP
#define _ITER_HPP
#include <iostream>
#include <string>

template <typename T>
void iter(T const *arr, size_t length, void(*f)(T const &element)){
    std::cout << arr << std::endl;
    for (size_t i = 0; i < length; i++) {
        (*f)(arr[i]);
    }
}

template <typename T>
void print_element(T const &element) {
    std::cout << element << " ";
}



#endif