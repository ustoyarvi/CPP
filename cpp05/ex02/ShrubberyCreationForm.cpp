#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
    : AForm("ShrubberyCreationForm", 145, 137), target(target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(Bureaucrat const& executor) const {
    if (!getIsSigned())
        throw AForm::NotSignedException();
    if (executor.getGrade() > getGradeToExecute())
        throw AForm::GradeTooLowException();

    std::ofstream file((target + "_shrubbery").c_str());
    file << "       ###\n"
            "      #o###\n"
            "    #####o###\n"
            "   #o#\\#|#/###\n"
            "    ###\\|/#o#\n"
            "     # }|{  #\n"
            "       }|{\n";
    file.close();
}
