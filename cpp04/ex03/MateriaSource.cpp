#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

MateriaSource::MateriaSource(void) {
	this->knowledge[0] = NULL;
	this->knowledge[1] = NULL;
	this->knowledge[2] = NULL;
	this->knowledge[3] = NULL;
}

MateriaSource::MateriaSource(MateriaSource const & src) {
	for (int i = 0; i < 4; i++)
		if (src.knowledge[i] != NULL)
			this->knowledge[i] = src.knowledge[i]->clone();
}

MateriaSource::~MateriaSource(void) {
	for (int i = 0; i < 4; i++) {
		if (this->knowledge[i] != NULL)
			delete this->knowledge[i];
	}
}

MateriaSource &	MateriaSource::operator=(MateriaSource const & rhs) {
	void	*ptr = NULL;
	if (this == ptr) {
		rhs.~MateriaSource();
		return (*((MateriaSource*)ptr));
	}
	return (*this);
}

void MateriaSource::learnMateria(AMateria* m) {
	for (int i = 0; i < 4; i++) {
		if (this->knowledge[i] != NULL)
			continue ;
		this->knowledge[i] = m->clone();
		break ;
	}
}

AMateria* MateriaSource::createMateria(std::string const & type) {
	for (int i = 0; i < 4; i++) {
		if (this->knowledge[i] && this->knowledge[i]->getType().compare(type) == 0)
			return (this->knowledge[i]->clone());
	}
	return (0);
}
