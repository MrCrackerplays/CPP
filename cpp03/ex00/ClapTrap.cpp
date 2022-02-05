#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : name(name), hit_points(10), energy_points(10), attack_damage(0) {
	std::cout << "Claptrap " << name << " created!" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const & src) : name(src.name), hit_points(src.hit_points), energy_points(src.energy_points), attack_damage(src.attack_damage) {
	std::cout << "Claptrap " << src.name << " created with copy constructor!" << std::endl;
}

ClapTrap::~ClapTrap(void) {
	std::cout << "Claptrap " << this->name << " destroyed!" << std::endl;
}

ClapTrap &	ClapTrap::operator=(ClapTrap const & rhs) {
	this->name = rhs.name;
	this->hit_points = rhs.hit_points;
	this->energy_points = rhs.energy_points;
	this->attack_damage = rhs.attack_damage;
	std::cout << "Claptrap " << this->name << " asigned!" << std::endl;
	return (*this);
}

void	ClapTrap::attack(const std::string& target) {
	if (this->hit_points == 0 || this->energy_points == 0) {
		// std::cout << "Claptrap " << this->name << " wanted to attack " << target << ", for " << this->attack_damage << " points of damage, but doesn't have any energy points left!" << std::endl;
		return ;
	}
	this->energy_points--;
	std::cout << "Claptrap " << this->name << " attacks " << target << ", causing " << this->attack_damage << " points of damage!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount) {
	if (this->hit_points == 0) {
		// std::cout << "Claptrap " << this->name << " was gonna take " << amount << " points of damage, but already has no hit points left!" << std::endl;
		return ;
	}
	std::cout << "Claptrap " << this->name << " takes " << amount << " points of damage!" << std::endl;
	if (amount > this->hit_points)
		this->hit_points = 0;
	else
		this->hit_points -= amount;
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (this->hit_points == 0 || this->energy_points == 0) {
		// std::cout << "Claptrap " << this->name << " wanted to get repaired for " << amount << " hit points, but doesn't have any energy points left!" << std::endl;
		return ;
	}
	std::cout << "Claptrap " << this->name << " gets repaired for " << amount << " hit points!" << std::endl;
	this->energy_points--;
	this->hit_points += amount;
}

unsigned int ClapTrap::gethp(void) {
	return this->hit_points;
}
