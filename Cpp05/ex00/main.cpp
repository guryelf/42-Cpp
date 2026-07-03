#include "Bureaucrat.hpp"


int main() {
    try {
        Bureaucrat high("Boss", 0); // Should throw GradeTooHighException
    }
    catch (const std::exception& e) {
        std::cout << "Test 1: " << e.what() << std::endl;
    }

    try {
        Bureaucrat low("Intern", 151); // Should throw GradeTooLowException
    }
    catch (const std::exception& e) {
        std::cout << "Test 2: " << e.what() << std::endl;
    }

    return 0;
}
