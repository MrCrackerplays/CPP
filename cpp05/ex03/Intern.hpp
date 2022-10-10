#ifndef INTERN_HPP
# define INTERN_HPP
#include "Form.hpp"
class Intern {
public:
	Intern(void);

	~Intern(void);

	Form *	makeForm(std::string form, std::string target) const;

private:
	Intern(Intern const & copy);
	Intern &	operator=(Intern const & rhs);

	enum formType {
		no_form = -1,
		shrubbery,
		robotomy,
		presidential
	};
	Intern::formType match_form(std::string form) const;
};

#endif
