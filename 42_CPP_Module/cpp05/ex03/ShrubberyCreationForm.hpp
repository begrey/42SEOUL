#ifndef _ShrubberyCreationForm_HPP
#define _ShrubberyCreationForm_HPP
#include <iostream>
#include <string>
#include <exception>
#include <fstream>
#include "Form.hpp"

class ShrubberyCreationForm : public Form
{
    private :
        std::string target;
    public :
        ShrubberyCreationForm(std::string target);
        ~ShrubberyCreationForm();
        ShrubberyCreationForm(const ShrubberyCreationForm& origin);
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm& origin);
        std::string getTarget();
        void Action() const;
};

#endif