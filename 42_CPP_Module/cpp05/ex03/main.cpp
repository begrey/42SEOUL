#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
	Intern intern;
	Form *form;
	Form *error;
	try
	{
		form = intern.makeForm("presidential pardon", "jimkwon");
		Bureaucrat b("b", 1);
		b.signForm(*form);
		b.executeForm(*form);
		error = intern.makeForm(" error", "jimkwon2");
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << '\n';
	}
	delete form;

	return 0;
}