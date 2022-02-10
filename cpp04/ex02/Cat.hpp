#ifndef CAT_HPP
# define CAT_HPP
# include "AAnimal.hpp"
# include "Brain.hpp"

class Cat : public AAnimal {
private:
	Brain	*brain;
public:
	/* Canonical */
	Cat(void);
	Cat(Cat const & src);
	virtual ~Cat(void);
	Cat &	operator=(Cat const & rhs);

	/* Specific */
	virtual void	makeSound(void) const;
	std::string		getType(void) const;
};

#endif
