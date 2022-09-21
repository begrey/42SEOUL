#include "PresidentialPardonForm.hpp"

    PresidentialPardonForm::PresidentialPardonForm(std::string target) :
    Form("PresidentialPardonForm", 25, 5){
        this->target = target;
    }
    PresidentialPardonForm::~PresidentialPardonForm(){
        
    }
    PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& origin) : 
    Form(origin){
        this->target = origin.target;
    }
    PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& origin){
        Form::operator=(origin);
        this->target = origin.target;
        return (*this);
    }
    std::string PresidentialPardonForm::getTarget(){
        return this->target;
    }
    void PresidentialPardonForm::Action() const{
        std::cout << this->target << " has been pardoned by Zafod Beeblebrox\n";
    }