#pragma once
#include <iostream>

class Fixed
{
	public :
		// all the init	
		Fixed( void );
		Fixed( const int nb );
		Fixed( const float nb);
		Fixed( const Fixed& copy );
		
		// operator overload
		Fixed &operator=( const Fixed& self );
		// destuctor
		~Fixed( void );
	
		//functions
		int getRawBits( void ) const;
		void setRawBits( int const raw );
		float toFloat( void ) const;
		int toInt( void ) const;

	private :
		int fixedPoint;
		static const int bitShift;
};

std::ostream& operator<<( std::ostream& o, Fixed const& self);
