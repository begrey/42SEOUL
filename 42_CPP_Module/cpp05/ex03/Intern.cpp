#include "Intern.hpp"

Intern::Intern()
{}

Intern::Intern(const Intern &origin)
{
	(void)origin;
}

Intern &Intern::operator=(const Intern &origin)
{
	(void)origin;
	return *this;
}

Intern::~Intern()
{}

const char *Intern::NoForm::what() const throw()
{
	return "Can't find Form";
}



Form *Intern::makeForm(const std::string &form_name, const std::string &target)
{
	Form *form = NULL;
	t_forms arr_forms[3] = {
			{"presidential pardon", new PresidentialPardonForm(target)},
			{"robotomy request", new RobotomyRequestForm(target)},
			{"shrubbery creation", new ShrubberyCreationForm(target)}
	};
	for (int i = 0; i < 3; i++)
	{
		if (arr_forms[i].form_name == form_name)
		{
			form = arr_forms[i].form;
			std::cout << "Intern creates " << form->getName() << '\n';
			for (int i = 0; i < 3; i++) {
				if (arr_forms[i].form_name != form_name)
					delete arr_forms[i].form;
			}
			return form;
		}
	}
	for (int i = 0; i < 3; i++) {
		delete arr_forms[i].form;
	}
	throw Intern::NoForm();
}