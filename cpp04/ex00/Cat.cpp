#include "Cat.hpp"

Cat::Cat() {
    type = "Cat";
    std::cout << "Cat created\n";
}

Cat::Cat(const Cat& other) : Animal(other) {
    *this = other;
    std::cout << "Cat copied\n";
}

Cat& Cat::operator=(const Cat& other) {
    Animal::operator=(other);
    return *this;
}

Cat::~Cat() {
    std::cout << "Cat destroyed\n";
}

void Cat::makeSound() const {
    std::cout << "Meow!\n";
}
