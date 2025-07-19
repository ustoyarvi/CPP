#include "Point.hpp"

// Вычисляет векторное произведение AB × AP
static Fixed cross(Point const& a, Point const& b, Point const& p) {
    Fixed abx = b.getX() - a.getX();
    Fixed aby = b.getY() - a.getY();
    Fixed apx = p.getX() - a.getX();
    Fixed apy = p.getY() - a.getY();
    return abx * apy - aby * apx;
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
    Fixed cp1 = cross(a, b, point);
    Fixed cp2 = cross(b, c, point);
    Fixed cp3 = cross(c, a, point);

    // 🔴 Проверка: если точка лежит на границе (cross == 0) — возвращаем false
    if (cp1 == Fixed(0) || cp2 == Fixed(0) || cp3 == Fixed(0))
        return false;

    // ✅ Если все знаки совпадают — точка строго внутри
    bool has_neg = (cp1 < 0) || (cp2 < 0) || (cp3 < 0);
    bool has_pos = (cp1 > 0) || (cp2 > 0) || (cp3 > 0);

    return !(has_neg && has_pos);
}
