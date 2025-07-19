#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main() {
    std::cout << "\033[1;36m=== Creating Animal Array ===\033[0m\n";
    Animal* animals[10];

    for (int i = 0; i < 5; ++i)
        animals[i] = new Dog();
    for (int i = 5; i < 10; ++i)
        animals[i] = new Cat();

    std::cout << "\n\033[1;36m=== Deleting Animal Array ===\033[0m\n";
    for (int i = 0; i < 10; ++i)
        delete animals[i];

    // DOG DEEP COPY TESTING
    {
        std::cout << "\033[1;35m\n--- Testing Dog deep copy ---\033[0m\n";
        Dog dog;
        dog.setIdea(0, "Chase the ball!");
        std::cout << "dog idea[0]: " << dog.getIdea(0) << "\n";

        Dog dogCopy(dog);
        std::cout << "dogCopy idea[0]: " << dogCopy.getIdea(0) << "\n";

        dog.setIdea(0, "Eat the bone!");
        std::cout << "After changing dog:\n";
        std::cout << "dog idea[0]: " << dog.getIdea(0) << "\n";
        std::cout << "dogCopy idea[0]: " << dogCopy.getIdea(0) << "\n";
    }

    // CAT DEEP COPY TESTING
    {
        std::cout << "\033[1;35m\n--- Testing Cat deep copy ---\033[0m\n";
        Cat cat;
        cat.setIdea(0, "Nap on the keyboard");
        std::cout << "cat idea[0]: " << cat.getIdea(0) << "\n";

        Cat catCopy(cat);
        std::cout << "catCopy idea[0]: " << catCopy.getIdea(0) << "\n";

        cat.setIdea(0, "Scratch the couch");
        std::cout << "After changing cat:\n";
        std::cout << "cat idea[0]: " << cat.getIdea(0) << "\n";
        std::cout << "catCopy idea[0]: " << catCopy.getIdea(0) << "\n";
    }

    return 0;
}
