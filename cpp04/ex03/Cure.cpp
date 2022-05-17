#include "Cure.hpp"

Cure::Cure(void) : AMateria("cure") {
}

Cure::Cure(Cure const & src) : AMateria(src) {
}

Cure::~Cure(void) {
}

Cure &	Cure::operator=(Cure const & rhs) {
	if (rhs.type[0] == '\0')
		return (*this);
	return (*this);
}

/* Specific */
AMateria* Cure::clone() const {
	return (new Cure(*this));
}

void Cure::use(ICharacter& target) {
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
