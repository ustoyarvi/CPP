#include "ScavTrap.hpp"

// Конструкторы и деструктор
ScavTrap::ScavTrap() {
    name = "Default";
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
    std::cout << "ScavTrap " << name << " created (default)" << std::endl;
}

ScavTrap::ScavTrap(std::string n) {
    name = n;
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
    std::cout << "ScavTrap " << name << " created" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {
    *this = other;
    std::cout << "ScavTrap " << name << " copied" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
    if (this != &other) {
        name = other.name;
        hitPoints = other.hitPoints;
        energyPoints = other.energyPoints;
        attackDamage = other.attackDamage;
    }
    std::cout << "ScavTrap " << name << " assigned" << std::endl;
    return *this;
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap " << name << " destroyed" << std::endl;
}

// Переопределённый метод
void ScavTrap::attack(const std::string& target) {
    if (hitPoints == 0 || energyPoints == 0) {
        std::cout << "ScavTrap " << name << " can't attack" << std::endl;
        return;
    }
    --energyPoints;
    std::cout << "ScavTrap " << name << " attacks " << target
              << ", causing " << attackDamage << " points of damage!" << std::endl;
}

// Новый метод
void ScavTrap::guardGate() {
    std::cout << "ScavTrap " << name << " is now in Gate Keeper mode!" << std::endl;
}
