#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name) : _name(name), _grade(MAX_GRADE) {
}

Bureaucrat::Bureaucrat(Bureaucrat const & src) : _name(src._name), _grade(src._grade) {
}

Bureaucrat::~Bureaucrat(void) {
}

Bureaucrat &	Bureaucrat::operator=(Bureaucrat const & rhs) {
	if (this == &rhs)
		return (*this);
	this->_grade = rhs._grade;
	return (*this);
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return ("That grade is too high");
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return ("That grade is too low");
}

const std::string	Bureaucrat::getName(void) const {
	return (this->_name);
}

int	Bureaucrat::getGrade(void) const {
	return (this->_grade);
}

void	Bureaucrat::setGrade(int grade) {
	if (grade < MAX_GRADE)
		throw Bureaucrat::GradeTooHighException();
	if (grade > MIN_GRADE)
		throw Bureaucrat::GradeTooLowException();
	this->_grade = grade;
}

void	Bureaucrat::increaseGrade(void) {
	this->setGrade(this->_grade - 1);
}

void	Bureaucrat::decreaseGrade(void) {
	this->setGrade(this->_grade + 1);
}

void	Bureaucrat::signForm(Form& form) const {
	try
	{
		form.beSigned(*this);
		std::cout << this->getName() << " signed " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << this->getName() << " couldn't sign " << form.getName() << " because " << e.what() << "." << std::endl;
	}
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& b1) {
	out << b1.getName() << ", bureaucrat grade " << b1.getGrade() << ".";
	return (out);
}
