#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP
# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
public:
	/* Canonical */
	WrongCat(void);
	WrongCat(WrongCat const & src);
	virtual ~WrongCat(void);
	WrongCat &	operator=(WrongCat const & rhs);

	/* Specific */
	void		makeSound(void) const;
	std::string	getType(void) const;
};

#endif
