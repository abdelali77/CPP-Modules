#ifndef __POINT_HPP__
#define __POINT_HPP__

#include <iostream>
#include <cmath>
#include "Fixed.hpp"

// ************************************************************************** //
//                                 Point Class                                //
// ************************************************************************** //

class Point {
private:
	Fixed const x;
	Fixed const y;
public:
	Point( void );
	Point( const float x, const float y );
	Point( const Point& point );
	Point& operator=( const Point &point );
	~Point();

	const Fixed& getX( void ) const;
	const Fixed& getY( void ) const;
};

bool bsp( Point const a, Point const b, Point const c, Point const point );

#endif