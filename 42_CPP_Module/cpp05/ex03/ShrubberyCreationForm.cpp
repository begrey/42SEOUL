#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : 
Form("ShrubberyForm", 145, 137){
    this->target = target;
}
ShrubberyCreationForm::~ShrubberyCreationForm(){
    
}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& origin) :
Form(origin){
    this->target = origin.target;
}
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& origin){
    Form::operator=(origin);
    this->target = origin.target;
    return (*this);
}
std::string ShrubberyCreationForm::getTarget(){
    return this->target;
}
void ShrubberyCreationForm::Action() const{
    std::string file_name = this->target + "_shrubbery";
    std::ofstream ofs(file_name, std::ios::trunc);
	if (ofs.fail())
	{
		std::cerr << "Error!" << std::endl;
	}
    if (ofs.is_open())
    {
        ofs << " •.,¸,.•*`•.,¸¸,.•*¯ ╭━━━━╮ \n"
                "•.,¸,.•*¯`•.,¸,.•*¯.|:::::::::: /___/\n"
                "•.,¸,.•*¯`•.,¸,.•* <|:::::::::(｡ ●ω●｡)\n"
                "•.,¸,.•¯•.,¸,.•╰ * >し------し---Ｊ\n";
        ofs.close();
    }
}
