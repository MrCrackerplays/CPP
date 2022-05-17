#ifndef MATERIALSOURCE_HPP
# define MATERIALSOURCE_HPP
class MateriaSource;
# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
protected:
	AMateria*	knowledge[4];
public:
	/* Canonical */
	MateriaSource(void);
	MateriaSource(MateriaSource const & src);
	virtual ~MateriaSource(void);
	MateriaSource &	operator=(MateriaSource const & rhs);

	/* Specific */
	virtual void learnMateria(AMateria*);
	virtual AMateria* createMateria(std::string const & type);
};

#endif
