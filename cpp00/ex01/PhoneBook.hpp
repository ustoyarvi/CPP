#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <iomanip>
#include <limits>
#include <string>
#include <sstream>

class PhoneBook
{
    private:
        Contact contacts[8];
        int contactCount;
        int oldestContactIndex;
    
    public:
        PhoneBook();
        void addContact();
        void searchContacts() const;
};

#endif