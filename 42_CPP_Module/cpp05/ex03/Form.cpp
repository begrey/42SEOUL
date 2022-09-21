#include "Form.hpp"

    //! 멤버 이니셜라이저 문법 필요! : const 멤버 변수를 초기화 시키기 위함
    Form::Form() : name("default"), is_signed(false), grade_to_sign(50), grade_to_execute(50){

    }
    Form::Form(std::string const _name, int const _grade_to_sign, int const _grade_to_execute) :
    name(_name), grade_to_sign(_grade_to_sign), grade_to_execute(_grade_to_execute){
        if (_grade_to_sign < 1 || _grade_to_execute < 1)
            throw GradeTooHighException();
        if (_grade_to_sign > 150 || _grade_to_execute > 150)
            throw GradeTooLowException();
        this->is_signed = false;
    }
    Form::~Form(){
        
    }
    Form::Form(const Form& origin) :
    name(origin.name), grade_to_sign(origin.grade_to_sign), grade_to_execute(origin.grade_to_execute){
        this->is_signed = origin.is_signed;
    }
    Form& Form::operator=(const Form& origin){
        this->is_signed = origin.is_signed;
        return (*this);
    }
    std::string Form::getName() const{
        return this->name;
    }
    int Form::getIsSigned() const{
        return this->is_signed;
    }
    int Form::getGradeToSign() const{
        return this->grade_to_sign;
    }
    int Form::getGradeToExecute() const{
        return this->grade_to_execute;
    }
    void Form::beSigned(const Bureaucrat &b){
        if (b.getGrade() <= this->getGradeToSign())
            this->is_signed = true;
        else 
            throw Form::GradeTooLowException();
    }
    std::ostream& operator <<(std::ostream& os, const Form& f){
        os << "[NAME] : "  << f.getName() 
        << "\n[is_signed] : "<< f.getIsSigned() 
        << "\n[Grade_to_sign] : " << f.getGradeToSign() 
        << "\n[Grade_to_execute] : " << f.getGradeToExecute() << std::endl;
        return os;
    }
    void Form::execute(Bureaucrat const & executor) const {
        if (this->is_signed == false)
		    throw Form::IsFormSigned();
        if (executor.getGrade() > this->getGradeToExecute())
            throw Form::GradeTooLowException();
        this->Action();
    }