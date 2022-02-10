#ifndef AANIMAL_HPP
# define AANIMAL_HPP
# include <iostream>

class AAnimal {
protected:
	std::string	type;

	AAnimal(std::string type);
public:
	/* Canonical */
	AAnimal(void);
	AAnimal(AAnimal const & src);
	virtual ~AAnimal(void);
	AAnimal &	operator=(AAnimal const & rhs);

	/* Specific */
	virtual void	makeSound(void) const = 0;
	std::string		getType(void) const;
};

#endif
