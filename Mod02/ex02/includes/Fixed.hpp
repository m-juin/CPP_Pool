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
		float	operator+(Fixed const& F2);
		float	operator-(Fixed const& F2);
		float	operator*(Fixed const& F2);
		float	operator/(Fixed const& F2);
		Fixed	operator++(int);
		Fixed	operator--(int);
		Fixed&	operator++();
		Fixed&	operator--();
		bool	operator>(Fixed const& F2);
		bool	operator<(Fixed const& F2);
		bool	operator>=(Fixed const& F2);
		bool	operator>=(Fixed const& F2);
		bool	operator!=(Fixed const& F2);
		bool	operator==(Fixed const& F2);
		float	min(Fixed &F1, Fixed &F2);
		float	min(Fixed const& F1, Fixed const& F2);
		float	max(Fixed &F1, Fixed &F2);
		float	max(Fixed const& F1, Fixed const& F2);
};

std::ostream	&operator<<(std::ostream& os, const Fixed& f);