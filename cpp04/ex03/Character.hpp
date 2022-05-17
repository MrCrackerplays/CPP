#ifndef CHARACTER_HPP
# define CHARACTER_HPP
class Character;
# include "ICharacter.hpp"

class Character : public ICharacter {
protected:
	AMateria*	inventory[4];
	std::string	name;
public:
	/* Canonical */
	Character(std::string name);
	Character(Character const & src);
	virtual ~Character(void);
	Character &	operator=(Character const & rhs);

	/* Specific */
	virtual std::string const & getName() const;
	virtual void equip(AMateria* m);
	virtual void unequip(int idx);
	virtual void use(int idx, ICharacter& target);
};

#endif
