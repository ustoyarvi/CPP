#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal") {
    std::cout << "WrongAnimal default Constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) {
    type = other.type;
    std::cout << "WrongAnimal copy Constructor called" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
    if (this != &other)
        type = other.type;
    std::cout << "WrongAnimal copy assignment operator called" << std::endl;
    return *this;
}

WrongAnimal::~WrongAnimal() {
    std::cout << "WrongAnimal Destructor called" << std::endl;
}

std::string WrongAnimal::getType() const {
    return type;
}

void WrongAnimal::makeSound() const {
    std::cout << "* wrong animal noise *" << std::endl;
}
