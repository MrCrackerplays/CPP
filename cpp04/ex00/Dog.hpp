#ifndef DOG_HPP
# define DOG_HPP
# include "Animal.hpp"

class Dog : public Animal {
public:
	/* Canonical */
	Dog(void);
	Dog(Dog const & src);
	virtual ~Dog(void);
	Dog &	operator=(Dog const & rhs);

	/* Specific */
	virtual void	makeSound(void) const;
	std::string		getType(void) const;
};

#endif
