#include "HumanB.hpp"

HumanB::HumanB(std::string name) {
	this->_name = name;
}

HumanB::~HumanB(void) {
	// std::cout << "HumanB \"" << this->_name << "\" is getting destructed!" << std::endl;
}

void	HumanB::setWeapon(Weapon& weapon) {
	this->_weapon = &weapon;
}

void	HumanB::attack(void) {
	std::cout << this->_name << " attacks with his " << this->_weapon->getType() << std::endl;
}