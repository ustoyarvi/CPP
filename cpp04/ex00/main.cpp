#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << j->getType() << " makes sound: ";
    j->makeSound();

    std::cout << i->getType() << " makes sound: ";
    i->makeSound();

    meta->makeSound();

    std::cout << "\n--- Wrong version ---\n";
    const WrongAnimal* wrong = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();

    std::cout << wrongCat->getType() << " makes sound: ";
    wrongCat->makeSound(); // ❌ вызывает WrongAnimal::makeSound

    wrong->makeSound();

    delete meta;
    delete j;
    delete i;
    delete wrong;
    delete wrongCat;

    return 0;
}
