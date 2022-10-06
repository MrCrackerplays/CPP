#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
	Bureaucrat billy = Bureaucrat("billy");

	//Form compileerror = Form("SomeForm");


	std::cout << "=======ShrubberyCreationForm=======" << std::endl;
	Form *melon = new ShrubberyCreationForm("watermelon");
	melon->beSigned(billy);
	// billy.setGrade(140);
	billy.executeForm(*melon);


	std::cout << "=======RobotomyRequest=======" << std::endl;
	billy.setGrade(1);
	RobotomyRequestForm cop = RobotomyRequestForm("Robo Cop");
	cop.beSigned(billy);
	// billy.setGrade(50);
	billy.executeForm(cop);


	std::cout << "=======PresidentialPardon=======" << std::endl;
	billy.setGrade(1);
	PresidentialPardonForm apology = PresidentialPardonForm("Brian David Gilbert");
	apology.beSigned(billy);
	// billy.setGrade(10);
	billy.executeForm(apology);
}
