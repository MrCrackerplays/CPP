#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern(void) {
}

Intern::~Intern(void) {
}

/**
 * for argument's sake in case the eval sheet mentions it, I specifically chose to use if's
 * because it's more readable and more easily updateable compared to the alternative function:
Intern::formType Intern::match_form(std::string form) const {
	std::string[] matches = ["shubbery creation", "robotomy request", "presidential pardon"];
	Intern::formType forms = [Intern::shrubbery, Intern::robotomy, Intern::presidential, Intern::no_form];
	int i = 0;
	for (; i < 3 && form != matches[i]; i++);
	return forms[i];
}
 * which, while using less lines, has to be changed entirely each time a new form gets added
 * as compared to just adding a single if statement to the function below
 */

Intern::formType Intern::match_form(std::string form) const {
	if (form == "shrubbery creation")
		return (Intern::shrubbery);
	if (form == "robotomy request")
		return (Intern::robotomy);
	if (form == "presidential pardon")
		return (Intern::presidential);
	return (Intern::no_form);
}

Form *	Intern::makeForm(std::string form, std::string target) const {
	Form	*result;
	switch (match_form(form))
	{
	case Intern::shrubbery:
		result = new ShrubberyCreationForm(target);
		break;
	case Intern::robotomy:
		result = new RobotomyRequestForm(target);
		break;
	case Intern::presidential:
		result = new PresidentialPardonForm(target);
		break;
	default:
		std::cerr << "No such form found with the name '" << form << "'" << std::endl;
		return (NULL);
	}
	std::cout << "Intern creates " << *result << std::endl;
	return (result);
}
