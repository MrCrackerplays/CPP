#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	this->hit_points = 100;
	this->energy_points = 100;
	this->attack_damage = 30;
	std::cout << "New FragTrap Unit " << name << " Created!" << std::endl;
}

FragTrap::FragTrap(FragTrap const & src) : ClapTrap(src) {
	std::cout << "FragTrap Unit " << src.name << " Created Via Copy Constructor!" << std::endl;
}

FragTrap::~FragTrap(void) {
	std::cout << "FragTrap Unit " << this->name << " Destroyed!" << std::endl;
}

FragTrap &	FragTrap::operator=(FragTrap const & rhs) {
	this->name = rhs.name;
	this->hit_points = rhs.hit_points;
	this->energy_points = rhs.energy_points;
	this->attack_damage = rhs.attack_damage;
	std::cout << "FragTrap Unit " << this->name << " Asigned!" << std::endl;
	return (*this);
}

void	FragTrap::attack(const std::string& target) {
	if (this->hit_points == 0 || this->energy_points == 0)
		return ;
	this->energy_points--;
	std::cout << "FragTrap Unit " << this->name << " Launches An Attack On " << target << ", Dealing " << this->attack_damage << " Points Of Damage!" << std::endl;
}

void	FragTrap::takeDamage(unsigned int amount) {
	if (this->hit_points == 0)
		return ;
	std::cout << "FragTrap Unit " << this->name << " Receives " << amount << " Points Of Damage!" << std::endl;
	if (amount > this->hit_points)
		this->hit_points = 0;
	else
		this->hit_points -= amount;
}

void	FragTrap::beRepaired(unsigned int amount) {
	if (this->hit_points == 0 || this->energy_points == 0)
		return ;
	std::cout << "FragTrap Unit " << this->name << " Gets Repaired For " << amount << " Hit Points!" << std::endl;
	this->energy_points--;
	this->hit_points += amount;
}

void	FragTrap::highFivesGuys(void) {
	std::cout << "FragTrap Unit " << this->name << " Requests High Fives From You!" << std::endl;
}
