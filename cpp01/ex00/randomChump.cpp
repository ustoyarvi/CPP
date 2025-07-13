#include "Zombie.hpp"

void randomChump(std::string name) {
    Zombie zombie(name);  // создаётся на стеке
    zombie.announce();    // автоматически удалится при выходе из функции
}
