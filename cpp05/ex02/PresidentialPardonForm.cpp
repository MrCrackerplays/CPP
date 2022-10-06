#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string target) : Form("PresidentialPardonForm", 25, 5), _target(target) {
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & src) : Form("PresidentialPardonForm", 25, 5), _target(src._target) {
}

PresidentialPardonForm::~PresidentialPardonForm(void){
}

bool	PresidentialPardonForm::execute(Bureaucrat const & executor) const {
	try {
		this->executeCheck(executor);
	} catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
		return (false);
	}
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
	return (true);
}
