#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP
# include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {
public:
	/* Canonical */
	FragTrap(FragTrap const & src);
	~FragTrap(void);
	FragTrap &	operator=(FragTrap const & rhs);

	/* Specific */
	FragTrap(std::string name);
	void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
	void	highFivesGuys(void);
private:
	FragTrap(void);
};

#endif
