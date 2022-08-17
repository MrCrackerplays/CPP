#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) : name(name), _weapon(weapon) {
}

HumanA::~HumanA(void) {
	// std::cout << "HumanA \"" << this->name << "\" is getting destructed!" << std::endl;
}

void	HumanA::attack(void) {
	std::cout << this->name << " attacks with their " << this->_weapon.getType() << std::endl;
}
