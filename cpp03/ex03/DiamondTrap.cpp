#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(ClapTrap::name), FragTrap(ClapTrap::name), name(name) {
	this->hit_points = FragTrap::hit_points;
	this->energy_points = ScavTrap::energy_points;
	this->attack_damage = FragTrap::attack_damage;
	std::cout << "New DiamondTrap Unit " << name << " Created!" << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap const & src) : ClapTrap(src), ScavTrap(src), FragTrap(src), name(src.name) {
	std::cout << "DiamondTrap Unit " << src.name << " Created Via Copy Constructor!" << std::endl;
}

DiamondTrap::~DiamondTrap(void) {
	std::cout << "DiamondTrap Unit " << this->name << " Destroyed!" << std::endl;
}

DiamondTrap &	DiamondTrap::operator=(DiamondTrap const & rhs) {
	this->ClapTrap::name = rhs.ClapTrap::name;
	this->name = rhs.name;
	this->hit_points = rhs.hit_points;
	this->energy_points = rhs.energy_points;
	this->attack_damage = rhs.attack_damage;
	this->gate_keeper = rhs.gate_keeper;
	std::cout << "DiamondTrap Unit " << this->name << " Asigned!" << std::endl;
	return (*this);
}

void	DiamondTrap::attack(const std::string& target) {
	ScavTrap::attack(target);
}

void	DiamondTrap::takeDamage(unsigned int amount) {
	if (this->hit_points == 0) {
		std::cout << "DiamondTrap Unit " << this->name << " Was Attacked For " << amount << " Points Of Damage, But Did Not Have Any Hit Points Left!" << std::endl;
		return ;
	}
	std::cout << "DiamondTrap Unit " << this->name << " Receives " << amount << " Points Of Damage!" << std::endl;
	if (amount > this->hit_points)
		this->hit_points = 0;
	else
		this->hit_points -= amount;
}

void	DiamondTrap::beRepaired(unsigned int amount) {
	if (this->hit_points == 0 || this->energy_points == 0) {
		std::cout << "DiamondTrap Unit " << this->name << " Failed To Get Repaired For " << amount << " Hit Points, Due To Not Having Any " << (this->hit_points == 0 ? "Hit Points" : "Energy Points") <<" Left!" << std::endl;
		return ;
	}
	std::cout << "DiamondTrap Unit " << this->name << " Gets Repaired For " << amount << " Hit Points!" << std::endl;
	this->energy_points--;
	this->hit_points += amount;
}

void	DiamondTrap::whoAmI(void) {
	std::cout << "DiamondTrap Unit " << this->name << " Is Also Registered As ClapTrap Unit " << this->ClapTrap::name << "!" << std::endl;
}
