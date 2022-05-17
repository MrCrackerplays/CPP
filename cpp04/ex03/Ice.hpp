#ifndef ICE_HPP
# define ICE_HPP
class Ice;
# include "AMateria.hpp"

class Ice : public AMateria {
public:
	/* Canonical */
	Ice(void);
	Ice(Ice const & src);
	virtual ~Ice(void);
	Ice &	operator=(Ice const & rhs);

	/* Specific */
	virtual AMateria* clone() const;
	virtual void use(ICharacter& target);
};

#endif
