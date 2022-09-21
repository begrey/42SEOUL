#ifndef _Form_HPP
#define _Form_HPP
#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    private:
        const std::string name;
        bool is_signed;
        const int grade_to_sign;
        const int grade_to_execute;

    public:
        Form();
        Form(std::string const name, int const grade_to_sign, int const grade_to_execute);
        ~Form();
        Form(const Form& origin);
        Form& operator=(const Form& origin);
        std::string getName() const;
        int getIsSigned() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;
        void beSigned(const Bureaucrat &b); // ? bereaucrat 의 점수가 적절하면 signed
        //? 사용자 정의 예외문
        class GradeTooHighException : public std::exception
        {
            public:
                const char * what() const throw()  //? noexcept overide 는 c++11 이상 컴파일러
                {
                    return "Grade is too high";
                }
        };

        class GradeTooLowException : public std::exception
        {
            public:
                const char * what() const throw()
                {
                    return "Grade is too low";
                }
        };
};



std::ostream& operator <<(std::ostream& os, const Form& f);

#endif