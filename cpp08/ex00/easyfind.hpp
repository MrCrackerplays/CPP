#ifndef EASYFIND_HPP
# define EASYFIND_HPP
#include <algorithm>

template<typename T>
typename T::iterator easyfind(T &container, int needle) {
	typename T::iterator findIter = std::find(container.begin(), container.end(), needle);
	if (findIter == container.end())
		throw std::exception();
	return (findIter);
}

#endif
