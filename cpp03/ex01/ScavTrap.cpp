#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name), gate_keeper(false) {
	this->hit_points = 100;
	this->energy_points = 50;
	this->attack_damage = 20;
	std::cout << "Scavtrap " << name << " created!" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const & src) : ClapTrap(src), gate_keeper(src.gate_keeper) {
	std::cout << "Scavtrap " << src.name << " created with copy constructor!" << std::endl;
}

ScavTrap::~ScavTrap(void) {
	std::cout << "Scavtrap " << this->name << " destroyed!" << std::endl;
}

ScavTrap &	ScavTrap::operator=(ScavTrap const & rhs) {
	this->name = rhs.name;
	this->hit_points = rhs.hit_points;
	this->energy_points = rhs.energy_points;
	this->attack_damage = rhs.attack_damage;
	this->gate_keeper = rhs.gate_keeper;
	std::cout << "Scavtrap " << this->name << " asigned!" << std::endl;
	return (*this);
}

void	ScavTrap::attack(const std::string& target) {
	if (this->hit_points == 0 || this->energy_points == 0)
		return ;
	this->energy_points--;
	std::cout << "ScavTrap " << this->name << " attacks " << target << ", causing " << this->attack_damage << " points of damage!" << std::endl;
}

void	ScavTrap::takeDamage(unsigned int amount) {
	if (this->hit_points == 0)
		return ;
	std::cout << "ScavTrap " << this->name << " takes " << amount << " points of damage!" << std::endl;
	if (amount > this->hit_points)
		this->hit_points = 0;
	else
		this->hit_points -= amount;
}

void	ScavTrap::beRepaired(unsigned int amount) {
	if (this->hit_points == 0 || this->energy_points == 0)
		return ;
	std::cout << "ScavTrap " << this->name << " gets repaired for " << amount << " hit points!" << std::endl;
	this->energy_points--;
	this->hit_points += amount;
}

void	ScavTrap::guardGate(void){
	if (this->gate_keeper)
		std::cout << "Scavtrap " << this->name << " is no longer in gate keeper mode!" << std::endl;
	else
		std::cout << "Scavtrap " << this->name << " is now in gate keeper mode!" << std::endl;
	this->gate_keeper = !this->gate_keeper;
}
