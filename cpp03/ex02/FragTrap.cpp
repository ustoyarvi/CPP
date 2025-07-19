#include "FragTrap.hpp"

FragTrap::FragTrap() {
    name = "Default";
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
    std::cout << "FragTrap " << name << " created (default)" << std::endl;
}

FragTrap::FragTrap(std::string n) {
    name = n;
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
    std::cout << "FragTrap " << name << " created" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
    *this = other;
    std::cout << "FragTrap " << name << " copied" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
    if (this != &other) {
        name = other.name;
        hitPoints = other.hitPoints;
        energyPoints = other.energyPoints;
        attackDamage = other.attackDamage;
    }
    std::cout << "FragTrap " << name << " assigned" << std::endl;
    return *this;
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap " << name << " destroyed" << std::endl;
}

void FragTrap::highFivesGuys(void) {
    std::cout << "FragTrap " << name << " requests a high five! 🙌" << std::endl;
}
