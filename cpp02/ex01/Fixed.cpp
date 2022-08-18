#include "Fixed.hpp"
#include <cmath>

/* Canonical */
Fixed::Fixed(void) : value(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const & src) {
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::~Fixed(void) {
	std::cout << "Destructor called" << std::endl;
}

Fixed &	Fixed::operator=(Fixed const & rhs) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->value = rhs.getRawBits();
	return (*this);
}

/* Specific */
int		Fixed::getRawBits(void) const {
	// std::cout << "getRawBits member function called" << std::endl;
	return (this->value);
}

void	Fixed::setRawBits(int const raw) {
	// std::cout << "setRawBits member function called" << std::endl;
	this->value = raw;
}

Fixed::Fixed(const int value) {
	std::cout << "Int constructor called" << std::endl;
	this->setRawBits(value << this->fractional_bits);
}

Fixed::Fixed(const float value) {
	//https://embeddedartistry.com/blog/2018/07/12/simple-fixed-point-conversion-in-c/
	std::cout << "Float constructor called" << std::endl;
	this->setRawBits(roundf(value * (1 << this->fractional_bits)));
}

float	Fixed::toFloat(void) const {
	//https://embeddedartistry.com/blog/2018/07/12/simple-fixed-point-conversion-in-c/
	return ((float)this->getRawBits() / (float)(1 << this->fractional_bits));
}

int		Fixed::toInt(void) const {
	return (this->getRawBits() >> this->fractional_bits);
}

std::ostream& operator<<(std::ostream& out, const Fixed& f1) {
	out << f1.toFloat();
	return (out);
}
