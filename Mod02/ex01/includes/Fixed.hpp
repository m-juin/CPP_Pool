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
};

std::ostream	&operator<<(std::ostream& os, const Fixed& f);