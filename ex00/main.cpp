#include "Bureaucrat.hpp"

int main() {
    try {
        Bureaucrat b1("Alice", 50);
        std::cout << b1 << endl;

        b1.increment();
        std::cout << "After incrementing: " << b1 << endl;

        b1.decrement();
        std::cout << "After decrementing: " << b1 << endl;

        Bureaucrat b2("Bob", 1);  // Grade 1, the highest
        std::cout << b2 << endl;
        b2.increment();  // This should throw an exception
    } catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << endl;
    }

    try {
        Bureaucrat b3("Charlie", 150);  // Grade 150, the lowest
        std::cout << b3 << endl;
        b3.decrement();  // This should throw an exception
    } catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << endl;
    }

    try {
        Bureaucrat b4("Diana", 0);  // Grade 0 is too high
        std::cout << b4 << endl;
    } catch (std::exception& e) {
        std::cout << "Exception caught during creation: " << e.what() << endl;
    }

    try {
        Bureaucrat b5("Eve", 151);  // Grade 151 is too low
        std::cout << b5 << endl;
    } catch (std::exception& e) {
        std::cout << "Exception caught during creation: " << e.what() << endl;
    }

    return 0;
}
