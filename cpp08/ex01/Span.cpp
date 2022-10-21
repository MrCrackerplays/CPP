#include "Span.hpp"
#include <exception>
#include <algorithm>

Span::Span(unsigned int n) : _span(new int[n]), _max_size(n), _current_size(0) {
}

Span::Span(Span const & copy) {
	*this = copy;
}

Span::~Span(void) {
	delete[] _span;
}

Span &	Span::operator=(Span const & rhs) {
	if (this == &rhs)
		return (*this);
	delete[] this->_span;
	new int[rhs._max_size];
	for (unsigned int i = 0; i < rhs._max_size; i++)
		this->_span[i] = rhs._span[i];
	this->_current_size = rhs._current_size;
	this->_max_size = rhs._max_size;
	return (*this);
}

void	Span::addNumber(int number) {
	if (this->_current_size >= this->_max_size)
		throw std::exception();
	this->_span[this->_current_size] = number;
	this->_current_size++;
}

unsigned int	Span::shortestSpan(void) {
	if (this->_current_size <= 1)
		throw std::exception();
	std::sort(this->_span, this->_span + this->_current_size);
	unsigned int shortlen = this->_span[this->_current_size - 1];
	for (unsigned int i = 0; i + 1 < this->_current_size; i++)
		if (shortlen > (unsigned int)(this->_span[i + 1] - this->_span[i]))
			shortlen = this->_span[i + 1] - this->_span[i];
	return (shortlen);
}

unsigned int	Span::longestSpan(void) {
	if (this->_current_size <= 1)
		throw std::exception();
	std::sort(this->_span, this->_span + this->_current_size);
	return (this->_span[this->_current_size - 1] - this->_span[0]);
}
