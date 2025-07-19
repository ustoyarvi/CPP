#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);

int main(void) {
    Point a(0, 0);
    Point b(5, 0);
    Point c(0, 5);

    Point inside(1, 1);
    Point edge(0, 0);
    Point outside(6, 6);

    std::cout << "Point (1,1): " << (bsp(a, b, c, inside) ? "Inside" : "Outside") << std::endl;
    std::cout << "Point (0,0): " << (bsp(a, b, c, edge) ? "Inside" : "Outside") << std::endl;
    std::cout << "Point (6,6): " << (bsp(a, b, c, outside) ? "Inside" : "Outside") << std::endl;

    return 0;
}
