#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("default"){
    this->grade = 100;
}
Bureaucrat::Bureaucrat(const std::string _name, int _grade) : name(_name){
    if (_grade < 1)
        throw GradeTooHighException();
    if (_grade > 150)
        throw GradeTooLowException();
    this->grade = _grade;
}
Bureaucrat::~Bureaucrat(){
    // ? 소멸자
}
Bureaucrat::Bureaucrat(const Bureaucrat& origin) : name(origin.name){
    if (origin.grade < 1)
        throw  GradeTooHighException();
    if (origin.grade > 150)
        throw GradeTooLowException();
    this->grade = origin.grade;
}
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& origin){
    if (origin.grade < 1)
        throw  GradeTooHighException();
    if (origin.grade > 150)
        throw GradeTooLowException();
    this->grade = origin.grade;
    return (*this);
}
std::string Bureaucrat::getName() const{
    return this->name;
}
int Bureaucrat::getGrade() const{
    return this->grade;
}

void Bureaucrat::setGrade(int grade){
    if (grade < 1)
        throw  GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
    this->grade = grade;
}
void Bureaucrat::increment(){
    if (grade == 1)
        throw  GradeTooHighException();
    this->grade -= 1;
}
void Bureaucrat::decrement(){
    if (grade == 150)
        throw GradeTooLowException();
    this->grade += 1;
}

std::ostream& operator <<(std::ostream& os, const Bureaucrat& b){
    os << b.getName() << ", bureaucrat grade "  << b.getGrade() << "." << std::endl;
    return os;
}