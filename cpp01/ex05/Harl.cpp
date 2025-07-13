#include "Harl.hpp"

void Harl::debug(void) {
    std::cout << "[ DEBUG ]\n";
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger.\n";
}

void Harl::info(void) {
    std::cout << "[ INFO ]\n";
    std::cout << "I cannot believe adding extra bacon costs more money.\n";
}

void Harl::warning(void) {
    std::cout << "[ WARNING ]\n";
    std::cout << "I think I deserve some extra bacon for free.\n";
}

void Harl::error(void) {
    std::cout << "[ ERROR ]\n";
    std::cout << "This is unacceptable! I want to speak to the manager now.\n";
}

void Harl::complain(std::string level) {
    std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    void (Harl::*funcs[])() = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };

    for (int i = 0; i < 4; ++i) {
        if (level == levels[i]) {
            (this->*funcs[i])();  // Вызов метода по указателю
            return;
        }
    }

    std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
}
