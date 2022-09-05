#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
# include <iostream>

class ClapTrap {
protected:
	std::string		name;
	unsigned int	hit_points;
	unsigned int	energy_points;
	unsigned int	attack_damage;
public:
	/* Canonical */
	ClapTrap(ClapTrap const & src);
	~ClapTrap(void);
	ClapTrap &	operator=(ClapTrap const & rhs);

	/* Specific */
	ClapTrap(std::string name);
	void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
private:
	ClapTrap(void);
};

#endif