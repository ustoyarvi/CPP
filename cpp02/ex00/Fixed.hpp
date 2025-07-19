#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
private:
    int                 _rawBits;
    static const int    _fractionalBits;

public:
    Fixed();                                // Конструктор по умолчанию
    Fixed(const Fixed& other);              // Копирующий конструктор
    Fixed& operator=(const Fixed& other);   // Оператор присваивания
    ~Fixed();                               // Деструктор

    int getRawBits(void) const;
    void setRawBits(int const raw);
};

#endif
