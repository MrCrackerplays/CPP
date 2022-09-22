#ifndef AMATERIA_HPP
# define AMATERIA_HPP
class AMateria;
# include "ICharacter.hpp"

class AMateria {
protected:
	const std::string	type;
public:
	AMateria(std::string const & type);
	/* Canonical */
	AMateria(AMateria const & src);
	virtual ~AMateria(void);
	AMateria &	operator=(AMateria const & rhs);

	/* Specific */
	std::string const & getType() const;

	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
private:
	AMateria(void);
};

#endif
