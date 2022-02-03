#ifndef POINT_HPP
# define POINT_HPP
# include "Fixed.hpp"

class Point {
private:
	const Fixed x;
	const Fixed y;
public:
	/* Canonical */
	Point(void);
	Point(Point const & src);
	~Point(void);
	Point &	operator=(Point const & rhs);

	/* Specific */
	Point(const float x, const float y);
	Point(const Fixed x, const Fixed y);
	Fixed	getX(void) const;
	Fixed	getY(void) const;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif