#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    try {
        Bureaucrat bob("Bob", 100);
        Bureaucrat alice("Alice", 30);

        Form formA("FormA", 50, 20);

        std::cout << formA << std::endl;

        bob.signForm(formA);   // недостаточный ранг
        alice.signForm(formA); // успешная подпись

        std::cout << formA << std::endl;

    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
