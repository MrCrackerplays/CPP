#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template <class whatever>
void swap (whatever &a, whatever &b) {
	whatever temp = b;
	b = a;
	a = temp;
}

template <class whatever>
whatever min (whatever a, whatever b) {
	return (a < b ? a : b);
}

template <class whatever>
whatever max (whatever a, whatever b) {
	return (a > b ? a : b);
}

#endif
