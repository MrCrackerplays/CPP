#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name(name), _weapon(NULL) {
}

HumanB::~HumanB(void) {
	// std::cout << "HumanB \"" << this->name << "\" is getting destructed!" << std::endl;
}

void	HumanB::setWeapon(Weapon& weapon) {
	this->_weapon = &weapon;
}

void	HumanB::attack(void) {
	std::cout << this->name << " attacks with his " << this->_weapon->getType() << std::endl;
}
