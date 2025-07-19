#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap {
protected:
    std::string     name;
    unsigned int    hitPoints;
    unsigned int    energyPoints;
    unsigned int    attackDamage;

public:
    ClapTrap();                                // default constructor
    ClapTrap(std::string name);                // name constructor
    ClapTrap(const ClapTrap& other);           // copy constructor
    ClapTrap& operator=(const ClapTrap& other);// assignment operator
    virtual ~ClapTrap();                       // destructor  virtual! 

    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
};

#endif
