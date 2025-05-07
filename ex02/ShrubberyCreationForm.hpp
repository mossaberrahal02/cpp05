#pragma once

#include "AForm.hpp"
#include "Bureaucrat.hpp"

class ShrubberyCreationForm : public AForm
{
    private:
        const str target;

    public:
        ShrubberyCreationForm();
        ~ShrubberyCreationForm() throw();
        ShrubberyCreationForm(const ShrubberyCreationForm & obj);
        ShrubberyCreationForm & operator=(const ShrubberyCreationForm & obj);
        ShrubberyCreationForm(const str &target);
        void execute(const Bureaucrat &executor) const ;
};

