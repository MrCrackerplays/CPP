#include "Weapon.hpp"

Weapon::Weapon(std::string type) {
	this->_type = type;
}

Weapon::Weapon(void) {
}

Weapon::~Weapon(void) {
	// std::cout << "Weapon of type \"" << this->_type << "\" is getting destructed!" << std::endl;
}

const std::string&	Weapon::getType(void) {
	return (this->_type);
}

void	Weapon::setType(std::string type) {
	this->_type = type;
}
