#ifndef POINT_HPP
#define POINT_HPP

#include <Fixed.hpp>

class Point
{
	public:
		Point();
		Point(const float x, const float y);
		Point(const Point&src);
		~Point();
		Point &operator=(const Point&);
		float GetX() const;
		float GetY() const;
	private:
		const Fixed _x;
		const Fixed _y;
};

#endif