#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try
    {
        Bureaucrat b1("jimkwon", 42);
        // ! 범위는 1 ~ 150
        Form f1("wrong form", 41, 41);
        Form f2("jimkwon's form", 43, 43);
        //f1.beSigned(b1);
        b1.signForm(f1);
        b1.signForm(f2);
        //f2.beSigned(b1);
        std::cout << "---------print Form-----------" << std::endl;
        std::cout << f1 << std::endl;
        std::cout << f2 << std::endl;
    }
    catch (std::exception & e)
    {
        std::cerr << e.what() << std::endl;
    }
}