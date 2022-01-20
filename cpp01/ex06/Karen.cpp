#include "Karen.hpp"

Karen::Karen(void) {
}

Karen::~Karen(void) {
}

void Karen::debug( void ) {
	std::cout << "I love to get extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger." << std::endl << "I just love it!" << std::endl;
}
void Karen::info( void ) {
	std::cout << "I cannot believe adding extra bacon cost more money." << std::endl << "You don’t put enough!" << std::endl << "If you did I would not have to ask for it!" << std::endl;
}
void Karen::warning( void ) {
	std::cout << "I think I deserve to have some extra bacon for free." << std::endl << "I’ve been coming here for years and you just started working here last month." << std::endl;
}
void Karen::error( void ) {
	std::cout << "This is unacceptable, I want to speak to the manager now." << std::endl;
}

void	Karen::complain(std::string level) {
	void (Karen::*ptr[])(void) = { &Karen::debug,  &Karen::info, &Karen::warning, &Karen::error };
	std::string	inputs[] = { "DEBUG", "INFO", "WARNING", "ERROR" };
	int	i = 0;
	for (; i < 3; i++)
		if (level.compare(inputs[i]) == 0)
			break;
	(this->*ptr[i])();
}
