#include "AMateria.hpp"

AMateria::AMateria(std::string const & type) : type(type) {
}

AMateria::AMateria(AMateria const & src) : type(src.type) {
}

AMateria::~AMateria(void) {
}

AMateria &	AMateria::operator=(AMateria const & rhs) {
	//subject says type shouldn't be assigned and materia doesn't have any other member variables
	if (rhs.type[0] == '\0')
		return (*this);
	return (*this);
}

std::string const & AMateria::getType() const {
	return (this->type);
}

void AMateria::use(ICharacter& target) {
	std::cout << "* is used on " << target.getName() << " *" << std::endl;
}
