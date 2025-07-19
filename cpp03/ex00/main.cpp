#include "ClapTrap.hpp"

int main() {
    ClapTrap a("Hero");
    ClapTrap b("Monster");

    a.attack("Monster");
    b.takeDamage(8);
    b.beRepaired(3);

    a.takeDamage(2);
    a.attack("Monster");      // should not work
    a.beRepaired(4);        // should not work

    return 0;
}
