#include "Point.hpp"

int	main( void ) {
	Point a = Point(0, 0);
	Point b = Point(1, 1);
	Point c = Point(0.99, 0);
	Fixed test1;
	Fixed test2;
	test1.setRawBits(85);
	test2.setRawBits(1);
	//(1/3) / 0.00390625 (=float value returned on setRawBits(1)) -> rawbits=85 + 1/3 -> not possible in int so becomes 85
	Point point1 = Point(test1, test1);
	Point point2 = Point(test1, test1 - test2);
	Point point3 = Point((float)1/(float)3, (float)1/(float)3);
	Point point4 = Point(Fixed(1) - test2, Fixed(1) - test2 - test2);
	Point point5 = Point(Fixed(-1) + test2, Fixed(1) - test2);
	Point point6 = Point(Fixed((float)0.5), test2);
	Point points[6] = {point1, point2, point3, point4, point5, point6};
	for (int i = 0; i < 6; i++) {
		std::cout << "is point (" << points[i].getX() << "," << points[i].getY() << ")";
		// std::cout << "(raw:" << points[i].getX().getRawBits() << "," << points[i].getY().getRawBits() << ")";
		std::cout << " within triangle[a(" << a.getX() << "," << a.getY() << "),b(" << b.getX() << "," << b.getY() << "),c(" << c.getX() << "," << c.getY() << ")]? ";
		std::cout << (bsp(a, b, c, points[i]) ? "yes" : "no") << std::endl;
	}
	return 0;
}