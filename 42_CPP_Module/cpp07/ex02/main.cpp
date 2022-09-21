#include "Array.hpp"

template <typename T>
void print(Array <T>arr, size_t len) {
    for (size_t i = 0; i < len; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}

int main()
{
    Array <int>arr1;
    Array <int>arr2(5);
    Array <int>arr3(5); 
    Array <int>arr4(arr2); // ? 복사 생성자
    arr3 = arr2; // ? 대입 연산자
    arr2[0] = 42;
    std::cout << "--------origin arr---------" << std::endl;
    print(arr2, 5);
    std::cout << "--------copy arr---------" << std::endl;
    print(arr4, 5);
    std::cout << "--------copy operator arr---------" << std::endl;
    print(arr3, 5);
    std::cout << "-------size--------" << std::endl;
    std::cout << "arr2 size : " << arr2.size() << std::endl;
    std::cout << "arr3 size : " << arr2.size() << std::endl;
    std::cout << "arr4 size : " << arr2.size() << std::endl;
    try {
        std::cout << arr2[0] << std::endl;
        std::cout << arr2[arr2.size()];
        //std::cout << arr2[-1];
    } catch(std::exception &e) {
        std::cout << e.what() << std::endl;
    } 
}