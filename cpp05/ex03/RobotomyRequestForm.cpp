#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string target) : Form("RobotomyRequestForm", 72, 45), _target(target) {
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & src) : Form("RobotomyRequestForm", 72, 45), _target(src._target) {
}

RobotomyRequestForm::~RobotomyRequestForm(void){
}

bool	RobotomyRequestForm::execute(Bureaucrat const & executor) const {
	try {
		this->executeCheck(executor);
	} catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
		return (false);
	}
	std::cout << "**SOME DRILLING NOISES**" << std::endl;
	std::srand(std::time(NULL));
	int random_variable = std::rand();
	if (random_variable % 2 == 0)
		std::cout << this->_target << " has been successfully robotomized." << std::endl;
	else
		std::cout << this->_target << "'s robotomy has failed." << std::endl;
	return (true);
}
