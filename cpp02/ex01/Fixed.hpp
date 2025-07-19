#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
private:
    int                 _rawBits;
    static const int    _fractionalBits;

public:
    Fixed();                              // default constructor
    Fixed(const int intVal);              // int constructor
    Fixed(const float floatVal);          // float constructor
    Fixed(const Fixed& other);            // copy constructor
    Fixed& operator=(const Fixed& other); // copy assignment operator
    ~Fixed();                             // destructor

    int     getRawBits(void) const;
    void    setRawBits(int const raw);
    float   toFloat(void) const;
    int     toInt(void) const;
};

// << перегрузка
std::ostream& operator<<(std::ostream& out, const Fixed& value);

#endif
