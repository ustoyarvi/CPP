#include "ClapTrap.hpp"

// Constructors / Destructor
ClapTrap::ClapTrap() : name("Default"), hitPoints(10), energyPoints(10), attackDamage(0) {
    std::cout << "ClapTrap " << name << " created (default)" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0) {
    std::cout << "ClapTrap " << name << " created" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) {
    *this = other;
    std::cout << "ClapTrap " << name << " copied" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
    if (this != &other) {
        name = other.name;
        hitPoints = other.hitPoints;
        energyPoints = other.energyPoints;
        attackDamage = other.attackDamage;
    }
    std::cout << "ClapTrap " << name << " assigned" << std::endl;
    return *this;
}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap " << name << " destroyed" << std::endl;
}

// Methods
void ClapTrap::attack(const std::string& target) {
    if (hitPoints == 0 || energyPoints == 0) {
        std::cout << "ClapTrap " << name << " can't attack (no HP or Energy)" << std::endl;
        return;
    }
    --energyPoints;
    std::cout << "ClapTrap " << name << " attacks " << target
              << ", causing " << attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (hitPoints == 0) {
        std::cout << "ClapTrap " << name << " is already destroyed!" << std::endl;
        return;
    }

    hitPoints = (amount >= hitPoints) ? 0 : hitPoints - amount;
    std::cout << "ClapTrap " << name << " takes " << amount << " damage! HP now: "
              << hitPoints << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (hitPoints == 0 || energyPoints == 0) {
        std::cout << "ClapTrap " << name << " can't repair (no HP or Energy)" << std::endl;
        return;
    }

    --energyPoints;
    hitPoints += amount;
    std::cout << "ClapTrap " << name << " repairs itself for " << amount
              << " HP. HP now: " << hitPoints << std::endl;
}
