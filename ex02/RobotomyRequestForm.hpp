#pragma once

#include "AForm.hpp"
#include <cstdlib>
#include <ctime>

class RobotomyRequestForm : public AForm
{
    private:
        const str target;

    public:
        RobotomyRequestForm();
        ~RobotomyRequestForm()throw ();
        RobotomyRequestForm(const RobotomyRequestForm & obj);
        RobotomyRequestForm & operator=(const RobotomyRequestForm & obj);
        RobotomyRequestForm(const str &target);
        void execute(const Bureaucrat &executor) const;
};

