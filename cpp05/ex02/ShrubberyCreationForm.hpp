#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP
# include "Form.hpp"
class ShrubberyCreationForm : public Form {
protected:
	const std::string	_target;
public:
	ShrubberyCreationForm(const std::string target);
	ShrubberyCreationForm(ShrubberyCreationForm const & src);

	~ShrubberyCreationForm(void);


	virtual bool	execute(Bureaucrat const & executor) const;
private:
	ShrubberyCreationForm(void);
	ShrubberyCreationForm &	operator=(ShrubberyCreationForm const & rhs);
};

#endif
