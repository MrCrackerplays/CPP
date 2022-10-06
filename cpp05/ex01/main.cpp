#include "Bureaucrat.hpp"

int main() {
	Bureaucrat billy = Bureaucrat("billy");
	billy.setGrade(3);
	Form contract = Form("Hedgehog Deal", 2, 1);
	Form agreement = Form(contract);
	std::cout << "contract: " << contract << std::endl;
	std::cout << "agreement: " << agreement << std::endl;
	billy.signForm(contract);
	std::cout << "contract: " << contract << std::endl;
	billy.increaseGrade();
	billy.signForm(contract);
	std::cout << "contract: " << contract << std::endl;
	std::cout << "agreement: " << agreement << std::endl;
	try
	{
		Form test = Form("Exceptional Form", 0, 150);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Form test = Form("Exceptional Form", 1, 151);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}
