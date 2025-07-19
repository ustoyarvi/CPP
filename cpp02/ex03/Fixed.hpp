#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
private:
    int                 _rawBits;
    static const int    _fractionalBits;

public:
    // Orthodox Canonical Form
    Fixed();
    Fixed(const int intVal);
    Fixed(const float floatVal);
    Fixed(const Fixed& other);
    Fixed& operator=(const Fixed& other);
    ~Fixed();

    // Comparison operators
    bool operator>(const Fixed& other) const;
    bool operator<(const Fixed& other) const;
    bool operator>=(const Fixed& other) const;
    bool operator<=(const Fixed& other) const;
    bool operator==(const Fixed& other) const;
    bool operator!=(const Fixed& other) const;

    // Arithmetic operators
    Fixed operator+(const Fixed& other) const;
    Fixed operator-(const Fixed& other) const;
    Fixed operator*(const Fixed& other) const;
    Fixed operator/(const Fixed& other) const;

    // Increment/Decrement
    Fixed& operator++();     // prefix ++
    Fixed operator++(int);   // postfix ++
    Fixed& operator--();     // prefix --
    Fixed operator--(int);   // postfix --

    // Getters / Setters
    int getRawBits(void) const;
    void setRawBits(int const raw);

    float toFloat(void) const;
    int toInt(void) const;

    // Min/Max
    static Fixed& min(Fixed& a, Fixed& b);
    static const Fixed& min(const Fixed& a, const Fixed& b);
    static Fixed& max(Fixed& a, Fixed& b);
    static const Fixed& max(const Fixed& a, const Fixed& b);
};

// <<
std::ostream& operator<<(std::ostream& out, const Fixed& value);

#endif
