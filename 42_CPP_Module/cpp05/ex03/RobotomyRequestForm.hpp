#ifndef _RobotomyRequestForm_HPP
#define _RobotomyRequestForm_HPP
#include <iostream>
#include <string>
#include <exception>
#include <cstdlib>
#include <ctime>
#include "Form.hpp"

class RobotomyRequestForm : public Form 
{
    private :
        std::string target;
    public :
        RobotomyRequestForm(std::string target);
        ~RobotomyRequestForm();
        RobotomyRequestForm(const RobotomyRequestForm& origin);
        RobotomyRequestForm& operator=(const RobotomyRequestForm& origin);
        std::string getTarget();
        void Action() const;
};
#endif