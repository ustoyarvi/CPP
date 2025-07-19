#include "Animal.hpp"

Animal::Animal() : type("Animal") {
    std::cout << "Animal created\n";
}

Animal::Animal(const Animal& other) {
    *this = other;
    std::cout << "Animal copied\n";
}

Animal& Animal::operator=(const Animal& other) {
    type = other.type;
    return *this;
}

Animal::~Animal() {
    std::cout << "Animal destroyed\n";
}

std::string Animal::getType() const {
    return type;
}
