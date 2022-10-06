#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <iostream>
class Bureaucrat {
protected:
	const std::string	_name;
	int					_grade;
public:
	/* Canonical */
	Bureaucrat(std::string name);
	Bureaucrat(Bureaucrat const & src);
	~Bureaucrat(void);
	Bureaucrat &	operator=(Bureaucrat const & rhs);

	/* Specific */
	class GradeTooHighException : public std::exception {
		public:
			const char* what() const throw();
	};
	class GradeTooLowException : public std::exception {
		public:
			const char* what() const throw();
	};
	const std::string	getName(void) const;
	int					getGrade(void) const;
	void				setGrade(int grade);
	void				increaseGrade(void);
	void				decreaseGrade(void);
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& b1);

#endif
