#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : contactCount(0), oldestContactIndex(0) {}

// Удаляет пробелы и табуляцию с начала и конца строки
static std::string trim(const std::string& str) {
    size_t start = 0;
    while (start < str.length() && (str[start] == ' ' || str[start] == '\t'))
        start++;

    size_t end = str.length();
    while (end > start && (str[end - 1] == ' ' || str[end - 1] == '\t'))
        end--;

    return str.substr(start, end - start);
}

void PhoneBook::addContact() {
    Contact newContact;
    std::string input;

    do {
        std::cout << "Enter first name: ";
        std::getline(std::cin, input);
        input = trim(input);
    } while (input.empty());
    newContact.setFirstName(input);

    do {
        std::cout << "Enter last name: ";
        std::getline(std::cin, input);
        input = trim(input);
    } while (input.empty());
    newContact.setLastName(input);

    do {
        std::cout << "Enter nickname: ";
        std::getline(std::cin, input);
        input = trim(input);
    } while (input.empty());
    newContact.setNickname(input);

    do {
        std::cout << "Enter phone number: ";
        std::getline(std::cin, input);
        input = trim(input);
    } while (input.empty());
    newContact.setPhoneNumber(input);

    do {
        std::cout << "Enter darkest secret: ";
        std::getline(std::cin, input);
        input = trim(input);
    } while (input.empty());
    newContact.setDarkestSecret(input);

    if (contactCount < 8) {
        contacts[contactCount++] = newContact;
    } else {
        contacts[oldestContactIndex] = newContact;
        oldestContactIndex = (oldestContactIndex + 1) % 8;
    }
}

static std::string formatField(const std::string& field) {
    if (field.length() > 10)
        return field.substr(0, 9) + ".";
    else
        return field;
}

void PhoneBook::searchContacts() const {
    std::cout << std::setw(10) << "Index" << "|"
              << std::setw(10) << "First Name" << "|"
              << std::setw(10) << "Last Name" << "|"
              << std::setw(10) << "Nickname" << std::endl;
    for (int i = 0; i < contactCount; ++i) {
        std::cout << std::setw(10) << i << "|"
                  << std::setw(10) << formatField(contacts[i].getFirstName()) << "|"
                  << std::setw(10) << formatField(contacts[i].getLastName()) << "|"
                  << std::setw(10) << formatField(contacts[i].getNickname()) << std::endl;
    }

    if (contactCount == 0) {
        std::cout << "Phonebook is empty.\n";
        return;
    }

    std::cout << "Enter index to view details: ";
    std::string input;
    std::getline(std::cin, input);

    // Проверяем, что строка состоит только из цифр
    bool isNumber = !input.empty() && input.find_first_not_of("0123456789") == std::string::npos;
    int index = -1;
    if (isNumber) {
        std::istringstream iss(input);
        iss >> index;
    }

    if (!isNumber || index < 0 || index >= contactCount) {
        std::cout << "Invalid index!" << std::endl;
        return;
    }

    std::cout << "First Name: " << contacts[index].getFirstName() << std::endl;
    std::cout << "Last Name: " << contacts[index].getLastName() << std::endl;
    std::cout << "Nickname: " << contacts[index].getNickname() << std::endl;
    std::cout << "Phone Number: " << contacts[index].getPhoneNumber() << std::endl;
    std::cout << "Darkest Secret: " << contacts[index].getDarkestSecret() << std::endl;
}