#include "Fixed.hpp"

const int Fixed::_fractionalBits = 8;

// Конструктор по умолчанию
Fixed::Fixed() : _rawBits(0) {
    std::cout << "Default constructor called" << std::endl;
}

// Копирующий конструктор
Fixed::Fixed(const Fixed& other) {
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

// Оператор присваивания
Fixed& Fixed::operator=(const Fixed& other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        this->_rawBits = other.getRawBits();
    return *this;
}

// Деструктор
Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

// Геттер
int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return _rawBits;
}

// Сеттер
void Fixed::setRawBits(int const raw) {
    _rawBits = raw;
}
