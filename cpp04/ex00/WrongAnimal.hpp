#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal {
protected:
    std::string type;

public:
    WrongAnimal();                                 // Default constructor
    WrongAnimal(const WrongAnimal& other);         // Copy constructor
    WrongAnimal& operator=(const WrongAnimal& other); // Copy assignment
    virtual ~WrongAnimal();                        // Destructor

    std::string getType() const;
    void makeSound() const;
};

#endif
