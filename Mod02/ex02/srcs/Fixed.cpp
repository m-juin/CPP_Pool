#include <Fixed.hpp>
#include <cmath>

Fixed::Fixed()
{
	_value = 0;
}

Fixed::Fixed(const int src)
{
	_value = (int)roundf(src * (1 << bits));
}

Fixed::Fixed(const float src)
{
	_value = roundf(src * (1 << bits));
}

Fixed::Fixed(const Fixed &src)
{
	*this = src;
}

Fixed::~Fixed()
{
}

Fixed &Fixed::operator=(const Fixed &src)
{
	if (&src == this)
		return(*this);
    _value = roundf(src.toFloat() * (1 << bits));
    return *this;
}

int Fixed::getRawBits(void) const
{
	return (_value);
}

void Fixed::setRawBits(int const raw)
{
	_value = raw;
}

float Fixed::toFloat(void) const
{
	return ((float)_value / (float)(1 << bits));
}

int Fixed::toInt(void) const
{
		return ((int)_value / (float)(1 << bits));
}


std::ostream	&operator<<(std::ostream& os, const Fixed& f)
{
	os << f.toFloat();
	return os;
}

float operator+(Fixed const &F1, Fixed const &F2)
{
	return (F1.toFloat() + F2.toFloat());
}

float operator-(Fixed const &F1, Fixed const &F2)
{
	return (F1.toFloat() - F2.toFloat());
}

float operator/(Fixed const &F1, Fixed const &F2)
{
	return (F1.toFloat() / F2.toFloat());
}

float operator*(Fixed const &F1, Fixed const &F2)
{
	return (F1.toFloat() * F2.toFloat());
}

bool operator>(Fixed const &F1, Fixed const &F2)
{
	return (F1.toFloat() > F2.toFloat());
}

bool operator<(Fixed const &F1, Fixed const &F2)
{
	return (F1.toFloat() < F2.toFloat());
}

bool operator>=(Fixed const &F1, Fixed const &F2)
{
	return (F1.toFloat() >= F2.toFloat());
}

bool operator<=(Fixed const &F1, Fixed const &F2)
{
	return (F1.toFloat() <= F2.toFloat());
}

bool operator!=(Fixed const &F1, Fixed const &F2)
{
	return (F1.toFloat() != F2.toFloat());
}

bool operator==(Fixed const &F1, Fixed const &F2)
{
	return (F1.toFloat() == F2.toFloat());
}

Fixed&	Fixed::operator++()
{
	this->_value++;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed tmp(*this);
	this->_value++;
	return (tmp);
}

Fixed&	Fixed::operator--()
{
	this->_value--;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed tmp(*this);
	this->_value--;
	return (tmp);
}

Fixed Fixed::min(Fixed &F1, Fixed &F2)
{
	return F1.toFloat() < F2.toFloat() ? F1 : F2;
}

Fixed const Fixed::min(Fixed const &F1, Fixed const &F2)
{
	return F1.toFloat() < F2.toFloat() ? F1 : F2;
}

Fixed Fixed::max(Fixed &F1, Fixed &F2)
{
	return F1.toFloat() > F2.toFloat() ? F1 : F2;
}

Fixed const Fixed::max(Fixed const &F1, Fixed const &F2)
{
	return F1.toFloat() > F2.toFloat() ? F1 : F2;
}
