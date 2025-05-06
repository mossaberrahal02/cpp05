#include "Form.hpp"
#include "Bureaucrat.hpp"

int main() {
    try {
        Bureaucrat bob("Bob", 50);
        Form formA("FormA", 45, 30);

        std::cout << "Initial Form State:\n" << formA << "\n";
        bob.signForm(formA);  // Should fail because 50 > 45

        Bureaucrat alice("Alice", 20);
        alice.signForm(formA);  // Should succeed

        std::cout << "Form After Signing Attempt:\n" << formA << "\n";
    }
    catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << '\n';
    }

    try {
        // Grade too high
        Form badFormHigh("TooHigh", 0, 30);
    } catch (const std::exception &e) {
        std::cerr << "Caught Exception (Too High): " << e.what() << '\n';
    }

    try {
        // Grade too low
        Form badFormLow("TooLow", 151, 30);
    } catch (const std::exception &e) {
        std::cerr << "Caught Exception (Too Low): " << e.what() << '\n';
    }

    return 0;
}
