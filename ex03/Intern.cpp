#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

// Static array of known form creators
const Intern::FormEntry Intern::formEntries[] = {
    { "shrubbery creation", &Intern::createShrubbery },
    { "robotomy request", &Intern::createRobotomy },
    { "presidential pardon", &Intern::createPresidential },
};

AForm* Intern::createShrubbery(const std::string & target)
{
    return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomy(const std::string & target)
{
    return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidential(const std::string & target)
{
    return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const std::string & formName, const std::string & target) const
{
    for (size_t i = 0; i < (sizeof(formEntries) / sizeof(FormEntry)); i++)
    {
        if (formEntries[i].name == formName)
        {
            std::cout << "Intern creates " << formName << endl;
            return formEntries[i].createFunc(target);
        }
    }
    std::cerr << "Intern: Error! Form \"" << formName << "\" does not exist." << endl;
    return NULL;
}
