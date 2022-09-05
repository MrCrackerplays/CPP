#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {
private:
	std::string	name;

	DiamondTrap(void);
public:
	/* Canonical */
	DiamondTrap(DiamondTrap const & src);
	~DiamondTrap(void);
	DiamondTrap &	operator=(DiamondTrap const & rhs);

	/* Specific */
	DiamondTrap(std::string name);
	void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
	void	whoAmI(void);
};

#endif
