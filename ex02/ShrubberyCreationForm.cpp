#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(const str &target)
    : AForm("Shrubbery Creation", 145, 137), target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("Shrubbery Creation", 145, 137), target("Default") {}
ShrubberyCreationForm::~ShrubberyCreationForm()throw ()
{
    
}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm & obj) : AForm(obj)
{
}
ShrubberyCreationForm & ShrubberyCreationForm::operator=(const ShrubberyCreationForm & obj)
{
    AForm::operator=(obj);
    return *this;
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
    if (!getSignedBook())
        throw AForm::GradeTooLowException(); // Form not signed

    if (executor.getGrade() > getGradeToExecute())
        throw AForm::GradeTooLowException(); // Not enough grade to execute

    // Create the target file and write ASCII tree into it
    std::ofstream outfile((target + "_shrubbery").c_str());
    if (outfile.is_open())
    {
        outfile << "     ^\n";
        outfile << "    ^^^\n";
        outfile << "   ^^^^^\n";
        outfile << "  ^^^^^^^\n";
        outfile << " ^^^^^^^^^\n";
        outfile << "^^^^^^^^^^^\n";
        outfile << "     |||\n";
        outfile.close();
    }
    else
        std::cerr << "Error creating the shrubbery file." << endl;
}