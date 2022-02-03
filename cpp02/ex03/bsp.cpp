#include "Point.hpp"

Fixed get_y_for_x(Point const p1, Point const p2, Fixed const x) {
	Fixed	coefficient = (p1.getY() - p2.getY()) / (p1.getX() - p2.getX());
	Fixed	translate = p1.getY() - (coefficient * p1.getX());
	Fixed	expectedY = translate + (coefficient * x);
	return (expectedY);
}

bool	is_on_under(Point const p1, Point const p2, Point const p3, Point const p) {
	//handling straight line where p1 and p2 are above one another because then you'd get division by 0 problems
	if (p1.getX() == p2.getX()) {
		if (p1.getX() == p3.getX()) {
			if (p1.getX() != p.getX())
				return (false);
			if (p.getY() > Fixed::max(Fixed::max(p1.getY(), p2.getY()), p3.getY()))
				return (false);
			if (p.getY() < Fixed::min(Fixed::min(p1.getY(), p2.getY()), p3.getY()))
				return (false);
			return (true);
		}
		else {
			bool right_p3 = (p1.getX() - p3.getX()) < Fixed(0);
			bool right_p = (p1.getX() - p.getX()) < Fixed(0);
			return (right_p3 == right_p);
		}
	}
	Fixed	expected_y_for_p = get_y_for_x(p1, p2, p.getX());
	Point middle = Point((p1.getX() + p2.getX() + p3.getX()) / 3,(p1.getY() + p2.getY() + p3.getY()) / 3);
	if (get_y_for_x(p1, p2, middle.getX()) > middle.getY())
		return ((p.getY() - expected_y_for_p) <= Fixed(0));
	return ((expected_y_for_p - p.getY()) <= Fixed(0));
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
	bool	onUnderA;
	bool	onUnderB;
	bool	onUnderC;
	//where A is the line opposite of the corner a, etc.

	onUnderA = is_on_under(b, c, a, point);
	onUnderB = is_on_under(c, a, b, point);
	onUnderC = is_on_under(a, b, c, point);
	return (onUnderA && onUnderB && onUnderC);
}
