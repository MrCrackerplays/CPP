#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP
# include "Form.hpp"
class RobotomyRequestForm : public Form {
protected:
	const std::string	_target;
public:
	RobotomyRequestForm(const std::string target);
	RobotomyRequestForm(RobotomyRequestForm const & src);

	~RobotomyRequestForm(void);


	virtual bool	execute(Bureaucrat const & executor) const;
private:
	RobotomyRequestForm(void);
	RobotomyRequestForm &	operator=(RobotomyRequestForm const & rhs);
};

#endif
