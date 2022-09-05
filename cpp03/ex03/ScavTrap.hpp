#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP
# include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {
protected:
	bool gate_keeper;
public:
	/* Canonical */
	ScavTrap(ScavTrap const & src);
	~ScavTrap(void);
	ScavTrap &	operator=(ScavTrap const & rhs);

	/* Specific */
	ScavTrap(std::string name);
	void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
	void	guardGate(void);
private:
	ScavTrap(void);
};

#endif
