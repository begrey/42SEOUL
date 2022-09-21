#include "RobotomyRequestForm.hpp"

    RobotomyRequestForm::RobotomyRequestForm(std::string target) :
    Form("RobotomyRequestForm", 72, 45){
        this->target = target;
    }
    RobotomyRequestForm::~RobotomyRequestForm(){
        
    }
    RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& origin) :
    Form(origin){
        this->target = origin.target;
    }
    RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& origin){
        Form::operator=(origin);
        this->target = origin.target;
        return (*this);
    }
    std::string RobotomyRequestForm::getTarget(){
        return this->target;
    }
    void RobotomyRequestForm::Action() const{
        std::cout << "Drrrrrr...!!!!!\n";
        srand(time(NULL));
        int a = rand() % 10; // ? 0 ~ 9까지 난수 생성
        if (a < 5)
            std::cout << this->target << " has been robotomized successfully 50% of the time\n";
        else
            std::cout << "It’s a failure\n";
    }