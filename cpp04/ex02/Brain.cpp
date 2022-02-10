#include "Brain.hpp"

Brain::Brain(void) {
	std::cout << "Brain Created" << std::endl;
}

Brain::Brain(Brain const & src) {
	std::cout << "Brain Cloning... ";
	for (int i = 0; i < 100; i++) {
		this->idea[i] = src.idea[i];
	}
	std::cout << "Brain Cloned!" << std::endl;
}

Brain::~Brain(void) {
	std::cout << "Brain Removed" << std::endl;
}

Brain &	Brain::operator=(Brain const & rhs) {
	std::cout << "Brain Assigning... ";
	for (int i = 0; i < 100; i++) {
		this->idea[i] = rhs.idea[i];
	}
	std::cout << "Brain Assigned!" << std::endl;
	return (*this);
}
