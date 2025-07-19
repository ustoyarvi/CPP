#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main() {
    const int SIZE = 6;
    Animal* animals[SIZE];

    for (int i = 0; i < SIZE / 2; ++i)
        animals[i] = new Dog();
    for (int i = SIZE / 2; i < SIZE; ++i)
        animals[i] = new Cat();

    std::cout << "\nDeleting all animals:\n";
    for (int i = 0; i < SIZE; ++i)
        delete animals[i];

    return 0;
}
