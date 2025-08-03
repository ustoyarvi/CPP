#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main() {
    try {
        Bureaucrat bob("Bob", 1); // самый высокий ранг

        Intern intern;

        // Правильный запрос формы
        AForm* form1 = intern.makeForm("robotomy request", "Bender");
        if (form1) {
            bob.signForm(*form1);
            bob.executeForm(*form1);
            delete form1;
        }

        // Неверное имя формы
        AForm* form2 = intern.makeForm("coffee request", "Machine");
        if (form2)
            delete form2;

        // Создание shrubbery и выполнение
        AForm* form3 = intern.makeForm("shrubbery creation", "garden");
        if (form3) {
            bob.signForm(*form3);
            bob.executeForm(*form3);
            delete form3;
        }

        // Создание pardon
        AForm* form4 = intern.makeForm("presidential pardon", "Arthur Dent");
        if (form4) {
            bob.signForm(*form4);
            bob.executeForm(*form4);
            delete form4;
        }

    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
