#include "Fixed.hpp"

const int Fixed::_fractionalBits = 8;

// default
Fixed::Fixed() : _rawBits(0) {
    std::cout << "Default constructor called" << std::endl;
}

// int constructor
Fixed::Fixed(const int intVal) {
    std::cout << "Int constructor called" << std::endl;
    _rawBits = intVal << _fractionalBits;
}

// float constructor
Fixed::Fixed(const float floatVal) {
    std::cout << "Float constructor called" << std::endl;
    _rawBits = roundf(floatVal * (1 << _fractionalBits));
}

// copy constructor
Fixed::Fixed(const Fixed& other) {
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

// assignment operator
Fixed& Fixed::operator=(const Fixed& other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        _rawBits = other.getRawBits();
    return *this;
}

// destructor
Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

// getRawBits
int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return _rawBits;
}

// setRawBits
void Fixed::setRawBits(int const raw) {
    _rawBits = raw;
}

// toFloat
float Fixed::toFloat(void) const {
    return (float)_rawBits / (1 << _fractionalBits);
}

// toInt
int Fixed::toInt(void) const {
    return _rawBits >> _fractionalBits;
}

// перегрузка <<
std::ostream& operator<<(std::ostream& out, const Fixed& value) {
    out << value.toFloat();
    return out;
}
