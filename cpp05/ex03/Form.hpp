#ifndef FORM_HPP
# define FORM_HPP
class Form;
# include "Bureaucrat.hpp"
class Form {
private:
	const std::string	_name;
	bool				_sign;
	const int			_sign_grade;
	const int			_execute_grade;
public:
	Form(std::string name, int sign_grade, int execute_grade);
	Form(Form const & src);

	virtual ~Form(void);

	Form &	operator=(Form const & rhs);

	const std::string	getName(void) const;
	int					getSignGrade(void) const;
	int					getExecuteGrade(void) const;
	bool				isSigned(void) const;
	void				beSigned(const Bureaucrat& bureaucrat);
	virtual bool		execute(Bureaucrat const & executor) const = 0;
	void				executeCheck(Bureaucrat const & executor) const;

	class GradeTooHighException : public std::exception {
		public:
			const char* what() const throw();
	};
	class GradeTooLowException : public std::exception {
		public:
			const char* what() const throw();
	};
	class NotSignedException : public std::exception {
		public:
			const char* what() const throw();
	};
private:
	Form(void);
};

std::ostream& operator<<(std::ostream& out, const Form& b1);

#endif
