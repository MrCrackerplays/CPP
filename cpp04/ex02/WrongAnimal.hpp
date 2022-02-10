#ifndef WRONG_ANIMAL_HPP
# define WRONG_ANIMAL_HPP
# include <iostream>

class WrongAnimal {
protected:
	std::string	type;

	WrongAnimal(std::string type);
public:
	/* Canonical */
	WrongAnimal(void);
	WrongAnimal(WrongAnimal const & src);
	virtual ~WrongAnimal(void);
	WrongAnimal &	operator=(WrongAnimal const & rhs);

	/* Specific */
	void		makeSound(void) const;
	std::string	getType(void) const;
};

#endif
