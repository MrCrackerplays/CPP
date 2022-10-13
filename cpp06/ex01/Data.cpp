#include "Data.hpp"

Data::Data(void) : _value(0) {
}

Data::Data(Data const & copy) : _value(copy._value) {
}

Data::~Data(void) {
}

Data &	Data::operator=(Data const & rhs) {
	if (this == &rhs)
		return (*this);
	return (*this);
}

int	Data::getValue(void) const {
	return (this->_value);
}

void	Data::setValue(int value) {
	this->_value = value;
}
