#include "Fixed.hpp"

const int	Fixed::_frac = 8;

Fixed::Fixed(void) : _fixedVar(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(Fixed const &copy)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = copy;
}

Fixed &Fixed::operator=(Fixed const &copy)
{
    std::cout << "Copy assignment operator called" << std::endl;
    this->_fixedVar = copy.getRawBits();
    return (*this);
}

int Fixed::getRawBits( void ) const
{
    // std::cout << "getRawBits member function called" << std::endl;
    return(this->_fixedVar);
}

void Fixed::setRawBits( int const raw )
{
    this->_fixedVar = raw;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////

Fixed::Fixed(const int integer)
{
	std::cout << "Int constructor called" << std::endl;
	this->_fixedVar = (integer << Fixed::_frac);
}

Fixed::Fixed(const float floating_point)
{
	std::cout << "Float constructor called" << std::endl;
	this->_fixedVar = roundf(floating_point * (1 << Fixed::_frac));
}

float	Fixed::toFloat(void) const
{
	return ((float)this->_fixedVar / (float)(1 << Fixed::_frac));
}

int		Fixed::toInt(void) const
{
	return (this->_fixedVar >> Fixed::_frac);
}

std::ostream	&operator<<(std::ostream &str, Fixed const &object)
{
	str << object.toFloat();
	return (str);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////

// For Tests

// Fixed::Fixed(const int integer)
// {
//     std::bitset<16> binaryRepresentation0(integer);  
//     std::cout << "Binary: " << binaryRepresentation0 << std::endl;
// 	std::cout << "Int constructor called" << std::endl;
// 	this->_fixedVar = (integer << Fixed::_frac);
//     std::cout << _fixedVar  << std::endl;
//     std::bitset<16> binaryRepresentation(_fixedVar); 
//     std::cout << "Binary: " << binaryRepresentation << std::endl;
// }

// Fixed::Fixed(const float floating_point)
// {


//     uint32_t intRepresentation;
//     std::memcpy(&intRepresentation, &floating_point, sizeof(float));
//     std::bitset<32> binaryRepresentation(intRepresentation);
//     std::cout << "Binary orig: " << binaryRepresentation << std::endl;

//     std::bitset<32> binaryRepresentation0(floating_point);  
//     std::cout << "Binary: " << binaryRepresentation0 << std::endl;

// 	std::cout << "Float constructor called" << std::endl;
// 	this->_fixedVar = roundf(floating_point * (1 << Fixed::_frac));

//     std::cout << _fixedVar  << std::endl;
//     std::bitset<32> binaryRepresentation(_fixedVar);  
//     std::cout << "Binary: " << binaryRepresentation << std::endl;
// }

// https://calcus.ru/perevod-sistem-schisleniya/iz-dvoichnoy-v-desyatichnuyu?input=eyJudW1iZXIiOiIxMDEwMTAwMTEwMTEwMCIsImZyb20iOiIyIiwidG8iOiIxMCJ9
// http://floatingpoint.ru/online/dec2float.php