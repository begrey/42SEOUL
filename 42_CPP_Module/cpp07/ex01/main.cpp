#include "iter.hpp"

int main() 
{
    int arr1[5] = {1, 2, 3, 4, 5};
    double arr3[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
    std::string arr4[5] = {"hi", "my", "name", "is", "jimkwon"};

    std::cout << std::endl << "-------int-------" << std::endl;
    iter(arr1, 5, &print_element);
    std::cout << std::endl << "-------double-------" << std::endl;
    iter(arr3, 5, &print_element);
    std::cout << std::endl << "-------string-------" << std::endl;
    iter(arr4, 5, &print_element);

}