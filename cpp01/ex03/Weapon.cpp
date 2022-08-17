#include "Weapon.hpp"

Weapon::Weapon(std::string type) : type(type) {
}

Weapon::Weapon(void) {
}

Weapon::~Weapon(void) {
	// std::cout << "Weapon of type \"" << this->type << "\" is getting destructed!" << std::endl;
}

const std::string&	Weapon::getType(void) {
	return (this->type);
}

void	Weapon::setType(std::string type) {
	this->type = type;
}
