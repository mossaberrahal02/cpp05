#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const str &target)
    : AForm("Presidential Pardon", 25, 5), target(target) {}


PresidentialPardonForm::PresidentialPardonForm()
: AForm("Presidential Pardon", 25, 5), target("Default") {}

PresidentialPardonForm::~PresidentialPardonForm() throw ()
{

}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm & obj):AForm(obj)
{
    
}

PresidentialPardonForm & PresidentialPardonForm::operator=(const PresidentialPardonForm & obj)
{
    AForm::operator=(obj);
    return *this;
}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
    if (!getSignedBook())
        throw AForm::GradeTooLowException(); // Form not signed

    if (executor.getGrade() > getGradeToExecute())
        throw AForm::GradeTooLowException(); // Not enough grade to execute

    // Execute the presidential pardon
    std::cout << target << " has been pardoned by Zaphod Beeblebrox." << endl;
}

