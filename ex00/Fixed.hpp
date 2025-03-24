#pragma once
#include <iostream>

class Fixed
{
	public :
		Fixed( void );
		Fixed(const Fixed& copy);
		Fixed &operator=(const Fixed& self);
		~Fixed( void );
		int getRawBits( void ) const;
		void setRawBits( int const raw );

	private :
		int fixedPoint;
		static const int bitShift;
};
