#include "Fixed.hpp"

const int Fixed::_fractionalBits = 8;

// Constructors / Destructor
Fixed::Fixed() : _rawBits(0) {}
Fixed::Fixed(const int intVal) {
    _rawBits = intVal << _fractionalBits;
}
Fixed::Fixed(const float floatVal) {
    _rawBits = roundf(floatVal * (1 << _fractionalBits));
}
Fixed::Fixed(const Fixed& other) {
    *this = other;
}
Fixed& Fixed::operator=(const Fixed& other) {
    if (this != &other)
        _rawBits = other._rawBits;
    return *this;
}
Fixed::~Fixed() {}

// Comparison operators
bool Fixed::operator>(const Fixed& other) const { return _rawBits > other._rawBits; }
bool Fixed::operator<(const Fixed& other) const { return _rawBits < other._rawBits; }
bool Fixed::operator>=(const Fixed& other) const { return _rawBits >= other._rawBits; }
bool Fixed::operator<=(const Fixed& other) const { return _rawBits <= other._rawBits; }
bool Fixed::operator==(const Fixed& other) const { return _rawBits == other._rawBits; }
bool Fixed::operator!=(const Fixed& other) const { return _rawBits != other._rawBits; }

// Arithmetic operators
Fixed Fixed::operator+(const Fixed& other) const {
    return Fixed(this->toFloat() + other.toFloat());
}
Fixed Fixed::operator-(const Fixed& other) const {
    return Fixed(this->toFloat() - other.toFloat());
}
Fixed Fixed::operator*(const Fixed& other) const {
    return Fixed(this->toFloat() * other.toFloat());
}
Fixed Fixed::operator/(const Fixed& other) const {
    return Fixed(this->toFloat() / other.toFloat());
}

// Increment / Decrement
Fixed& Fixed::operator++() {
    ++_rawBits;
    return *this;
}
Fixed Fixed::operator++(int) {
    Fixed tmp(*this);
    _rawBits++;
    return tmp;
}
Fixed& Fixed::operator--() {
    --_rawBits;
    return *this;
}
Fixed Fixed::operator--(int) {
    Fixed tmp(*this);
    _rawBits--;
    return tmp;
}

// Getters / Setters
int Fixed::getRawBits(void) const {
    return _rawBits;
}
void Fixed::setRawBits(int const raw) {
    _rawBits = raw;
}
float Fixed::toFloat(void) const {
    return (float)_rawBits / (1 << _fractionalBits);
}
int Fixed::toInt(void) const {
    return _rawBits >> _fractionalBits;
}

// Min/Max
Fixed& Fixed::min(Fixed& a, Fixed& b) {
    return (a < b ? a : b);
}
const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
    return (a < b ? a : b);
}
Fixed& Fixed::max(Fixed& a, Fixed& b) {
    return (a > b ? a : b);
}
const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
    return (a > b ? a : b);
}

// <<
std::ostream& operator<<(std::ostream& out, const Fixed& value) {
    out << value.toFloat();
    return out;
}
