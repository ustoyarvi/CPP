#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie {
private:
    std::string name;  // имя зомби

public:
    Zombie(std::string name);  // Конструктор : вызывается при создании зомби
    ~Zombie();                 // Деструктор : вызывается при удалении зомби

    void announce(void);       // зомби говорит "BraiiiiiiinnnzzzZ..."
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);


#endif
