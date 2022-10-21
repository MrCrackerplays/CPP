#include <list>
#include <array>
#include <iostream>
#include "easyfind.hpp"

int main()
{
	std::list<int> ilist;
	ilist.push_back(1);
	ilist.push_back(2);
	ilist.push_back(3);

	try {
		std::list<int>::iterator it = easyfind(ilist, 6);
		std::cout << "found " << *it << std::endl;
	} catch (std::exception err) {
		std::cout << "not found" << std::endl;
	}

	std::array<int, 3> iarray = {1, 2, 3};

	try {
		std::array<int, 3>::iterator it = easyfind(iarray, 6);
		std::cout << "found " << *it << std::endl;
	} catch (std::exception err) {
		std::cout << "not found" << std::endl;
	}
}
