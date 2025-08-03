#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : name("Default"), isSigned(false), gradeToSign(150), gradeToExecute(150) {}

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute)
    : name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute) {
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}

AForm::AForm(const AForm& other)
    : name(other.name), isSigned(other.isSigned),
      gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute) {}

AForm& AForm::operator=(const AForm& other) {
    if (this != &other)
        isSigned = other.isSigned;
    return *this;
}

AForm::~AForm() {}

const std::string& AForm::getName() const { return name; }
bool AForm::getIsSigned() const { return isSigned; }
int AForm::getGradeToSign() const { return gradeToSign; }
int AForm::getGradeToExecute() const { return gradeToExecute; }

void AForm::beSigned(const Bureaucrat& b) {
    if (b.getGrade() > gradeToSign)
        throw GradeTooLowException();
    isSigned = true;
}

const char* AForm::GradeTooHighException::what() const throw() {
    return "AForm: grade too high";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "AForm: grade too low";
}

const char* AForm::NotSignedException::what() const throw() {
    return "AForm: not signed";
}

std::ostream& operator<<(std::ostream& out, const AForm& f) {
    out << "Form \"" << f.getName() << "\", signed: " << std::boolalpha << f.getIsSigned()
        << ", grade to sign: " << f.getGradeToSign()
        << ", grade to execute: " << f.getGradeToExecute();
    return out;
}
