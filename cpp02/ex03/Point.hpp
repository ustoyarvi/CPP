#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point {
private:
    const Fixed _x;
    const Fixed _y;

public:
    Point();
    Point(const float x, const float y);
    Point(const Point& other);
    Point& operator=(const Point& other); // нужен, даже если не копирует
    ~Point();

    Fixed getX() const;
    Fixed getY() const;
};

#endif
