#include "ScalarConverter.hpp"
#include <iostream>      // std::cout, std::endl
#include <cstdlib>       // std::atoi, std::strtof, std::strtod
#include <cctype>        // std::isdigit, std::isprint
#include <iomanip>       // std::setprecision, std::fixed
#include <cmath>         // std::isnan, std::isinf (на будущее)
#include <limits>        // std::numeric_limits (для проверки int переполнений)

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter&) {}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter&) { return *this; }
ScalarConverter::~ScalarConverter() {}

// Определение типа литерала
ScalarConverter::Type ScalarConverter::detectType(std::string const& literal) {
    // Спец float литералы
    if (literal == "-inff" || literal == "+inff" || literal == "nanf")
        return TYPE_FLOAT;

    // Спец double литералы
    if (literal == "-inf" || literal == "+inf" || literal == "nan")
        return TYPE_DOUBLE;

    // Один отображаемый символ (но не цифра)
    if (literal.length() == 1 && std::isprint(literal[0]) && !std::isdigit(literal[0]))
        return TYPE_CHAR;

    // Float с суффиксом f (например, 42.0f)
    if (literal[literal.length() - 1] == 'f') {
        std::string core = literal.substr(0, literal.length() - 1);
        char* endptr = NULL;
        std::strtof(core.c_str(), &endptr);
        if (*endptr == '\0')
            return TYPE_FLOAT;
    }

    // Double (с точкой, без f)
    {
        char* endptr = NULL;
        std::strtod(literal.c_str(), &endptr);
        if (*endptr == '\0' && literal.find('.') != std::string::npos)
            return TYPE_DOUBLE;
    }

    // Int (целое число)
    {
        char* endptr = NULL;
        std::strtol(literal.c_str(), &endptr, 10);
        if (*endptr == '\0')
            return TYPE_INT;
    }

    return TYPE_UNKNOWN;
}

// Преобразование и вывод значений
void ScalarConverter::convert(std::string const& literal) {
    Type type = detectType(literal);

    char    c = 0;
    int     i = 0;
    float   f = 0.0f;
    double  d = 0.0;

    // Приведение значений по типу
    switch (type) {
        case TYPE_CHAR:
            c = literal[0];
            i = static_cast<int>(c);
            f = static_cast<float>(c);
            d = static_cast<double>(c);
            break;
        case TYPE_INT:
            i = std::atoi(literal.c_str());
            c = static_cast<char>(i);
            f = static_cast<float>(i);
            d = static_cast<double>(i);
            break;
        case TYPE_FLOAT:
            f = std::strtof(literal.c_str(), NULL);
            c = static_cast<char>(f);
            i = static_cast<int>(f);
            d = static_cast<double>(f);
            break;
        case TYPE_DOUBLE:
            d = std::strtod(literal.c_str(), NULL);
            c = static_cast<char>(d);
            i = static_cast<int>(d);
            f = static_cast<float>(d);
            break;
        case TYPE_UNKNOWN:
        default:
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: impossible" << std::endl;
            std::cout << "double: impossible" << std::endl;
            return;
    }

    // Вывод char
    std::cout << "char: ";
    if ((type == TYPE_FLOAT && (literal == "nanf" || literal == "+inff" || literal == "-inff")) ||
        (type == TYPE_DOUBLE && (literal == "nan" || literal == "+inf" || literal == "-inf")) ||
        i < 0 || i > 127)
        std::cout << "impossible" << std::endl;
    else if (!std::isprint(c))
        std::cout << "Non displayable" << std::endl;
    else
        std::cout << "'" << c << "'" << std::endl;

    // Вывод int
    std::cout << "int: ";
    if ((type == TYPE_FLOAT && (literal == "nanf" || literal == "+inff" || literal == "-inff")) ||
        (type == TYPE_DOUBLE && (literal == "nan" || literal == "+inf" || literal == "-inf")) ||
        d > static_cast<double>(std::numeric_limits<int>::max()) ||
        d < static_cast<double>(std::numeric_limits<int>::min()))
        std::cout << "impossible" << std::endl;
    else
        std::cout << i << std::endl;

    // Вывод float с точностью 1
    std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;

    // Вывод double с точностью 1
    std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
}
