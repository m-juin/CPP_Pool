#include <iostream>

class Fixed
{
	private:
		int _value;
		static const int bits = 8;
	public:
		Fixed();
		Fixed(const int src);
		Fixed(const float src);
		Fixed(const Fixed&);
		~Fixed();
		Fixed &operator=(const Fixed&);
		int getRawBits( void ) const;
		void setRawBits( int const raw );
		float toFloat( void ) const;
		int toInt( void ) const;
		Fixed	operator++(int);
		Fixed	operator--(int);
		Fixed&	operator++();
		Fixed&	operator--();
		static Fixed 	min(Fixed &F1, Fixed &F2);
		static const Fixed 	min(Fixed const &F1, Fixed const &F2);
		static Fixed 	max(Fixed &F1, Fixed &F2);
		static const Fixed 	max(Fixed const &F1, Fixed const &F2);
};

std::ostream	&operator<<(std::ostream& os, const Fixed& f);
float	operator+(Fixed const& F1, Fixed const& F2);
float	operator-(Fixed const& F1, Fixed const& F2);
float	operator*(Fixed const& F1, Fixed const& F2);
float	operator/(Fixed const& F1, Fixed const& F2);
bool	operator>(Fixed const& F1, Fixed const& F2);
bool	operator<(Fixed const& F1, Fixed const& F2);
bool	operator<=(Fixed const& F1, Fixed const& F2);
bool	operator>=(Fixed const& F1, Fixed const& F2);
bool	operator!=(Fixed const& F1, Fixed const& F2);
bool	operator==(Fixed const& F1, Fixed const& F2);