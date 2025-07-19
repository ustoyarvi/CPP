#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat() {
    type = "WrongCat";
    std::cout << "WrongCat default Constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other) {
    std::cout << "WrongCat copy Constructor called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other) {
    if (this != &other) {
        type = other.type;
    }
    std::cout << "WrongCat copy assignment operator called" << std::endl;
    return *this;
}

WrongCat::~WrongCat() {
    std::cout << "WrongCat Destructor called" << std::endl;
}

void WrongCat::makeSound() const {
    std::cout << "WrongCat meows" << std::endl;
}
