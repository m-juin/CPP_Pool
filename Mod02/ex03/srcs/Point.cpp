#include <Point.hpp>

Point::Point() : _x(Fixed(0)), _y(Fixed(0))
{
}


Point::Point(const float x, const float y) : _x(Fixed(x)), _y(Fixed(y))
{
}

Point::Point(const Point &src) : _x(Fixed(src._x)), _y(Fixed(src._y))
{
}

Point::~Point()
{
}

Point &Point::operator=(const Point &src)
{
	if (this == &src)
		return (*this);
	(Fixed)this->_x = src._x;
	(Fixed)this->_y = src._y;
	return (*this);		
}

float Point::GetX() const
{
	return (this->_x.toFloat());
}

float Point::GetY() const
{
	return (this->_y.toFloat());
}
