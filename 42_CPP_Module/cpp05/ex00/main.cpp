#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat b1("jimkwon", 4);
        // ! 범위는 1 ~ 150
       // Bureaucrat b2("jimkwon_wrong", 0); // ! error
       // Bureaucrat b3("jimkwon_wrong", 151); // ! error
        Bureaucrat b4 = b1;
        Bureaucrat b5("jimkwon2", 1);
        b4.setGrade(150);
       // b4.decrement(); // ! error
       // b5.increment(); // ! error
        b4.increment();
        b5.decrement();
        std::cout << "---------print bureaycrats-----------" << std::endl;
        std::cout << b1 << b4 << b5;
    }
    catch (std::exception & e)
    {
        std::cerr << e.what() << std::endl;
    }
}