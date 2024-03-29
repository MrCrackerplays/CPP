#ifndef HUMANA_HPP
# define HUMANA_HPP
# include "Weapon.hpp"
# include <iostream>

class HumanA
{
private:
	std::string		name;
	Weapon&			_weapon;
public:
	HumanA(std::string name, Weapon& weapon);
	~HumanA(void);

	const std::string&	getWeapon(void);
	void				attack(void);
};

#endif
