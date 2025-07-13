#include "Zombie.hpp"

int main() {
    int n = 3; // А сколько зомби осилишь ты, воин ?
    Zombie* horde = zombieHorde(n, "HordeZombie");

    if (!horde)
        return 1;

    for (int i = 0; i < n; ++i) {
        horde[i].announce();
    }

    delete[] horde;
    return 0;
}
