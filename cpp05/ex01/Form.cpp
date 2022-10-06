#include "Form.hpp"

Form::Form(std::string name, int sign_grade, int execute_grade) : _name(name), _sign(false), _sign_grade(sign_grade), _execute_grade(execute_grade) {
	if (sign_grade < MAX_GRADE)
		throw GradeTooHighException();
	if (sign_grade > MIN_GRADE)
		throw GradeTooLowException();
	if (execute_grade < MAX_GRADE)
		throw GradeTooHighException();
	if (execute_grade > MIN_GRADE)
		throw GradeTooLowException();
}

Form::Form(Form const & src) : _name(src._name), _sign(src._sign), _sign_grade(src._sign_grade), _execute_grade(src._execute_grade) {
	if (src._sign_grade < MAX_GRADE)
		throw GradeTooHighException();
	if (src._sign_grade > MIN_GRADE)
		throw GradeTooLowException();
	if (src._execute_grade < MAX_GRADE)
		throw GradeTooHighException();
	if (src._execute_grade > MIN_GRADE)
		throw GradeTooLowException();
}

Form::~Form(void) {
}

Form &	Form::operator=(Form const & rhs) {
	if (this == &rhs)
		return (*this);
	this->_sign = rhs._sign;
	return (*this);
}

/* Specific */
const char* Form::GradeTooHighException::what() const throw() {
	return ("That grade is too high");
}
const char* Form::GradeTooLowException::what() const throw() {
	return ("That grade is too low");
}

const std::string	Form::getName(void) const {
	return (this->_name);
}

int	Form::getSignGrade(void) const {
	return (this->_sign_grade);
}

int	Form::getExecuteGrade(void) const {
	return (this->_execute_grade);
}

bool	Form::isSigned(void) const {
	return (this->_sign);
}

void	Form::beSigned(const Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() <= this->_sign_grade)
		this->_sign = true;
	else
		throw Form::GradeTooLowException();
}

std::ostream& operator<<(std::ostream& out, const Form& f1) {
	out << f1.getName() << ", signed " << f1.isSigned() << ", sign grade " << f1.getSignGrade() << ", execute grade " << f1.getExecuteGrade() << ".";
	return (out);
}
