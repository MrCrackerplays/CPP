#ifndef ITER_HPP
# define ITER_HPP
#include <iostream>

template <class Whatever>
void templatemagic(Whatever a) {
	std::cout << "printing a [" << a << "]" << std::endl;
}

template <class Arr, class Len>
void iter(Arr *a, Len b, void c(const Arr)) {
	for (Len i = 0; i < b; i++)
		c(a[i]);
}

#endif
