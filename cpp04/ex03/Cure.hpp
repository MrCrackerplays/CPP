#ifndef CURE_HPP
# define CURE_HPP
class Cure;
# include "AMateria.hpp"

class Cure : public AMateria {
public:
	/* Canonical */
	Cure(void);
	Cure(Cure const & src);
	virtual ~Cure(void);
	Cure &	operator=(Cure const & rhs);

	/* Specific */
	virtual AMateria* clone() const;
	virtual void use(ICharacter& target);
};

#endif
