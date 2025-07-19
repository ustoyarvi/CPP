#include "Dog.hpp"

Dog::Dog() {
    type = "Dog";
    std::cout << "Dog created\n";
}

Dog::Dog(const Dog& other) : Animal(other) {
    *this = other;
    std::cout << "Dog copied\n";
}

Dog& Dog::operator=(const Dog& other) {
    Animal::operator=(other);
    return *this;
}

Dog::~Dog() {
    std::cout << "Dog destroyed\n";
}

void Dog::makeSound() const {
    std::cout << "Woof!\n";
}
