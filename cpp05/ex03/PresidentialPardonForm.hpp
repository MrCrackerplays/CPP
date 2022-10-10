#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP
# include "Form.hpp"
class PresidentialPardonForm : public Form {
protected:
	const std::string	_target;
public:
	PresidentialPardonForm(const std::string target);
	PresidentialPardonForm(PresidentialPardonForm const & src);

	~PresidentialPardonForm(void);


	virtual bool	execute(Bureaucrat const & executor) const;
private:
	PresidentialPardonForm(void);
	PresidentialPardonForm &	operator=(PresidentialPardonForm const & rhs);
};

#endif
