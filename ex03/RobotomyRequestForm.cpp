#include "RobotomyRequestForm.hpp"
#include <cstddef>

RobotomyRequestForm::RobotomyRequestForm(const str &target)
    : AForm("Robotomy Request", 72, 45), target(target) {}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
    if (!getSignedBook())
        throw AForm::FormNotSignedException(); // Form not signed

    if (executor.getGrade() > getGradeToExecute())
        throw AForm::GradeTooLowException(); // Not enough grade to execute

    std::srand(std::time(NULL));
    int success = std::rand() % 2;
    std::cout << "Drilling noises... ";

    if (success)
        std::cout << target << " has been robotomized successfully." << endl;
    else
        std::cout << "Robotomy failed for " << target << "." << endl;
}

RobotomyRequestForm::RobotomyRequestForm()
    : AForm("Robotomy Request", 72, 45), target("Default") {}


RobotomyRequestForm::~RobotomyRequestForm()throw ()
{
    
}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm & obj) : AForm(obj)
{
}
RobotomyRequestForm & RobotomyRequestForm::operator=(const RobotomyRequestForm & obj)
{
    AForm::operator=(obj);
    return *this;
}
