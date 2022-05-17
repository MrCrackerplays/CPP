#include "Character.hpp"

Character::Character(std::string name) : name(name) {
	this->inventory[0] = NULL;
	this->inventory[1] = NULL;
	this->inventory[2] = NULL;
	this->inventory[3] = NULL;
}

Character::Character(Character const & src) : name(src.name) {
	for (int i = 0; i < 4; i++)
		if (src.inventory[i] != NULL)
			this->inventory[i] = src.inventory[i]->clone();
}

Character::~Character(void) {
	for (int i = 0; i < 4; i++) {
		if (this->inventory[i] != NULL) {
			delete this->inventory[i];
			this->inventory[i] = NULL;
		}
	}
	// std::cout << this->name << ": I die now" << std::endl;
}

Character &	Character::operator=(Character const & rhs) {
	this->name = rhs.name;
	return (*this);
}

std::string const & Character::getName() const {
	return (this->name);
}

void Character::equip(AMateria* m) {
	for (int i = 0; i < 4; i++) {
		if (this->inventory[i] != NULL)
			continue ;
		this->inventory[i] = m;
		break ;
	}
}

void Character::unequip(int idx) {
	this->inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target) {
	if (idx < 4 && this->inventory[idx] != NULL)
		this->inventory[idx]->use(target);
}
