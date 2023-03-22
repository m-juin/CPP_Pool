#include <Fixed.hpp>
#include <cmath>

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	_value = 0;
}

Fixed::Fixed(const int src)
{
	std::cout << "Int constructor called" << std::endl;
	_value = (int)roundf(src * (1 << bits));
}

Fixed::Fixed(const float src)
{
	std::cout << "Float constructor called" << std::endl;
	_value = roundf(src * (1 << bits));
}

Fixed::Fixed(const Fixed &src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &src)
{
	if (&src == this)
		return(*this);
	std::cout << "Copy assignment operator called" << std::endl;
    _value = src._value;
    return *this;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (_value);
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
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