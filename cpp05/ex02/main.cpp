#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    try {
        Bureaucrat bob("Bob", 1); // самый высокий ранг

        ShrubberyCreationForm shrub("garden");
        RobotomyRequestForm robot("Bender");
        PresidentialPardonForm pardon("Ford Prefect");

        // Попытка подписать все формы
        bob.signForm(shrub);
        bob.signForm(robot);
        bob.signForm(pardon);

        // Попытка исполнить все формы
        bob.executeForm(shrub);
        bob.executeForm(robot);
        bob.executeForm(pardon);
    }
    catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
