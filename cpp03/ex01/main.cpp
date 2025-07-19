#include "ScavTrap.hpp"

int main() {
    ScavTrap s("Hero");

    s.attack("Monster");
    s.takeDamage(30);
    s.beRepaired(20);
    s.guardGate();

    return 0;
}
