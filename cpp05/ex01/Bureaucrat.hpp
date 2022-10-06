#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <iostream>
# define MAX_GRADE 1
# define MIN_GRADE 150
class Bureaucrat;
# include "Form.hpp"
class Bureaucrat {
protected:
	const std::string	_name;
	int					_grade;
public:
	Bureaucrat(std::string name);
	Bureaucrat(Bureaucrat const & src);

	~Bureaucrat(void);

	Bureaucrat &	operator=(Bureaucrat const & rhs);

	const std::string	getName(void) const;
	int					getGrade(void) const;
	void				setGrade(int grade);
	void				increaseGrade(void);
	void				decreaseGrade(void);
	void				signForm(Form& form) const;

	class GradeTooHighException : public std::exception {
		public:
			const char* what() const throw();
	};
	class GradeTooLowException : public std::exception {
		public:
			const char* what() const throw();
	};
private:
	Bureaucrat(void);
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& b1);

#endif
