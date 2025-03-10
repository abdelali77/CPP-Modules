#include "Point.hpp"

Fixed calc_area( Point const a, Point const b, Point const c) {
	Fixed area = (a.getX() * (b.getY() - c.getY()) + b.getX() * (c.getY() - a.getY()) + c.getX() * (a.getY() - b.getY())) / 2;
	return area < 0 ? area * (-1) : area;
}

bool bsp( Point const a, Point const b, Point const c, Point const point ) {
	Fixed area = calc_area(a, b, c);
	Fixed areaA = calc_area(point, a, b);
	Fixed areaB = calc_area(point, b, c);
	Fixed areaC = calc_area(point, a, c);

	if (areaA == 0 || areaB == 0 || areaC == 0)
		return false;
	if ((areaA + areaB + areaC) == area)
		return true;
	else
		return false;
	return true;
}
