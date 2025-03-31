#include "Fixed.hpp"
#include <cmath>

const int Fixed::bitShift = 8;

// Here is the connonical form 
Fixed::Fixed( void )
{
	this->fixedPoint = 0;
}

Fixed::Fixed( const int nb )
{
	this->fixedPoint = nb << bitShift;
}

Fixed::Fixed( const float nb )
{
	fixedPoint = roundf(nb* (1 << bitShift));
}

Fixed::Fixed( const Fixed &copy )
{
	*this = copy;
}

Fixed::~Fixed ( void )
{
	return ;
}

// if you don't put the const the  function above will consider it as 'not viable'
Fixed &Fixed::operator=( const Fixed &self )
{
	if (this != &self)
		this->fixedPoint = self.getRawBits();
	return *this;
}

// comparision
bool Fixed::operator<(const Fixed &self) const
{
	if (this->fixedPoint < self.fixedPoint)
		return true;
	return false;
}

bool Fixed::operator>(const Fixed &self) const
{
	if (this->fixedPoint > self.fixedPoint)
		return true;
	return false;
}

bool Fixed::operator>=(const Fixed &self) const
{
	if (this->fixedPoint >= self.fixedPoint)
		return true;
	return false;
}

bool Fixed::operator<=(const Fixed &self) const
{
	if (this->fixedPoint <= self.fixedPoint)
		return true;
	return false;
}

bool Fixed::operator!=(const Fixed &self) const
{
	if (self.fixedPoint != this->fixedPoint)
		return true;
	return false;
}

bool Fixed::operator==(const Fixed &self) const
{
	if (self.fixedPoint == this->fixedPoint)
		return true;
	return false;
}

// calculation

Fixed Fixed::operator+( const Fixed& self )
{
	Fixed tmp = Fixed(this->toFloat() + self.toFloat());
	return tmp;
}

Fixed Fixed::operator-( const Fixed& self )
{
	Fixed tmp = Fixed(this->toFloat() - self.toFloat());
	return tmp;
}

Fixed Fixed::operator*( const Fixed& self )
{
	Fixed tmp = Fixed(this->toFloat() * self.toFloat());
	return tmp;
}

Fixed Fixed::operator/( const Fixed& self )
{
	Fixed tmp = Fixed(this->toFloat() / self.toFloat());
	return tmp;
}

//pre increment
Fixed Fixed::operator++( int nb )
{
	Fixed tmp = *this;

	if (!nb)
		++this->fixedPoint;
	else 
		this->fixedPoint += nb;
	return tmp;
}

Fixed Fixed::operator--( int nb )
{
	Fixed tmp = *this;

	if (!nb)
		--this->fixedPoint;
	else 
		this->fixedPoint -= nb;
	return tmp;
}

// min max
Fixed &Fixed::min( Fixed& first, Fixed& second )
{
	if (first < second)
		return first;
	return second;
}

Fixed &Fixed::max( Fixed& first, Fixed& second )
{
	if (first > second)
		return first;
	return second;
}

// min max const

const Fixed &Fixed::min(const Fixed& first, const Fixed& second )
{
	if (first < second)
		return first;
	return second;
}

const Fixed &Fixed::max(const Fixed& first, const Fixed& second )
{
	if (first > second)
		return first;
	return second;
}

// post incrment
Fixed &Fixed::operator++( void )
{
	this->fixedPoint++;
	return *this;
}

Fixed &Fixed::operator--( void )
{
	this->fixedPoint--;
	return *this;
}

// print

std::ostream &operator<<( std::ostream& o, const Fixed &self )
{
	o << self.toFloat();
	return o;
}

// functions
void Fixed::setRawBits( const int raw )
{
	fixedPoint = raw;
}

int Fixed::getRawBits( void ) const
{
	return this->fixedPoint;
}

float Fixed::toFloat( void ) const
{
	return (float)this->fixedPoint / (float)(1 << this->bitShift);
}

int Fixed::toInt( void ) const
{
	return roundf(this->fixedPoint >> this->bitShift);
}
