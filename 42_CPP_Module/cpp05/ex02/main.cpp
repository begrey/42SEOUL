#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	try
	{
        std::cout << "-------_Action_-------------\n";
		ShrubberyCreationForm sForm("sForm");
        //sForm.Action();

		RobotomyRequestForm rForm("rForm");
		//rForm.Action();

		PresidentialPardonForm pForm("pForm");
		//pForm.Action();

		Bureaucrat b("b", 150);

        std::cout << "-------sign and excute-------------\n";
		sForm.beSigned(b);
		b.signForm(sForm);
		sForm.execute(b);
        std::cout << "-------print sForm information-------------\n";
		std::cout << sForm << '\n';
		pForm.beSigned(b);
		b.executeForm(pForm);
        std::cout << "-------rForm is not signed-------------\n";
        //rForm.beSigned(b);
		rForm.execute(b);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << '\n';
	}
	return 0;
}