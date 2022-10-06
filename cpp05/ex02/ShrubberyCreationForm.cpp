#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : Form("ShrubberyCreationForm", 145, 137), _target(target) {
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & src) : Form("ShrubberyCreationForm", 145, 137), _target(src._target) {
}

ShrubberyCreationForm::~ShrubberyCreationForm(void){
}

bool	ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
	try {
		this->executeCheck(executor);
	} catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
		return (false);
	}
	std::ofstream targetfile;
	targetfile.open(this->_target + "_shrubbery", std::ios::out);
	if (targetfile.is_open()) {
		targetfile <<	"               ,@@@@@@@," << std::endl <<
						"       ,,,.   ,@@@@@@/@@,  .oo8888o." << std::endl <<
						"    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o" << std::endl <<
						"   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'" << std::endl <<
						"   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'" << std::endl <<
						"   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'" << std::endl <<
						"   `&%\\ ` /%&'    |.|        \\ '|8'" << std::endl <<
						"       |o|        | |         | |" << std::endl <<
						"       |.|        | |         | |" << std::endl <<
						"jgs \\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_";
		targetfile.close();
		return (true);
	}
	std::cerr << "Unable to access '" << this->_target << "_shrubbery'" << std::endl;
	return (false);
}
