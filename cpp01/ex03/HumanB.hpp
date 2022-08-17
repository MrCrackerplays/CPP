#ifndef HUMANB_HPP
# define HUMANB_HPP
# include "Weapon.hpp"
# include <iostream>

class HumanB
{
private:
	std::string		name;
	Weapon			*_weapon;
public:
	HumanB(std::string name);
	~HumanB(void);

	const std::string&	getWeapon(void);
	void				setWeapon(Weapon& weapon);
	void				attack(void);
};

#endif
