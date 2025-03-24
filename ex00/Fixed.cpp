#include "Fixed.hpp"
#include <stdio.h>

// Here is the connonical form 
Fixed::Fixed( void )
{
	std::cout << "Default constructor called" << std::endl;
	this->fixedPoint = 0;
}

Fixed::Fixed( const Fixed &copy )
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Fixed::~Fixed ( void )
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

// if you don't put the const the  function above will consider it as 'not viable'
Fixed &Fixed::operator=( const Fixed &self )
{
	std::cout << "copy assigment operator called" << std::endl;
	if (this != &self)
		this->fixedPoint = self.getRawBits();
	return *this;
}

// bits
void Fixed::setRawBits( const int raw )
{
	fixedPoint = raw;
}

int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->fixedPoint;
}
