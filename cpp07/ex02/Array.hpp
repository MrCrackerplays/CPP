#ifndef ARRAY_HPP
# define ARRAY_HPP
# include <exception>

template <class T>
class Array {
protected:
	T	*_values;
	unsigned int _size;
public:
	Array(void) : _values(NULL), _size(0) {}
	Array(unsigned int n) : _values(new T[n]), _size(n) {}
	Array(Array const & copy) : _values(NULL), _size(0) {
		*this = copy;
	}

	~Array(void) {
		delete[] this->_values;
	}

	Array<T> &	operator=(Array<T> const & rhs) {
		if (&rhs == this)
			return (*this);
		if (this->_size)
			delete[] this->_values;
		this->_size = rhs._size;
		this->_values = new T[this->_size];
		for (unsigned int i = 0; i < this->_size; i++)
			this->_values[i] = rhs._values[i];
		return (*this);
	}
	T & operator[](const int i) const {
		if (i < 0 || static_cast<unsigned int>(i) >= this->_size)
			throw std::exception();
		return (this->_values[i]);
	}

	unsigned int size(void) const {
		return (this->_size);
	}
};

#endif
