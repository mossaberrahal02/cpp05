#include <iostream>
#include "Intern.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"

int main()
{
    Intern someRandomIntern;
    Bureaucrat alice("Alice", 1);
    Bureaucrat bob("Bob", 150);

    AForm* form = NULL;

    // creating a ShrubberyCreationForm
    form = someRandomIntern.makeForm("shrubbery creation", "Home");
    if (form)
    {
        std::cout << *form << endl;

        try {
            alice.signForm(*form);
            alice.executeForm(*form);
        }
        catch (const std::exception &e) {
            std::cerr << "Error: " << e.what() << endl;
        }

        delete form;
    }

    std::cout << "--------------------------------" << endl;

    // creating a RobotomyRequestForm
    form = someRandomIntern.makeForm("robotomy request", "Bender");
    if (form)
    {
        std::cout << *form << endl;

        try {
            alice.signForm(*form);
            alice.executeForm(*form);
        }
        catch (const std::exception &e) {
            std::cerr << "Error: " << e.what() << endl;
        }

        delete form;
    }

    std::cout << "--------------------------------" << endl;

    // creating a PresidentialPardonForm
    form = someRandomIntern.makeForm("presidential pardon", "Marvin");
    if (form)
    {
        std::cout << *form << endl;

        try {
            alice.signForm(*form);
            alice.executeForm(*form);
        }
        catch (const std::exception &e) {
            std::cerr << "Error: " << e.what() << endl;
        }

        delete form;
    }

    std::cout << "--------------------------------" << endl;

    // creating an unknown form (should print error)
    form = someRandomIntern.makeForm("unknown form", "Nobody");
    if (form)
    {
        delete form;  // Should never get here
    }

    return 0;
}
