#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name) : _name(name), _grade(1) {
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
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade = grade;
}

void	Bureaucrat::increaseGrade(void) {
	this->setGrade(this->_grade - 1);
}

void	Bureaucrat::decreaseGrade(void) {
	this->setGrade(this->_grade + 1);
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& b1) {
	out << b1.getName() << ", bureaucrat grade " << b1.getGrade() << ".";
	return (out);
}
