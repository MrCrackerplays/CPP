#include "Point.hpp"


	Point::Point(void) : x(0), y(0) {
		// std::cout << "create" << std::endl;
	}

	Point::Point(Point const & src) : x(src.x), y(src.y) {
		// std::cout << "copy" << std::endl;
	}

	Point::~Point(void) {
		// std::cout << "destr" << std::endl;
	}

	Point &	Point::operator=(Point const & rhs) {
		// std::cout << "assign" << std::endl;
		// *this = Point(rhs);
		if (rhs.x.getRawBits() == 0)
			return (*this);
		return (*this);
	}

	Point::Point(const float x, const float y) : x(x), y(y) {
		// std::cout << "float create" << std::endl;
	}

	Point::Point(const Fixed x, const Fixed y) : x(x), y(y) {
		// std::cout << "fixed create" << std::endl;
	}

	Fixed	Point::getX(void) const {
		return (this->x);
	}

	Fixed	Point::getY(void) const {
		return (this->y);
	}
