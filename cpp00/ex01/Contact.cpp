#include "Contact.hpp"

void Contact::setFirstName(const std::string &value) {
    firstName = value;
}

void Contact::setLastName(const std::string &value) {
    lastName = value;
}

void Contact::setNickName(const std::string &value) {
    nickname = value;
}

void Contact:: setPhoneNumber(const std::string &value) {
    phoneNumber = value;
}

void Contact::setDarkestSecret(const std::string &value) {
    darkestSecret = value;
}

std::string Contact::getFirstName() const {
    return firstName;
}

std::string Contact::getLastName() const {
    return lastName;
}

std::string Contact::getNickName() const {
    return nickname;
}

std::string Contact::getPhoneNumber() const {
    return phoneNumber;
}

std::string Contact::getDarkestSecret() const {
    return darkestSecret;
}