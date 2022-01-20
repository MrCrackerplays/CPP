#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) : _name(name), _weapon(weapon) {
}

HumanA::~HumanA(void) {
	// std::cout << "HumanA \"" << this->_name << "\" is getting destructed!" << std::endl;
}

void	HumanA::attack(void) {
	std::cout << this->_name << " attacks with his " << this->_weapon.getType() << std::endl;
}
