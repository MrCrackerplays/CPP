#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include <iostream>

class Animal {
protected:
	std::string	type;

	Animal(std::string type);
public:
	/* Canonical */
	Animal(void);
	Animal(Animal const & src);
	virtual ~Animal(void);
	Animal &	operator=(Animal const & rhs);

	/* Specific */
	virtual void	makeSound(void) const;
	std::string		getType(void) const;
};

#endif
