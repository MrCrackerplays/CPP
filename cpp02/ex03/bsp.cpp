#include "Point.hpp"

Fixed get_y_for_x(Point const p1, Point const p2, Fixed const x) {
	Fixed	coefficient = (p1.getY() - p2.getY()) / (p1.getX() - p2.getX());
	Fixed	translate = p1.getY() - (coefficient * p1.getX());
	Fixed	expectedY = translate + (coefficient * x);
	return (expectedY);
}

bool	is_under(Point const p1, Point const p2, Point const p3, Point const p) {
	//handling straight line where p1 and p2 are above one another because then you'd get division by 0 problems
	if (p1.getX() == p2.getX()) {
		if (p1.getX() == p.getX())
			return (false);
		if (p1.getX() == p3.getX()) {
			return (false);
			//the subject *used* to accept point on the edge of the triangle too but no longer, thus it'll always be false if the triangle is a line (since a point will always be on the edge of a line)
			// if (p1.getX() != p.getX())
			// 	return (false);
			// if (p.getY() > Fixed::max(Fixed::max(p1.getY(), p2.getY()), p3.getY()))
			// 	return (false);
			// if (p.getY() < Fixed::min(Fixed::min(p1.getY(), p2.getY()), p3.getY()))
			// 	return (false);
			// return (true);
		}
		else {
			bool p3_same_side_p = ((p3.getX() < 0) == (p.getX() < 0));
			Fixed distance_from_p_to_p1 = p1.getX() > p.getX() ? ((Fixed)p1.getX() - (Fixed)p.getX()) : ((Fixed)p.getX() - (Fixed)p1.getX());
			Fixed distance_from_p3_to_p1 = p1.getX() > p3.getX() ? ((Fixed)p1.getX() - (Fixed)p3.getX()) : ((Fixed)p3.getX() - (Fixed)p1.getX());
			bool p_closer_than_p3_to_p1 = (distance_from_p_to_p1) < (distance_from_p3_to_p1);
			return (p3_same_side_p && p_closer_than_p3_to_p1);
		}
	}
	Fixed	expected_y_for_p = get_y_for_x(p1, p2, p.getX());
	//if the actual y is higher than the expected y then it can only be correct if the line is below the middle
	//if the actual y is lower than the expected y then it can only be corect if the line is above the middle

	Point	middle = Point((p1.getX() + p2.getX() + p3.getX()) / 3,(p1.getY() + p2.getY() + p3.getY()) / 3);
	Fixed	expected_y_for_middle = get_y_for_x(p1, p2, middle.getX());
	if (expected_y_for_middle > middle.getY()) {
		//the middle point is located below the line of p1-p2
		//return true if the actual y is lower than the expected y cause then it's below the line (which we want cause the line is above the middle)
		return (p.getY() < expected_y_for_p);
	}
	else if (expected_y_for_middle < middle.getY()) {
		//the middle point is located above the line of p1-p2
		//return true if the actual y is higher than the expected y cause then it's above the line (which we want cause the line is below the middle)
		return (p.getY() > expected_y_for_p);
	}
	//the middle point is located in the line of p1-2 thus the 'triangle' is a line 
	return (false);
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
	bool	underA;
	bool	underB;
	bool	underC;
	//where A is the line opposite of the corner a, etc.

	//'under' in this place meaning taking the middle of the triangle as the 'gravitational center'
	//and the side of the line that that 'gravitational center' is on is the 'under' side
	//yes this is a very convoluted explanation but my brain is mush after wrestling with logic
	underA = is_under(b, c, a, point);
	underB = is_under(c, a, b, point);
	underC = is_under(a, b, c, point);
	return (underA && underB && underC);
}
