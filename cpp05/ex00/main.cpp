#include "Bureaucrat.hpp"

int main() {
    // Попытка создать бюрократа с недопустимо низким grade
    try {
        Bureaucrat low("TooLow", 151);
    } catch (std::exception& e) {
        std::cout << "Exception on TooLow: " << e.what() << std::endl;
    }

    // Попытка создать бюрократа с недопустимо высоким grade
    try {
        Bureaucrat high("TooHigh", 0);
    } catch (std::exception& e) {
        std::cout << "Exception on TooHigh: " << e.what() << std::endl;
    }

    // Нормальный случай
    try {
        Bureaucrat bob("Bob", 2);
        std::cout << bob << std::endl;

        // Повышаем Bob до 1
        bob.incrementGrade();
        std::cout << "After increment: " << bob << std::endl;

        // Попытка повысить за границу (должно вызвать исключение)
        bob.incrementGrade();
    } catch (std::exception& e) {
        std::cout << "Exception on Bob: " << e.what() << std::endl;
    }

    try {
        Bureaucrat jim("Jim", 149);
        std::cout << jim << std::endl;

        // Понижаем до 150
        jim.decrementGrade();
        std::cout << "After decrement: " << jim << std::endl;

        // Понижаем ещё раз — ошибка
        jim.decrementGrade();
    } catch (std::exception& e) {
        std::cout << "Exception on Jim: " << e.what() << std::endl;
    }

    return 0;
}
