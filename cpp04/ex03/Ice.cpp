#include "Ice.hpp"

Ice::Ice(void) : AMateria("ice") {
}

Ice::Ice(Ice const & src) : AMateria(src) {
}

Ice::~Ice(void) {
}

Ice &	Ice::operator=(Ice const & rhs) {
	if (rhs.type[0] == '\0')
		return (*this);
	return (*this);
}

/* Specific */
AMateria* Ice::clone() const {
	return (new Ice(*this));
}

void Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
