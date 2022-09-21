#ifndef INTERN_HPP
#define INTERN_HPP

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

typedef struct s_forms
{
	std::string form_name;
	Form *form;
}	t_forms;

class Intern
{
public:
	Intern();
	Intern(const Intern &sample);
	Intern &operator =(const Intern &sample);
	~Intern();
	Form *makeForm(const std::string &Name_form, const std::string &target);

	class NoForm : public std::exception
	{
	public:
		const char* what() const throw();
	};
};

#endif