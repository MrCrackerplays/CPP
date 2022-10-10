#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main() {
	Bureaucrat billy = Bureaucrat("billy");
	Intern intern;

	//Form compileerror = Form("SomeForm");


	std::cout << "=======ShrubberyCreationForm=======" << std::endl;
	Form *melon = intern.makeForm("shrubbery creation", "watermelon");
	if (melon) {
		billy.signForm(*melon);
		// billy.setGrade(140);
		billy.executeForm(*melon);
		delete melon;
	}


	std::cout << "=======RobotomyRequest=======" << std::endl;
	billy.setGrade(1);
	Form *cop = intern.makeForm("robotomy request", "Robo Cop");
	if (cop) {
		billy.signForm(*cop);
		// billy.setGrade(50);
		billy.executeForm(*cop);
		delete cop;
	}


	std::cout << "=======PresidentialPardon=======" << std::endl;
	billy.setGrade(1);
	Form *apology = intern.makeForm("presidential pardon", "Brian David Gilbert");
	if (apology) {
		billy.signForm(*apology);
		// billy.setGrade(10);
		billy.executeForm(*apology);
		delete apology;
	}


	std::cout << "=======No Such Form=======" << std::endl;
	Form *unknown = intern.makeForm("this form doesn't exist", "something");
	std::cout << unknown << std::endl;
	if (unknown)
		delete unknown;
}
