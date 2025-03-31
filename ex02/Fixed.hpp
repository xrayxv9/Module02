#pragma once

#include <cmath>
#include <iostream>

class Fixed
{
	public :
		// all the init	
		Fixed( void );
		Fixed( const int nb );
		Fixed( const float nb);
		Fixed( const Fixed& copy );
	
		//copy
		Fixed &operator=( const Fixed& self );

		// comparaison
		bool operator<( const Fixed& self ) const;
		bool operator>( const Fixed& self ) const;
		bool operator>=( const Fixed& self ) const;
		bool operator<=( const Fixed& self ) const;
		bool operator==( const Fixed& self ) const;
		bool operator!=( const Fixed& self ) const;

		// calcul
		Fixed operator+( const Fixed& self );
		Fixed operator-( const Fixed& self );
		Fixed operator/( const Fixed& self );
		Fixed operator*( const Fixed& self );
		
		//post
		Fixed &operator++( void );
		Fixed &operator--( void );

		// pre
		Fixed operator++( int nb );
		Fixed operator--( int nb );

		// min max
		static Fixed& min( Fixed& first, Fixed& second);	
		static Fixed& max( Fixed& first, Fixed& second);	

		// const version
		static const Fixed& min( const Fixed& first, const Fixed& second);	
		static const Fixed& max( const Fixed& first, const Fixed& second);	

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
