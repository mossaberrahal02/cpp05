#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    try
    {
        Bureaucrat highBureaucrat("HighBureaucrat", 15);
        Bureaucrat lowBureaucrat("LowBureaucrat", 88);

        ShrubberyCreationForm shrubberyForm("Home");
        RobotomyRequestForm robotomyForm("Bob");
        PresidentialPardonForm pardonForm("Alice");

        std::cout << "Before signing:\n";
        std::cout << "Shrubbery Form signed: " << shrubberyForm.getSignedBook() << endl;
        std::cout << "Shrubbery Form signed: " << shrubberyForm.getSignedBook() << endl;
        std::cout << "Shrubbery Form signed: " << shrubberyForm.getSignedBook() << endl;
        std::cout << "Robotomy Form signed: " << robotomyForm.getSignedBook() << endl;
        std::cout << "Pardon Form signed: " << pardonForm.getSignedBook() << endl;

        highBureaucrat.signForm(shrubberyForm);
        highBureaucrat.signForm(robotomyForm);
        highBureaucrat.signForm(pardonForm);

        
        lowBureaucrat.signForm(shrubberyForm);
        lowBureaucrat.signForm(robotomyForm); 
        lowBureaucrat.signForm(pardonForm);   

        std::cout << "Before signing:\n";
        std::cout << "Shrubbery Form signed: " << shrubberyForm.getSignedBook() << endl;
        std::cout << "Robotomy Form signed: " << robotomyForm.getSignedBook() << endl;
        std::cout << "Pardon Form signed: " << pardonForm.getSignedBook() << endl;


        highBureaucrat.executeForm(shrubberyForm);  
        highBureaucrat.executeForm(robotomyForm);   
        highBureaucrat.executeForm(pardonForm);     
        lowBureaucrat.executeForm(shrubberyForm);   
        lowBureaucrat.executeForm(robotomyForm);    
        lowBureaucrat.executeForm(pardonForm);      
    }
    catch (const std::exception &e)
    {
        std::cout << "Exception: " << e.what() << endl;
    }

    return 0;
}
