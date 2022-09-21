#ifndef _PresidentialPardonForm_HPP
#define _PresidentialPardonForm_HPP
#include <iostream>
#include <string>
#include <exception>
#include "Form.hpp"

class PresidentialPardonForm : public Form 
{
    private :
        std::string target;
    public :
        PresidentialPardonForm(std::string target);
        ~PresidentialPardonForm();
        PresidentialPardonForm(const PresidentialPardonForm& origin);
        PresidentialPardonForm& operator=(const PresidentialPardonForm& origin);
        std::string getTarget();
        void Action() const;
};
#endif