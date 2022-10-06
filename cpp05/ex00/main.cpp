#include "Bureaucrat.hpp"

int main() {
	Bureaucrat billy = Bureaucrat("billy");
	Bureaucrat steve = Bureaucrat(billy);
	std::cout << "steve: " << steve << std::endl;
	std::cout << "billy: " << billy << std::endl;
	billy.setGrade(2);
	billy.decreaseGrade();
	std::cout << "steve: " << steve << std::endl;
	std::cout << "billy: " << billy << std::endl;
	try
	{
		billy.increaseGrade();
	}
	catch(Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << e.what() << '\n';
	}
	billy.setGrade(149);
	billy.decreaseGrade();
	std::cout << "billy: " << billy << std::endl;
	try
	{
		billy.decreaseGrade();
	}
	catch(Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << e.what() << '\n';
	}
}
