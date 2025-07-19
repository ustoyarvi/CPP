#include "FragTrap.hpp"

int main() {
    FragTrap f("Hero");

    f.attack("the Monster");
    f.takeDamage(40);
    f.beRepaired(20);
    f.highFivesGuys();

    return 0;
}
