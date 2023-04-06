#include <iostream>
#include "PmergeMe.hpp"
#include <ctime>

static void	print_vector(std::vector<unsigned long> container) {
	bool	first = true;
	for (std::vector<unsigned long>::iterator it = container.begin(); it != container.end(); it++) {
		if (!first) {
			std::cout << " ";
		} else {
			first = false;
		}
		std::cout << *it;
	}
	std::cout << std::endl;
}

int main(int argc, char **argv) {
	std::cout << "Before:\t";
	for (int i = 1; i < argc; i++) {
		if (i != 1) {
			std::cout << " ";
		}
		std::cout << argv[i];
	}
	std::cout << std::endl;
	std::clock_t	c1_start = std::clock();
	std::vector<unsigned long>	c1;
	for (int i = 1; i < argc; i++) {
		if (std::string(argv[i]).find_first_not_of("0123456789") != std::string::npos) {
			std::cout << "Error, not a positive integer" << std::endl;
			return (1);
		}
		char	*end = argv[i] + std::strlen(argv[i]);
		c1.push_back(std::strtoul(argv[i], &end, 10));
		//this module isn't about boundary checking for 2147483647+ it's about using containers
	}
	sortVector(c1, 0, c1.size() - 1);
	std::clock_t	c1_end = std::clock();
	long double		c1_elapsed = 1000.0 * (c1_end - c1_start) / CLOCKS_PER_SEC;
	std::clock_t	c2_start = std::clock();
	std::deque<unsigned long>	c2;
	for (int i = 1; i < argc; i++) {
		if (std::string(argv[i]).find_first_not_of("0123456789") != std::string::npos) {
			std::cout << "Error, not a positive integer" << std::endl;
			return (1);
		}
		char	*end = argv[i] + std::strlen(argv[i]);
		c2.push_back(std::strtoul(argv[i], &end, 10));
	}
	sortDeque(c2, 0, c2.size() - 1);
	std::clock_t	c2_end = std::clock();
	long double		c2_elapsed = 1000.0 * (c2_end - c2_start) / CLOCKS_PER_SEC;
	std::cout << "After:\t";
	print_vector(c1);
	std::cout << "Time to process a range of " << c1.size() << " elements with std::vector : " << c1_elapsed << " ms" << std::endl;
	std::cout << "Time to process a range of " << c2.size() << " elements with std::deque : " << c2_elapsed << " ms" << std::endl;
}
